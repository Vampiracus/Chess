#include "Objectively.h"

/*
		Объявление матрицы -- текущая позиция
		   0 - пусто
		   1 - ладья белых,  -1 - ладья чёрных
		   2 - конь белых,   -2 - конь чёрных
		   3 - слон белых,   -3 - слон чёрных
		   4 - ферзь белых,  -4 - ферзь чёрных
		   5 - король белых, -5 - король чёрных
		   6 - пешка белых,  -6 - пешка чёрных
*/

///Returns 1 - white, 0 - nothing, -1 - black
int define_color(int figure_value)
{
	return int(figure_value > 0) - int(figure_value < 0);
}
///Returns 1 if it is white's turn, else returns -1
int define_color(bool whites_turn)
{
	return whites_turn - !whites_turn;
}

//Returns the number of figures of the color attacking the position of {i, j} in theMatrix
int attackedBy(const vector<vector<int>>& theMatrix, int i, int j, int color)
{
	if (color == 0)
		return 0;
	int i1, j1;
	int res = 0;
	//checking 8 directions from right ccw
	{
		{
			i1 = i; j1 = j + 1;
			while (j1 < 8 && theMatrix[i][j1] == 0)
				j1++;
			if (j1 < 8 && (theMatrix[i][j1] == color || theMatrix[i][j1] == color * 4))
				res++;
		}
		{
			i1 = i + 1, j1 = j + 1;
			if (i1 < 8 && j1 < 8)
			{
				if (color < 0 && theMatrix[i1][j1] == color * 6)
					res++;
				while (i1 < 8 && j1 < 8 && theMatrix[i1][j1] == 0)
				{
					i1++;
					j1++;
				}
				if (i1 < 8 && j1 < 8 && (theMatrix[i1][j1] == color * 3 || theMatrix[i1][j1] == color * 4))
					res++;
			}
		}
		{
			i1 = i + 1; j1 = j;
			while (i1 < 8 && theMatrix[i1][j1] == 0)
				i1++;
			if (i1 < 8 && (theMatrix[i1][j1] == color || theMatrix[i1][j1] == color * 4))
				res++;
		}
		{
			i1 = i + 1, j1 = j - 1;
			if (i1 < 8 && j1 >= 0)
			{
				if (color < 0 && theMatrix[i1][j1] == color * 6)
					res++;
				while (i1 < 8 && j1 >= 0 && theMatrix[i1][j1] == 0)
				{
					i1++;
					j1--;
				}
				if (i1 < 8 && j1 >= 0 && (theMatrix[i1][j1] == color * 3 || theMatrix[i1][j1] == color * 4))
					res++;
			}
		}
		{
			i1 = i; j1 = j - 1;
			while (j1 >= 0 && theMatrix[i1][j1] == 0)
				j1--;
			if (j1 >= 0 && (theMatrix[i1][j1] == color || theMatrix[i1][j1] == color * 4))
				res++;
		}
		{
			i1 = i - 1, j1 = j - 1;
			if (i1 >= 0 && j1 >= 0)
			{
				if (color > 0 && theMatrix[i1][j1] == color * 6)
					res++;
				while (i1 >= 0 && j1 >= 0 && theMatrix[i1][j1] == 0)
				{
					i1--;
					j1--;
				}
				if (i1 >= 0 && j1 >= 0 && (theMatrix[i1][j1] == color * 3 || theMatrix[i1][j1] == color * 4))
					res++;
			}
		}
		{
			i1 = i - 1; j1 = j;
			while (i1 >= 0 && theMatrix[i1][j1] == 0)
				i1--;
			if (i1 >= 0 && (theMatrix[i1][j1] == color || theMatrix[i1][j1] == color * 4))
				res++;
		}
		{
			i1 = i - 1, j1 = j + 1;
			if (i1 >= 0 && j1 < 8)
			{
				if (color > 0 && theMatrix[i1][j1] == color * 6)
					res++;
				while (i1 >= 0 && j1 < 8 && theMatrix[i1][j1] == 0)
				{
					i1--;
					j1++;
				}
				if (i1 >= 0 && j1 < 8 && (theMatrix[i1][j1] == color * 3 || theMatrix[i1][j1] == color * 4))
					res++;
			}
		}
	}
	//checking 8 knight positions
	{
		{
			if (i < 7 && j < 6 && theMatrix[i + 1][j + 2] == color * 2)
				res++;
		}
		{
			if (i < 6 && j < 7 && theMatrix[i + 2][j + 1] == color * 2)
				res++;
		}
		{
			if (i < 7 && j >= 2 && theMatrix[i + 1][j - 2] == color * 2)
				res++;
		}
		{
			if (i < 6 && j >= 1 && theMatrix[i + 2][j - 1] == color * 2)
				res++;
		}
		{
			if (i >= 2 && j < 7 && theMatrix[i - 2][j + 1] == color * 2)
				res++;
		}
		{
			if (i >= 1 && j < 6 && theMatrix[i - 1][j + 2] == color * 2)
				res++;
		}
		{
			if (i >= 1 && j >= 2 && theMatrix[i - 1][j - 2] == color * 2)
				res++;
		}
		{
			if (i >= 2 && j >= 1 && theMatrix[i - 2][j - 1] == color * 2)
				res++;
		}
	}
	//checking 8 enemy's king positions
	{
		if (i < 7)
		{
			if (j < 7 && theMatrix[i + 1][j + 1] == color * 5)
				res++;
			if (theMatrix[i + 1][j] == color * 5)
				res++;
			if (j > 0 && theMatrix[i + 1][j - 1] == color * 5)
				res++;
		}
		if (i > 0)
		{
			if (j < 7 && theMatrix[i - 1][j + 1] == color * 5)
				res++;
			if (theMatrix[i - 1][j] == color * 5)
				res++;
			if (j > 0 && theMatrix[i - 1][j - 1] == color * 5)
				res++;
		}
		if (j > 0 && theMatrix[i][j - 1] == color * 5)
			res++;
		if (j < 7 && theMatrix[i][j + 1] == color * 5)
			res++;
	}
	return res;
}

///Finds the king
void find_king(const vector<vector<int>> & theMatrix, int color, int &i, int &j)
{
	for(int k1 = 0; k1 < 8; k1++)
		for(int k2 = 0; k2 < 8; k2++)
			if (theMatrix[k1][k2] == (color * 5))
			{
				i = k1;
				j = k2;
				return;
			}
	i = 100;
}

///Returns 0 if no check, 1 if check from 1 figure, 2 if check from 2 or more figures. Also returns the position of the king in i and j
int check(const vector<vector<int>>& theMatrix, bool whites_turn, int& i, int& j)
{
	int color = define_color(whites_turn);
	find_king(theMatrix, color, i, j);
	if (i == 100)
	{
		i = 0;
		i = 100 / i; // Вызов этого действия означает, что на доске не найден король
	}
	int i1, j1;
	bool found = 0;
	//checking 8 directions from right ccw
	{
		{
			i1 = i; j1 = j + 1;
			while (j1 < 8 && theMatrix[i][j1] == 0)
				j1++;
			if (j1 < 8 && (theMatrix[i][j1] == -color || theMatrix[i][j1] == -color * 4))
				found = 1;
		}
		{
			i1 = i + 1, j1 = j + 1;
			if (i1 < 8 && j1 < 8)
			{
				if (whites_turn && theMatrix[i1][j1] == -color * 6)
					if (found)
						return 2;
					else
						found = 1;
				while (i1 < 8 && j1 < 8 && theMatrix[i1][j1] == 0)
				{
					i1++;
					j1++;
				}
				if (i1 < 8 && j1 < 8 && (theMatrix[i1][j1] == -color * 3 || theMatrix[i1][j1] == -color * 4))
					if (found)
						return 2;
					else
						found = 1;
			}
		}
		{
			i1 = i + 1; j1 = j;
			while (i1 < 8 && theMatrix[i1][j1] == 0)
				i1++;
			if (i1 < 8 && (theMatrix[i1][j1] == -color || theMatrix[i1][j1] == -color * 4))
				if (found)
					return 2;
				else
					found = 1;
		}
		{
			i1 = i + 1, j1 = j - 1;
			if (i1 < 8 && j1 >= 0)
			{
				if (whites_turn && theMatrix[i1][j1] == -color * 6)
					if (found)
						return 2;
					else
						found = 1;
				while (i1 < 8 && j1 >= 0 && theMatrix[i1][j1] == 0)
				{
					i1++;
					j1--;
				}
				if (i1 < 8 && j1 >= 0 && (theMatrix[i1][j1] == -color * 3 || theMatrix[i1][j1] == -color * 4))
					if (found)
						return 2;
					else
						found = 1;
			}
		}
		{
			i1 = i; j1 = j - 1;
			while (j1 >= 0 && theMatrix[i1][j1] == 0)
				j1--;
			if (j1 >= 0 && (theMatrix[i1][j1] == -color || theMatrix[i1][j1] == -color * 4))
				if (found)
					return 2;
				else
					found = 1;
		}
		{
			i1 = i - 1, j1 = j - 1;
			if (i1 >= 0 && j1 >= 0)
			{
				if (!whites_turn && theMatrix[i1][j1] == -color * 6)
					if (found)
						return 2;
					else
						found = 1;
				while (i1 >= 0 && j1 >= 0 && theMatrix[i1][j1] == 0)
				{
					i1--;
					j1--;
				}
				if (i1 >= 0 && j1 >= 0 && (theMatrix[i1][j1] == -color * 3 || theMatrix[i1][j1] == -color * 4))
					if (found)
						return 2;
					else
						found = 1;
			}
		}
		{
			i1 = i - 1; j1 = j;
			while (i1 >= 0 && theMatrix[i1][j1] == 0)
				i1--;
			if (i1 >= 0 && (theMatrix[i1][j1] == -color || theMatrix[i1][j1] == -color * 4))
				if (found)
					return 2;
				else
					found = 1;
		}
		{
			i1 = i - 1, j1 = j + 1;
			if (i1 >= 0 && j1 < 8)
			{
				if (!whites_turn && theMatrix[i1][j1] == -color * 6)
					if (found)
						return 2;
					else
						found = 1;
				while (i1 >= 0 && j1 < 8 && theMatrix[i1][j1] == 0)
				{
					i1--;
					j1++;
				}
				if (i1 >= 0 && j1 < 8 && (theMatrix[i1][j1] == -color * 3 || theMatrix[i1][j1] == -color * 4))
					if (found)
						return 2;
					else
						found = 1;
			}
		}
	}
	//checking 8 knight positions
	{
		{
			if (i < 7 && j < 6 && theMatrix[i + 1][j + 2] == -color * 2)
				if (found)
					return 2;
				else
					found = 1;
		}
		{
			if (i < 6 && j < 7 && theMatrix[i + 2][j + 1] == -color * 2)
				if (found)
					return 2;
				else
					found = 1;
		}
		{
			if (i < 7 && j >= 2 && theMatrix[i + 1][j - 2] == -color * 2)
				if (found)
					return 2;
				else
					found = 1;
		}
		{
			if (i < 6 && j >= 1 && theMatrix[i + 2][j - 1] == -color * 2)
				if (found)
					return 2;
				else
					found = 1;
		}
		{
			if (i >= 2 && j < 7 && theMatrix[i - 2][j + 1] == -color * 2)
				if (found)
					return 2;
				else
					found = 1;
		}
		{
			if (i >= 1 && j < 6 && theMatrix[i - 1][j + 2] == -color * 2)
				if (found)
					return 2;
				else
					found = 1;
		}
		{
			if (i >= 1 && j >= 2 && theMatrix[i - 1][j - 2] == -color * 2)
				if (found)
					return 2;
				else
					found = 1;
		}
		{
			if (i >= 2 && j >= 1 && theMatrix[i - 2][j - 1] == -color * 2)
				if (found)
					return 2;
				else
					found = 1;
		}
	}
	//checking 8 enemy's king positions
	{
		if (i < 7)
		{
			if (j < 7 && theMatrix[i + 1][j + 1] == -color * 5)
				if (found)
					return 2;
				else
					found = 1;
			if (theMatrix[i + 1][j] == -color * 5)
				if (found)
					return 2;
				else
					found = 1;
			if (j > 0 && theMatrix[i + 1][j - 1] == -color * 5)
				if (found)
					return 2;
				else
					found = 1;
		}
		if (i > 0)
		{
			if (j < 7 && theMatrix[i - 1][j + 1] == -color * 5)
				if (found)
					return 2;
				else
					found = 1;
			if (theMatrix[i - 1][j] == -color * 5)
				if (found)
					return 2;
				else
					found = 1;
			if (j > 0 && theMatrix[i - 1][j - 1] == -color * 5)
				if (found)
					return 2;
				else
					found = 1;
		}
		if (j > 0 && theMatrix[i][j - 1] == -color * 5)
			if (found)
				return 2;
			else
				found = 1;
		if (j < 7 && theMatrix[i][j + 1] == -color * 5)
			if (found)
				return 2;
			else
				found = 1;
	}
	return found;
}
///Does the same. King's position is already known
int check_KingPos(const vector<vector<int>> & theMatrix, bool whites_turn, int i, int j)
{
	int color = define_color(whites_turn);
	int i1, j1;
	bool found = 0;
	//checking 8 directions from right ccw
	{
		i1 = i; j1 = j + 1;
		while (j1 < 8 && theMatrix[i][j1] == 0)
			j1++;
		if (j1 < 8 && (theMatrix[i][j1] == -color || theMatrix[i][j1] == -color * 4))
			found = 1;
	}
	{
		i1 = i + 1, j1 = j + 1;
		if (i1 < 8 && j1 < 8)
		{
			if (whites_turn && theMatrix[i1][j1] == -color * 6)
				if (found)
					return 2;
				else
					found = 1;
			while (i1 < 8 && j1 < 8 && theMatrix[i1][j1] == 0)
			{
				i1++;
				j1++;
			}
			if (i1 < 8 && j1 < 8 && (theMatrix[i1][j1] == -color * 3 || theMatrix[i1][j1] == -color * 4))
				if (found)
					return 2;
				else
					found = 1;
		}
	}
	{
		i1 = i + 1; j1 = j;
		while (i1 < 8 && theMatrix[i1][j1] == 0)
			i1++;
		if (i1 < 8 && (theMatrix[i1][j1] == -color || theMatrix[i1][j1] == -color * 4))
			if (found)
				return 2;
			else
				found = 1;
	}
	{
		i1 = i + 1, j1 = j - 1;
		if (i1 < 8 && j1 >= 0)
		{
			if (whites_turn && theMatrix[i1][j1] == -color * 6)
				if (found)
					return 2;
				else
					found = 1;
			while (i1 < 8 && j1 >= 0 && theMatrix[i1][j1] == 0)
			{
				i1++;
				j1--;
			}
			if (i1 < 8 && j1 >= 0 && (theMatrix[i1][j1] == -color * 3 || theMatrix[i1][j1] == -color * 4))
				if (found)
					return 2;
				else
					found = 1;
		}
	}
	{
		i1 = i; j1 = j - 1;
		while (j1 >= 0 && theMatrix[i1][j1] == 0)
			j1--;
		if (j1 >= 0 && (theMatrix[i1][j1] == -color || theMatrix[i1][j1] == -color * 4))
			if (found)
				return 2;
			else
				found = 1;
	}
	{
		i1 = i - 1, j1 = j - 1;
		if (i1 < 8 && j1 < 8)
		{
			if (!whites_turn && theMatrix[i1][j1] == -color * 6)
				if (found)
					return 2;
				else
					found = 1;
			while (i1 >= 0 && j1 >= 0 && theMatrix[i1][j1] == 0)
			{
				i1--;
				j1--;
			}
			if (i1 >= 0 && j1 >= 0 && (theMatrix[i1][j1] == -color * 3 || theMatrix[i1][j1] == -color * 4))
				if (found)
					return 2;
				else
					found = 1;
		}
	}
	{
		i1 = i - 1; j1 = j;
		while (i1 >= 0 && theMatrix[i1][j1] == 0)
			i1--;
		if (i1 >= 0 && (theMatrix[i1][j1] == -color || theMatrix[i1][j1] == -color * 4))
			if (found)
				return 2;
			else
				found = 1;
	}
	{
		i1 = i - 1, j1 = j + 1;
		if (i1 >= 0 && j1 < 8)
		{
			if (!whites_turn && theMatrix[i1][j1] == -color * 6)
				if (found)
					return 2;
				else
					found = 1;
			while (i1 >= 0 && j1 < 8 && theMatrix[i1][j1] == 0)
			{
				i1--;
				j1++;
			}
			if (i1 >= 0 && j1 < 8 && (theMatrix[i1][j1] == -color * 3 || theMatrix[i1][j1] == -color * 4))
				if (found)
					return 2;
				else
					found = 1;
		}
	}
	//checking 8 knight positions
	{
		if (i < 7 && j < 6 && theMatrix[i + 1][j + 2] == -color * 2)
			if (found)
				return 2;
			else
				found = 1;
	}
	{
		if (i < 6 && j < 7 && theMatrix[i + 2][j + 1] == -color * 2)
			if (found)
				return 2;
			else
				found = 1;
	}
	{
		if (i < 7 && j >= 2 && theMatrix[i + 1][j - 2] == -color * 2)
			if (found)
				return 2;
			else
				found = 1;
	}
	{
		if (i < 6 && j >= 1 && theMatrix[i + 2][j - 1] == -color * 2)
			if (found)
				return 2;
			else
				found = 1;
	}
	{
		if (i >= 2 && j < 7 && theMatrix[i - 2][j + 1] == -color * 2)
			if (found)
				return 2;
			else
				found = 1;
	}
	{
		if (i >= 1 && j < 6 && theMatrix[i - 1][j + 2] == -color * 2)
			if (found)
				return 2;
			else
				found = 1;
	}
	{
		if (i >= 1 && j >= 2 && theMatrix[i - 1][j - 2] == -color * 2)
			if (found)
				return 2;
			else
				found = 1;
	}
	{
		if (i >= 2 && j >= 1 && theMatrix[i - 2][j - 1] == -color * 2)
			if (found)
				return 2;
			else
				found = 1;
	}
	//checking 8 enemy's king positions (because when the king is moved, it may appear in reach of the other king)
	{
		if (i < 7)
		{
			if (j < 7 && theMatrix[i + 1][j + 1] == -color * 5)
				if (found)
					return 2;
				else
					found = 1;
			if (theMatrix[i + 1][j] == -color * 5)
				if (found)
					return 2;
				else
					found = 1;
			if (j > 0 && theMatrix[i + 1][j - 1] == -color * 5)
				if (found)
					return 2;
				else
					found = 1;
		}
		if (i > 0)
		{
			if (j < 7 && theMatrix[i - 1][j + 1] == -color * 5)
				if (found)
					return 2;
				else
					found = 1;
			if (theMatrix[i - 1][j] == -color * 5)
				if (found)
					return 2;
				else
					found = 1;
			if (j > 0 && theMatrix[i - 1][j - 1] == -color * 5)
				if (found)
					return 2;
				else
					found = 1;
		}
		if (j > 0 && theMatrix[i][j - 1] == -color * 5)
			if (found)
				return 2;
			else
				found = 1;
		if (j < 7 && theMatrix[i][j + 1] == -color * 5)
			if (found)
				return 2;
			else
				found = 1;
	}
	return found;
}

///Returns vector of possible moves (where the figure could be moved) for a definite figure (not paying attention to checks). Format: {i, j}
vector<vector<int>> possible_figure_moves(const vector<vector<int>> & theMatrix, int i, int j)
{
	vector<vector<int>> res(0);
	int absolute = (theMatrix[i][j] < 0) ? -theMatrix[i][j] : theMatrix[i][j];
	if (absolute == 0)
		return {};
	if (absolute == 1)
	{
		int color = int(theMatrix[i][j] > 0) - int(theMatrix[i][j] < 0), i1, j1;
		{
			i1 = i; j1 = j + 1;
			while (j1 < 8 && theMatrix[i1][j1] == 0)
			{
				res.push_back({ i1, j1 });
				j1++;
			}
			if (j1 < 8 && int(theMatrix[i1][j1] > 0) - int(theMatrix[i1][j1] < 0) == -color)
				res.push_back({ i1, j1 });
		} // right
		{
			i1 = i; j1 = j - 1;
			while (j1 >= 0 && theMatrix[i1][j1] == 0)
			{
				res.push_back({ i1, j1 });
				j1--;
			}
			if (j1 >= 0 && int(theMatrix[i1][j1] > 0) - int(theMatrix[i1][j1] < 0) == -color)
				res.push_back({ i1, j1 });
		} // left
		{
			i1 = i + 1; j1 = j;
			while (i1 < 8 && theMatrix[i1][j1] == 0)
			{
				res.push_back({ i1, j1 });
				i1++;
			}
			if (i1 < 8 && int(theMatrix[i1][j1] > 0) - int(theMatrix[i1][j1] < 0) == -color)
				res.push_back({ i1, j1 });
		} // up
		{
			i1 = i - 1; j1 = j;
			while (i1 >= 0 && theMatrix[i1][j1] == 0)
			{
				res.push_back({ i1, j1 });
				i1--;
			}
			if (i1 >= 0 && int(theMatrix[i1][j1] > 0) - int(theMatrix[i1][j1] < 0) == -color)
				res.push_back({ i1, j1 });
		} // down
	}
	else if (absolute == 2)
	{
		int theothercolor; // the color of the other figure (0 if no figure)
		int color = define_color(theMatrix[i][j]);
		{
			if (i < 7 && j < 6 && ((theothercolor = define_color(theMatrix[i + 1][j + 2])) == -color || theothercolor == 0))
				res.push_back({ i + 1, j + 2 });
		}
		{
			if (i < 6 && j < 7 && ((theothercolor = define_color(theMatrix[i + 2][j + 1])) == -color || theothercolor == 0))
				res.push_back({ i + 2, j + 1 });
		}
		{
			if (i < 7 && j >= 2 && ((theothercolor = define_color(theMatrix[i + 1][j - 2])) == -color || theothercolor == 0))
				res.push_back({ i + 1, j - 2 });
		}
		{
			if (i < 6 && j >= 1 && ((theothercolor = define_color(theMatrix[i + 2][j - 1])) == -color || theothercolor == 0))
				res.push_back({ i + 2, j - 1 });
		}
		{
			if (i >= 2 && j < 7 && ((theothercolor = define_color(theMatrix[i - 2][j + 1])) == -color || theothercolor == 0))
				res.push_back({ i - 2, j + 1 });
		}
		{
			if (i >= 1 && j < 6 && ((theothercolor = define_color(theMatrix[i - 1][j + 2])) == -color || theothercolor == 0))
				res.push_back({ i - 1, j + 2 });
		}
		{
			if (i >= 1 && j >= 2 && ((theothercolor = define_color(theMatrix[i - 1][j - 2])) == -color || theothercolor == 0))
				res.push_back({ i - 1, j - 2 });
		}
		{
			if (i >= 2 && j >= 1 && ((theothercolor = define_color(theMatrix[i - 2][j - 1])) == -color || theothercolor == 0))
				res.push_back({ i - 2, j - 1 });
		}
	}
	else if (absolute == 3)
	{
		int color = define_color(theMatrix[i][j]), i1, j1;
		{
			i1 = i + 1; j1 = j + 1;
			while (i1 < 8 && j1 < 8 && theMatrix[i1][j1] == 0)
			{
				res.push_back({ i1, j1 });
				i1++;
				j1++;
			}
			if (i1 < 8 && j1 < 8 && define_color(theMatrix[i1][j1]) == -color)
				res.push_back({ i1, j1 });
		}
		{
			i1 = i + 1; j1 = j - 1;
			while (i1 < 8 && j1 >= 0 && theMatrix[i1][j1] == 0)
			{
				res.push_back({ i1, j1 });
				i1++;
				j1--;
			}
			if (i1 < 8 && j1 >= 0 && define_color(theMatrix[i1][j1]) == -color)
				res.push_back({ i1, j1 });
		}
		{
			i1 = i - 1; j1 = j + 1;
			while (j1 < 8 && i1 >= 0 && theMatrix[i1][j1] == 0)
			{
				res.push_back({ i1, j1 });
				j1++;
				i1--;
			}
			if (j1 < 8 && i1 >= 0 && define_color(theMatrix[i1][j1]) == -color)
				res.push_back({ i1, j1 });
		}
		{
			i1 = i - 1; j1 = j - 1;
			while (i1 >= 0 && j1 >= 0 && theMatrix[i1][j1] == 0)
			{
				res.push_back({ i1, j1 });
				i1--;
				j1--;
			}
			if (i1 >= 0 && j1 >= 0 && define_color(theMatrix[i1][j1]) == -color)
				res.push_back({ i1, j1 });
		}
	}
	else if (absolute == 4)
	{
		{
			//like rook
			int color = define_color(theMatrix[i][j]), i1, j1;
			{
				i1 = i; j1 = j + 1;
				while (j1 < 8 && theMatrix[i1][j1] == 0)
				{
					res.push_back({ i1, j1 });
					j1++;
				}
				if (j1 < 8 && int(theMatrix[i1][j1] > 0) - int(theMatrix[i1][j1] < 0) == -color)
					res.push_back({ i1, j1 });
			} // right
			{
				i1 = i; j1 = j - 1;
				while (j1 >= 0 && theMatrix[i1][j1] == 0)
				{
					res.push_back({ i1, j1 });
					j1--;
				}
				if (j1 >= 0 && int(theMatrix[i1][j1] > 0) - int(theMatrix[i1][j1] < 0) == -color)
					res.push_back({ i1, j1 });
			} // left
			{
				i1 = i + 1; j1 = j;
				while (i1 < 8 && theMatrix[i1][j1] == 0)
				{
					res.push_back({ i1, j1 });
					i1++;
				}
				if (i1 < 8 && int(theMatrix[i1][j1] > 0) - int(theMatrix[i1][j1] < 0) == -color)
					res.push_back({ i1, j1 });
			} // up
			{
				i1 = i - 1; j1 = j;
				while (i1 >= 0 && theMatrix[i1][j1] == 0)
				{
					res.push_back({ i1, j1 });
					i1--;
				}
				if (i1 >= 0 && int(theMatrix[i1][j1] > 0) - int(theMatrix[i1][j1] < 0) == -color)
					res.push_back({ i1, j1 });
			} // down
		}
		{
			//like bishop
			int color = define_color(theMatrix[i][j]), i1, j1;
			{
				i1 = i + 1; j1 = j + 1;
				while (i1 < 8 && j1 < 8 && theMatrix[i1][j1] == 0)
				{
					res.push_back({ i1, j1 });
					i1++;
					j1++;
				}
				if (i1 < 8 && j1 < 8 && define_color(theMatrix[i1][j1]) == -color)
					res.push_back({ i1, j1 });
			}
			{
				i1 = i + 1; j1 = j - 1;
				while (i1 < 8 && j1 >= 0 && theMatrix[i1][j1] == 0)
				{
					res.push_back({ i1, j1 });
					i1++;
					j1--;
				}
				if (i1 < 8 && j1 >= 0 && define_color(theMatrix[i1][j1]) == -color)
					res.push_back({ i1, j1 });
			}
			{
				i1 = i - 1; j1 = j + 1;
				while (j1 < 8 && i1 >= 0 && theMatrix[i1][j1] == 0)
				{
					res.push_back({ i1, j1 });
					j1++;
					i1--;
				}
				if (j1 < 8 && i1 >= 0 && define_color(theMatrix[i1][j1]) == -color)
					res.push_back({ i1, j1 });
			}
			{
				i1 = i - 1; j1 = j - 1;
				while (i1 >= 0 && j1 >= 0 && theMatrix[i1][j1] == 0)
				{
					res.push_back({ i1, j1 });
					i1--;
					j1--;
				}
				if (i1 >= 0 && j1 >= 0 && define_color(theMatrix[i1][j1]) == -color)
					res.push_back({ i1, j1 });
			}
		}
	}
	else if (absolute == 5)
	{
		int color = define_color(theMatrix[i][j]);

		if (i < 7)
		{
			if (j < 7 && (theMatrix[i + 1][j + 1] == 0 || define_color(theMatrix[i + 1][j + 1]) == -color))
				res.push_back({ i + 1, j + 1 });
			if (theMatrix[i + 1][j] == 0 || define_color(theMatrix[i + 1][j]) == -color)
				res.push_back({ i + 1, j });
			if (j > 0 && (theMatrix[i + 1][j - 1] == 0 || define_color(theMatrix[i + 1][j - 1]) == -color))
				res.push_back({ i + 1, j - 1 });
		}
		if (i > 0)
		{
			if (j < 7 && (theMatrix[i - 1][j + 1] == 0 || define_color(theMatrix[i - 1][j + 1]) == -color))
				res.push_back({ i - 1, j + 1 });
			if (theMatrix[i - 1][j] == 0 || define_color(theMatrix[i - 1][j]) == -color)
				res.push_back({ i - 1, j });
			if (j > 0 && (theMatrix[i - 1][j - 1] == 0 || define_color(theMatrix[i - 1][j - 1]) == -color))
				res.push_back({ i - 1, j - 1 });
		}
		if (j > 0 && (theMatrix[i][j - 1] == 0 || define_color(theMatrix[i][j - 1]) == -color))
			res.push_back({ i, j - 1 });
		if (j < 7 && (theMatrix[i][j + 1] == 0 || define_color(theMatrix[i][j + 1]) == -color))
			res.push_back({ i, j + 1 });
		//Castling
		if (j == 3)
		{
			if (i == 0 && !check_KingPos(theMatrix, 1, 0, j))
			{
				if (theMatrix[8][0] == 1 && theMatrix[0][1] == 0 && theMatrix[0][2] == 0 && !check_KingPos(theMatrix, 1, 0, j - 1))
				{
					res.push_back({i, j - 2});
				}
				if (theMatrix[8][1] == 1 && theMatrix[0][4] == 0 && theMatrix[0][5] == 0 && theMatrix[0][6] == 0 && !check_KingPos(theMatrix, 1, 0, j + 1))
				{
					res.push_back({i, j + 2 });
				}
			}
			if (i == 7 && !check_KingPos(theMatrix, 0, 7, j))
			{
				if (theMatrix[8][2] == 1 && theMatrix[7][1] == 0 && theMatrix[7][2] == 0 && !check_KingPos(theMatrix, 0, i, j - 1))
				{
					res.push_back({i, j - 2 });
				}
				if (theMatrix[8][3] == 1 && theMatrix[7][4] == 0 && theMatrix[7][5] == 0 && theMatrix[7][6] == 0 && !check_KingPos(theMatrix, 0, i, j + 1))
				{
					res.push_back({i, j + 2 });
				}
			}
		}
	}
	else
	{
		int color = define_color(theMatrix[i][j]);
		if (color == 1 && i != 7)
		{
			if (theMatrix[i + 1][j] == 0)
				res.push_back({ i + 1, j });
			if (j > 0 && (theMatrix[i + 1][j - 1] < 0 || (theMatrix[8].size() == 6 && theMatrix[8][4] == i + 1 && theMatrix[8][5] == j - 1)))
				res.push_back({ i + 1, j - 1 });
			if (j < 7 && (theMatrix[i + 1][j + 1] < 0 || (theMatrix[8].size() == 6 && theMatrix[8][4] == i + 1 && theMatrix[8][5] == j + 1)))
				res.push_back({ i + 1, j + 1 });
			if (i == 1 && theMatrix[i + 2][j] == 0 && theMatrix[i + 1][j] == 0)
				res.push_back({ i + 2, j });
		}
		else if (color == -1 && i != 0)
		{
			if (theMatrix[i - 1][j] == 0)
				res.push_back({ i - 1, j });
			if (j > 0 && (theMatrix[i - 1][j - 1] > 0 || (theMatrix[8].size() == 6 && theMatrix[8][4] == i - 1 && theMatrix[8][5] == j - 1)))
				res.push_back({ i - 1, j - 1 });
			if (j < 7 && (theMatrix[i - 1][j + 1] > 0 || (theMatrix[8].size() == 6 && theMatrix[8][4] == i - 1 && theMatrix[8][5] == j + 1)))
				res.push_back({ i - 1, j + 1 });
			if (i == 6 && theMatrix[i - 2][j] == 0 && theMatrix[i - 1][j] == 0)
				res.push_back({ i - 2, j });
		}
	}
	return res;
}

///returns Matrix when a move is made. The move may be incorrect
vector<vector<int>> make_move(vector<vector<int>> theMatrix, int i1, int j1, int i2, int j2)
{
	theMatrix[i2][j2] = theMatrix[i1][j1];
	theMatrix[i1][j1] = 0;
	if (i2 == 0 && theMatrix[i2][j2] == -6)
		theMatrix[i2][j2] = -4;
	if (i2 == 7 && theMatrix[i2][j2] == 6)
		theMatrix[i2][j2] = 4;
	return theMatrix;
}

///Returns every single possible move, considering checks. Format: {i1, j1, i2, j2}
vector<vector<int>> all_possible_moves(const vector<vector<int>> & theMatrix, bool whites_turn)
{
	int color = define_color(whites_turn);
	vector<vector<int>> res(0);
	for(int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int polcolor = define_color(theMatrix[i][j]);
			if (color == polcolor)
			{
				int r1, r2;
				vector<vector<int>> pfm = possible_figure_moves(theMatrix, i, j);
				for (int k = 0; k < pfm.size(); k++)
					if (!check(make_move(theMatrix, i, j, pfm[k][0], pfm[k][1]), whites_turn, r1, r2))
						pfm[k].insert(pfm[k].begin(), { i, j });
					else
					{
						pfm.erase(pfm.begin() + k);
						k--;
					}
				res.insert(res.end(), pfm.begin(), pfm.end());
			}
		}
	}
	return res;
}

///Returns true if the player cannot move
bool no_possible_moves(const vector<vector<int>>& theMatrix, bool whites_turn)
{
	int color = define_color(whites_turn);
	for (int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
			if (define_color(theMatrix[i][j]) == color)
			{
				vector<vector<int>> pfm = possible_figure_moves(theMatrix, i, j);
				if (pfm.size() != 0)
				{
					for (int k = 0; k < pfm.size(); k++)
					{
						//if no check making this move return 0
						int a, b;
						if (!check(make_move(theMatrix, i, j, pfm[k][0], pfm[k][1]), whites_turn, a, b))
							return 0;
					}
				}
			}
	}
	return 1;
}

///Takes position and who's turn it is. Returns 0 if nothing, 1 if check, 2 if mate (to the player, who makes the turn), 3 if draw
int check_mate(const vector<vector<int>> & theMatrix, bool whites_turn)
{
	int i, j; // the position of the king
	int check_result = check(theMatrix, whites_turn, i, j);
	if (!check_result)
	{
		if (!no_possible_moves(theMatrix, whites_turn))
			return 0;
		return 3;
	}
	if (check_result == 2)
	{
		vector<vector<int>> possible_king_moves = possible_figure_moves(theMatrix, i, j);
		for (int move = 0; move < possible_king_moves.size(); move++)
		{
			if (!check_KingPos(make_move(theMatrix, i, j, possible_king_moves[move][0], possible_king_moves[move][1]), whites_turn, possible_king_moves[move][0], possible_king_moves[move][1]))
				return 1;
		}
		return 2;
	}
	vector<vector<int>> possible_moves = all_possible_moves(theMatrix, whites_turn);
	for (int move = 0; move < possible_moves.size(); move++)
	{
		if (!check(make_move(theMatrix, possible_moves[move][0], possible_moves[move][1], possible_moves[move][2], possible_moves[move][3]), whites_turn, i, j))
			return 1;
	}
	return 2;
}

//Returns if the move is possible
bool possible_move(const vector<vector<int>> & theMatrix, bool whites_turn, int i1, int j1, int i2, int j2)
{
	vector<vector<int>> all_moves_available = all_possible_moves(theMatrix, whites_turn);
	int a1, a2, sz = all_moves_available.size();
	for (int i = 0; i < sz; i++)
	{
		//if our figure may move there, and it will create no check to our king
		if (i1 == all_moves_available[i][0] && j1 == all_moves_available[i][1] && i2 == all_moves_available[i][2] && j2 == all_moves_available[i][3] &&
			!check(make_move(theMatrix, all_moves_available[i][0], all_moves_available[i][1], all_moves_available[i][2], all_moves_available[i][3]), whites_turn, a1, a2))
			return 1;
	}
	return 0;
}

//Optimizes all_possible_moves so that not all moves are to be considered when choosing best ones
vector<vector<int>> possible_moves_optimized(const vector<vector<int>>& theMatrix, bool whites_turn)
{
	vector<vector<int>> res = all_possible_moves(theMatrix, whites_turn);
	int i = 0;
	double curAdv = Evaluate(theMatrix, whites_turn);
	while (i != res.size())
	{
		double difference = (Evaluate(make_move(theMatrix, res[i][0], res[i][1], res[i][2], res[i][3]), !whites_turn) - curAdv) * define_color(whites_turn);
		if (difference < 0.0001)
		{
			res.erase(res.begin() + i);
			i--;
		}
		i++;
	}
	if (res.size() == 0) 
		return all_possible_moves(theMatrix, whites_turn);
	return res;
}