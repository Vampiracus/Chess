#pragma once
#include<iostream>
#include<vector>
#include"Objectively.h"

using namespace std;

//Counts material advantage, where pawn costs 1, knigt and bishop 3, rook 5, queen 9
double MatAdv(const vector<vector<int>> &theMatrix);

//Counts advantage by pawn structure
double PawnAdv(const vector<vector<int>>& theMatrix, bool whites_turn);

//Counts advantage by activity of figures
double ActivyAdv(const vector <vector <int > >& a);

//Count disadvantage by king's defence
double  KingDefenceAdv(const vector <vector <int> >& a);

//Summs the advantage
double Evaluate(const vector<vector<int>>& theMatrix, bool whites_turn);