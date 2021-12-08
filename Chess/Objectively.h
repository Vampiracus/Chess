#pragma once
#include<iostream>
#include<vector>
#include"Evaluate.h"

using namespace std;

///returns Matrix when a move is made. The move may be incorrect
vector<vector<int>> make_move(vector<vector<int>> theMatrix, int i1, int j1, int i2, int j2);
///Returns 1 if it is white's turn, else returns -1
int define_color(bool whites_turn);
///Returns 1 - white, 0 - nothing, -1 - black
int define_color(int figure_value);
//Returns the number of figures of the color attacking the position of {i, j} in theMatrix
int attackedBy(const vector<vector<int>>& theMatrix, int i, int j, int color);
///Finds the king. Color should be 1 if the white king is being looked for and -1 otherwise
void find_king(const vector<vector<int>>& theMatrix, int color, int& i, int& j);
///Takes position and who's turn it is. Returns 0 if nothing, 1 if check, 2 if mate (to the player, who makes the turn), 3 if draw
int check_mate(const vector<vector<int>>& theMatrix, bool whites_turn);
///ЅерЄт чей ход, начальную точку и конечную, и возвращает, можно ли сходить из начальной точки в конечную
bool possible_move(const vector<vector<int>>& theMatrix, bool whites_turn, int i1, int j1, int i2, int j2);
///Returns every single possible move
vector<vector<int>> all_possible_moves(const vector<vector<int>>& theMatrix, bool whites_turn);
///Optimizez previous function and drops stupid moves
vector<vector<int>> possible_moves_optimized(const vector<vector<int>> & theMatrix, bool whites_turn);