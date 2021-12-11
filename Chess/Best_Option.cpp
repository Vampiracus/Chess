#include "Best_Option.h"

//Returns best deal for us if the enemy moves optimally
double ifMoveLikeThis(vector<vector<int>> theMatrix, bool whites_turn, int depthToThink)
{
	if (depthToThink == 0)
		return Evaluate(theMatrix, whites_turn);
	vector<vector<int>> moves = possible_moves_optimized(theMatrix, whites_turn);
	if (moves.size() == 0)
	{
		if (check_mate(theMatrix, whites_turn) == 2)
			return define_color(whites_turn) * -200;
		return 0;
	}
	double ma = Evaluate(make_move(theMatrix, moves[0][0], moves[0][1], moves[0][2], moves[0][3]), !whites_turn);
	int color = define_color(whites_turn);
	for (int i = 1; i < moves.size(); i++)
	{
		double cur = ifMoveLikeThis(make_move(theMatrix, moves[1][0], moves[1][1], moves[1][2], moves[1][3]), !whites_turn, depthToThink - 1);
		if ((cur - ma) * color > 0)
		{
			ma = cur;
			moves.erase(moves.begin());
		}
		else
			moves.erase(moves.begin() + 1);
		if (ma == 200 || ma == -200)
			return ma;
	}
	return ma;
}

//Returns {i1, j1, i2, j2} of one of three best moves
vector<int> bestMove(const vector<vector<int>> & theMatrix, bool whites_turn)
{
	//Temporarily returns random move
	vector<vector<int>> moves = possible_moves_optimized(theMatrix, whites_turn);

	const int depth = 4;

	vector<double> maxes(3, -1000);
	vector<int> iMaxes(3, 0);
	for (int i = 0; i < moves.size(); i++)
	{
		double cur = ifMoveLikeThis(make_move(theMatrix, moves[i][0], moves[i][1], moves[i][2], moves[i][3]), !whites_turn, depth - 1);
		if (maxes[0] == -1000 || (cur - maxes[0]) * define_color(whites_turn) > 0)
		{
			maxes[2] = maxes[1];
			iMaxes[2] = iMaxes[1];
			maxes[1] = maxes[0];
			iMaxes[1] = iMaxes[0];
			maxes[0] = cur;
			iMaxes[0] = i;
		}
		else if (maxes[1] == -1000 || (cur - maxes[1]) * define_color(whites_turn) > 0)
		{
			maxes[2] = maxes[1];
			iMaxes[2] = iMaxes[1];
			maxes[1] = cur;
			iMaxes[1] = i;
		}
		else if (maxes[2] == -1000 || (cur - maxes[2]) * define_color(whites_turn) > 0)
		{
			maxes[2] = cur;
			iMaxes[2] = i;
		}
	}


	return moves[iMaxes[0]];


	if (maxes[1] == -1000)
		return moves[iMaxes[0]];
	if (maxes[2] == -1000)
		return moves[(rand() % 11 + abs(maxes[0] - maxes[1])) < 6];
	double seed = rand() % 18;
	seed += abs(maxes[1] - maxes[2]);
	seed += abs(maxes[0] - maxes[1]);
	seed /= (rand() % 2 + 1);
	if (seed < 6)
		return moves[iMaxes[2]];
	if (seed < 12)
		return moves[iMaxes[1]];
	return moves[iMaxes[0]];
}
