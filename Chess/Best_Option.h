#pragma once
#include "Objectively.h"
#include <iostream>
#include <vector>

//Returns {i1, j1, i2, j2} of one of three best moves
vector<int> bestMove(const vector<vector<int>>& theMatrix, bool whites_turn);