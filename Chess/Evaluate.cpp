#include "Evaluate.h"
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

			//Последний ряд отвечает за спец.условия. [8][0], [8][1] -- за право на соответственно короткую и длинную рокировку для белых
			//[8][2], [8][3] -- за право на соответственно короткую и длинную рокировку для чёрных
			//Также опционально могут быть [8][4] и [8][5] -- координаты поля для взятия на проходе


//Returns if the figure is attacked by less or the same number of figures than it is defended by
bool defended(const vector<vector<int>>& theMatrix, int i, int j)
{
	int color = define_color(theMatrix[i][j]),
		WhAttackers = attackedBy(theMatrix, i, j, 1),
		BlAttackers = attackedBy(theMatrix, i, j, -1);
	if ((WhAttackers - BlAttackers) * color >= 0)
		return 1;
	return 0;
}
//Imagining that a figure of the color is placed there. Returns if the square is attacked by less figures than it is defended by or the enemy does not attack it. 
bool defended(const vector<vector<int>>& theMatrix, int i, int j, int color)
{
	int WhAttackers = attackedBy(theMatrix, i, j, 1),
		BlAttackers = attackedBy(theMatrix, i, j, -1);
	if (BlAttackers == 0 || (WhAttackers - BlAttackers) * color > 0)
		return 1;
	return 0;
}

//pawn costs 1, knigtand bishop 3, rook 5, queen 9
int figure_cost(const int &a, const int &i)
{
	int absolute = (a > 0) ? a : -a;
	switch (absolute)
	{
	case (0):
	{
		return 0;
	}
	case (6):
	{
		if (i == 7 || i == 0)
			return ((a > 0) ? 9 : -9);
		return ((a > 0) ? 1 : -1);
	}
	case(1):
	{
		return ((a > 0) ? 5 : -5);
	}
	case(2):
	{
		return ((a > 0) ? 3 : -3);
	}
	case(3):
	{
		return ((a > 0) ? 3 : -3);
	}
	case(4):
	{
		return ((a > 0) ? 9 : -9);
	}
	}
	return 0;
}

//Counts material advantage, where pawn costs 1, knigt and bishop 3, rook 5, queen 9
double MatAdv(const vector<vector<int>>& theMatrix)
{
	double res = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			res += figure_cost(theMatrix[i][j], i);
		}
	}
	return res;
}




//Our pawn not defended by another pawn -- +0.1 to the enemy (completely undefended -- +0.3)
double pawnsDefended(const vector<vector<int>>& theMatrix)
{
	double res = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (theMatrix[i][j] == 6 || theMatrix[i][j] == -6)
			{
				int color = define_color(theMatrix[i][j]);
				if (color == 1)
				{
					if (j > 0 && theMatrix[i - 1][j - 1] == 6)
						continue;
					if (j < 7 && theMatrix[i - 1][j + 1] == 6)
						continue;
					res -= 0.1;
					if (!defended(theMatrix, i, j))
						res -= 0.2;
				}
				else
				{
					if (j > 0 && theMatrix[i + 1][j - 1] == -6)
						continue;
					if (j < 7 && theMatrix[i + 1][j + 1] == -6)
						continue;
					res += 0.1;
					if (!defended(theMatrix, i, j))
						res += 0.2;
				}
			}
		}
	}
	return res;
}

//If 2+ pawns on a line -- +0.3 to the enemy for each line
double pawnsOnALine(const vector<vector<int>>& theMatrix)
{
	double res = 0;
	for (int j = 0; j < 8; j++)
	{
		int countBl = 0, countWh = 0;
		for (int i = 1; i < 7; i++)
			if (theMatrix[i][j] == 6)
				countWh++;
			else if (theMatrix[i][j] == -6)
				countBl++;
		if (countWh > 1)
			res -= 0.3;
		if (countBl > 1)
			res += 0.3;
	}
	return res;
}

//We have a pawn which passed the middle of the desk -- +0.2
//If it advanced by 1 square -- +0.1 (+0.3 if defended)
//If it advanced by 2 squares -- +0.2 (+0.8 if defended)
//If it advanced by 3 squares -- +1.0 (+2 if defended; if it's our turn -- +1 more; 
//if no check to us, and the square in front of the pawn is defended by us -- +5 more)
double advancedPawns(const vector<vector<int>>& theMatrix, bool whites_turn)
{
	double res = 0;
	int i = 1;
	for (int j = 0; j < 8; j++)
	{
		if (theMatrix[i][j] == -6)
		{
			res -= 1.2;
			if (defended(theMatrix, i, j))
				res -= 1.0;
			if (!whites_turn)
			{
				res -= 1.0;
				if (!check_mate(theMatrix, whites_turn) && defended(theMatrix, 0, j, -1))
					res -= 5.0;
			}
		}
	}
	i = 2;
	for (int j = 0; j < 8; j++)
	{
		if (theMatrix[i][j] == -6)
		{
			res -= 0.4;
			if (defended(theMatrix, i, j))
				res -= 0.6;
		}
	}
	i = 3;
	for (int j = 0; j < 8; j++)
	{
		if (theMatrix[i][j] == -6)
		{
			res -= 0.3;
			if (defended(theMatrix, i, j))
				res -= 0.2;
		}
	}
	i = 4;
	for (int j = 0; j < 8; j++)
	{
		if (theMatrix[i][j] == 6)
		{
			res += 0.3;
			if (defended(theMatrix, i, j))
				res += 0.2;
		}
	}
	i = 5;
	for (int j = 0; j < 8; j++)
	{
		if (theMatrix[i][j] == 6)
		{
			res += 0.4;
			if (defended(theMatrix, i, j))
				res += 0.6;
		}
	}
	i = 6;
	for (int j = 0; j < 8; j++)
	{
		if (theMatrix[i][j] == 6)
		{
			res += 1.2;
			if (defended(theMatrix, i, j))
				res += 1.0;
			if (whites_turn)
			{
				res += 1.0;
				if (!check_mate(theMatrix, whites_turn) && defended(theMatrix, 7, j, 1))
					res += 5.0;
			}
		}
	}
	return res;
}

//If our pawn attacks one of 4 central squares -- +attack_center_value for each pawn
double pawnsAttackCenter(const vector<vector<int>>& theMatrix)
{
	const double attack_center_value = 0.3,
			  attack_subcenter_value = 0.15;
	double res = 0;
	//center
	{
		if (theMatrix[2][2] == 6)
			res += attack_center_value;
		if (theMatrix[3][2] == 6)
			res += attack_center_value;
		if (theMatrix[2][3] == 6)
			res += attack_center_value;
		if (theMatrix[3][3] == 6)
			res += attack_center_value;
		if (theMatrix[2][4] == 6)
			res += attack_center_value;
		if (theMatrix[3][4] == 6)
			res += attack_center_value;
		if (theMatrix[2][5] == 6)
			res += attack_center_value;
		if (theMatrix[3][5] == 6)
			res += attack_center_value;

		if (theMatrix[5][2] == -6)
			res -= attack_center_value;
		if (theMatrix[4][2] == -6)
			res -= attack_center_value;
		if (theMatrix[5][3] == -6)
			res -= attack_center_value;
		if (theMatrix[4][3] == -6)
			res -= attack_center_value;
		if (theMatrix[5][4] == -6)
			res -= attack_center_value;
		if (theMatrix[4][4] == -6)
			res -= attack_center_value;
		if (theMatrix[5][5] == -6)
			res -= attack_center_value;
		if (theMatrix[4][5] == -6)
			res -= attack_center_value;
	}
	return res;
}

//Counts advantage by pawn structure
double PawnAdv(const vector<vector<int>>& theMatrix, bool whites_turn)
{
	double res = 0;
	res += pawnsDefended(theMatrix);
	res += pawnsOnALine(theMatrix);
	res += advancedPawns(theMatrix, whites_turn);
	res += pawnsAttackCenter(theMatrix);
	return res;
}




//определяет для атакованной клетки преймущество. l - индекс строки. r - столбца
long double activefornow(int l, int r) {//определяет для атакованной клетки преймущество. l - индекс строки. r - столбца
	if ((l <= 7) && (l >= 0) && (r <= 7) && (r >= 0)) {
		if ((l == 0) || (l == 7) || (l == 7) || (r == 0)) { return 0.10; }
		else if ((((r == 6) || (r == 1)) && ((l < 7) && (l > 0))) || (((l == 6) || (l == 1)) && ((r < 7) && (r > 0)))) { return 0.12; }
		else if ((((r == 5) || (r == 2)) && ((l < 6) && (l > 1))) || (((l == 5) || (l == 2)) && ((r < 6) && (r > 1)))) { return 0.15; }
		else if ((((r == 4) || (r == 3)) && ((l < 5) && (l > 2))) || (((l == 3) || (l == 4)) && ((r < 5) && (r > 2)))) { return 0.18; }
	}
	return 0;
}

//Adventure by the pieces activity
double ActivyAdv(const vector<vector<int>>& a) {
	int i, g;
	long double sum = 0;
	int u, v;
	for (i = 0; i < 8; i++) {
		for (g = 0; g < 8; g++) {
			if (a[i][g] == 6) { //для пешки
				sum = sum + activefornow(i + 1, g - 1);
				sum = sum + activefornow(i + 1, g + 1);
			}
			else if (a[i][g] == 5) {   //короля
				sum = sum + activefornow(i + 1, g - 1);
				sum = sum + activefornow(i + 1, g + 1);
				sum = sum + activefornow(i + 1, g);
				sum = sum + activefornow(i, g + 1);
				sum = sum + activefornow(i, g - 1);
				sum = sum + activefornow(i - 1, g - 1);
				sum = sum + activefornow(i - 1, g);
				sum = sum + activefornow(i - 1, g + 1);
			}
			else if (a[i][g] == 4) {  //ферзя
				for (u = 1; u < 9; u++) {
					sum = sum + activefornow(i + u, g);
					sum = sum + activefornow(i - u, g);
					sum = sum + activefornow(i, g + u);
					sum = sum + activefornow(i, g - u);
				}
				for (u = 1; u < 9; u++) {
					sum = sum + activefornow(i + u, g + u);
					sum = sum + activefornow(i - u, g + u);
					sum = sum + activefornow(i + u, g - u);
					sum = sum + activefornow(i - u, g - u);
				}
			}
			else if (a[i][g] == 3) {    //слон
				for (v = 1; v < 9; v++) {
					sum = sum + activefornow(i + v, g + v);
					sum = sum + activefornow(i - v, g + v);
					sum = sum + activefornow(i + v, g - v);
					sum = sum + activefornow(i - v, g - v);
				}
			}
			else if (a[i][g] == 2) { //конь
				sum = sum + activefornow(i + 2, g - 1);
				sum = sum + activefornow(i + 2, g + 1);
				sum = sum + activefornow(i - 2, g - 1);
				sum = sum + activefornow(i - 2, g + 1);
				sum = sum + activefornow(i + 1, g - 2);
				sum = sum + activefornow(i + 1, g + 2);
				sum = sum + activefornow(i - 1, g - 2);
				sum = sum + activefornow(i - 1, g + 2);
			}
			else if (a[i][g] == 1) {  //ладья
				for (u = 1; u < 9; u++) {
					sum = sum + activefornow(i + u, g);
					sum = sum + activefornow(i - u, g);
					sum = sum + activefornow(i, g + u);
					sum = sum + activefornow(i, g - u);
				}
			}
			else if (a[i][g] == -6) { //для пешки
				sum = sum - activefornow(i - 1, g + 1);
				sum = sum - activefornow(i - 1, g - 1);
			}
			else if (a[i][g] == -5) {   //короля
				sum = sum - activefornow(i + 1, g - 1);
				sum = sum - activefornow(i + 1, g + 1);
				sum = sum - activefornow(i + 1, g);
				sum = sum - activefornow(i, g + 1);
				sum = sum - activefornow(i, g - 1);
				sum = sum - activefornow(i - 1, g - 1);
				sum = sum - activefornow(i - 1, g);
				sum = sum - activefornow(i - 1, g + 1);
			}
			else if (a[i][g] == -4) {  //ферзя
				for (u = 1; u < 9; u++) {
					sum = sum - activefornow(i + u, g);
					sum = sum - activefornow(i - u, g);
					sum = sum - activefornow(i, g + u);
					sum = sum - activefornow(i, g - u);
				}
				for (v = 1; v < 9; v++) {
					sum = sum - activefornow(i + v, g + v);
					sum = sum - activefornow(i - v, g + v);
					sum = sum - activefornow(i + v, g - v);
					sum = sum - activefornow(i - v, g - v);
				}
			}
			else if (a[i][g] == -3) {    //слон
				for (v = 1; v < 9; v++) {
					sum = sum - activefornow(i + v, g + v);
					sum = sum - activefornow(i - v, g + v);
					sum = sum - activefornow(i + v, g - v);
					sum = sum - activefornow(i - v, g - v);
				}
			}
			else if (a[i][g] == -2) { //конь
				sum = sum - activefornow(i + 2, g - 1);
				sum = sum - activefornow(i + 2, g + 1);
				sum = sum - activefornow(i - 2, g - 1);
				sum = sum - activefornow(i - 2, g + 1);
				sum = sum - activefornow(i + 1, g - 2);
				sum = sum - activefornow(i + 1, g + 2);
				sum = sum - activefornow(i - 1, g - 2);
				sum = sum - activefornow(i - 1, g + 2);
			}
			else if (a[i][g] == -1) {  //ладья
				for (u = 1; u < 9; u++) {
					sum = sum - activefornow(i + u, g);
					sum = sum - activefornow(i - u, g);
					sum = sum - activefornow(i, g + u);
					sum = sum - activefornow(i, g - u);
				}
			}
		}
	}
	return sum;
}

void numofattofwferz(int i, int g, const vector <vector <int> >& a, vector <vector < int> >& numofattonespot) {
	int flag = 0;
	int u;
	for (u = 1; u < 8; u++) {
		if (i + u < 8) {
			if (flag == 0) { numofattonespot[i + u][g]++; }
			if (a[i + u][g] != 0) { flag = 1; }
		}
	}
	flag = 0;
	for (u = 1; u < 8; u++) {
		if (i - u > -1) {
			if (flag == 0) { numofattonespot[i - u][g]++; }
			if (a[i - u][g] != 0) { flag = 1; }
		}
	}
	flag = 0;
	for (u = 1; u < 8; u++) {
		if (g - u > -1) {
			if (flag == 0) { numofattonespot[i][g - u]++; }
			if (a[i][g - u] != 0) { flag = 1; }
		}
	}
	flag = 0;
	for (u = 1; u < 8; u++) {
		if (g + u < 8) {
			if (flag == 0) { numofattonespot[i][g + u]++; }
			if (a[i][g + u] != 0) { flag = 1; }
		}
	}
	flag = 0;
	for (u = 1; u < 8; u++) {
		if ((i + u < 8) && (g + u < 8)) {
			if (flag == 0) { numofattonespot[i + u][g + u]++; }
			if (a[i + u][g + u] != 0) { flag = 1; }
		}
	}
	flag = 0;
	for (u = 1; u < 8; u++) {
		if ((i - u > -1) && (g + u < 8)) {
			if (flag == 0) { numofattonespot[i - u][g + u]++; }
			if (a[i - u][g + u] != 0) { flag = 1; }
		}
	}
	flag = 0;
	for (u = 1; u < 8; u++) {
		if ((i + u < 8) && (g - u > -1)) {
			if (flag == 0) { numofattonespot[i + u][g - u]++; }
			if (a[i + u][g - u] != 0) { flag = 1; }
		}
	}
	flag = 0;
	for (u = 1; u < 8; u++) {
		if ((i - u > -1) && (g - u > -1)) {
			if (flag == 0) { numofattonespot[i - u][g - u]++; }
			if (a[i - u][g - u] != 0) { flag = 1; }
		}
	}
}
void numofattofbferz(int i, int g, const vector <vector <int> >& a, vector <vector <int > >& numofattonespot) {
	int flag = 0;
	int u;
	for (u = 1; u < 8; u++) {
		if (i + u < 8) {
			if (flag == 0) { numofattonespot[i + u][g]--; }
			if (a[i + u][g] != 0) { flag = 1; }
		}
	}
	flag = 0;
	for (u = 1; u < 8; u++) {
		if (i - u > -1) {
			if (flag == 0) { numofattonespot[i - u][g]--; }
			if (a[i - u][g] != 0) { flag = 1; }
		}
	}
	flag = 0;
	for (u = 1; u < 8; u++) {
		if (g - u > -1) {
			if (flag == 0) { numofattonespot[i][g - u]--; }
			if (a[i][g - u] != 0) { flag = 1; }
		}
	}
	flag = 0;
	for (u = 1; u < 8; u++) {
		if (g + u < 8) {
			if (flag == 0) { numofattonespot[i][g + u]--; }
			if (a[i][g + u] != 0) { flag = 1; }
		}
	}
	flag = 0;
	for (u = 1; u < 8; u++) {
		if ((i + u < 8) && (g + u < 8)) {
			if (flag == 0) { numofattonespot[i + u][g + u]--; }
			if (a[i + u][g + u] != 0) { flag = 1; }
		}
	}
	flag = 0;
	for (u = 1; u < 8; u++) {
		if ((i - u > -1) && (g + u < 8)) {
			if (flag == 0) { numofattonespot[i - u][g + u]--; }
			if (a[i - u][g + u] != 0) { flag = 1; }
		}
	}
	flag = 0;
	for (u = 1; u < 8; u++) {
		if ((i + u < 8) && (g - u > -1)) {
			if (flag == 0) { numofattonespot[i + u][g - u]--; }
			if (a[i + u][g - u] != 0) { flag = 1; }
		}
	}
	flag = 0;
	for (u = 1; u < 8; u++) {
		if ((i - u > -1) && (g - u > -1)) {
			if (flag == 0) { numofattonespot[i - u][g - u]--; }
			if (a[i - u][g - u] != 0) { flag = 1; }
		}
	}
}
double KingDefenceAdv(const vector <vector <int> >& a) {
	vector <vector <int > > numofattonespot(8, vector <int>(8, 0));   //количество фигур, которые атакуют конкретное поле
	int i, g;
	int u, v;
	int xb = -1, xw = -1, yb = -1, yw = -1;
	for (i = 0; i < 8; i++) {
		for (g = 0; g < 8; g++) {
			if (a[i][g] == 5) { xw = i; yw = g; }
			if (a[i][g] == -5) { xb = i; yb = g; }
		}
	}
	for (i = 0; i < 8; i++) {
		for (g = 0; g < 8; g++) {
			if (a[i][g] == 6) { //для пешки
				if ((i + 1 <= 7) && (g - 1 >= 0)) numofattonespot[i + 1][g - 1]++;
				if ((i + 1 <= 7) && (g + 1 <= 7)) numofattonespot[i + 1][g + 1]++;
			}
			else if (a[i][g] == 5) {   //короля
				if ((i + 1 <= 7) && (g - 1 >= 0)) numofattonespot[i + 1][g - 1]++;
				if ((i + 1 <= 7) && (g + 1 <= 7))numofattonespot[i + 1][g + 1]++;
				if (i + 1 <= 7) numofattonespot[i + 1][g]++;
				if (g + 1 <= 7) numofattonespot[i][g + 1]++;
				if (g - 1 >= 0) numofattonespot[i][g - 1]++;
				if ((i - 1 >= 0) && (g - 1 >= 0)) numofattonespot[i - 1][g - 1]++;
				if (i - 1 >= 0) numofattonespot[i - 1][g]++;
				if ((i - 1 >= 0) && (g + 1 <= 7)) numofattonespot[i - 1][g + 1]++;
			}
			else if (a[i][g] == 4) {  //ферзя
				numofattofwferz(i, g, a, numofattonespot);
			}
			else if (a[i][g] == 3) {    //слон
				int flag = 0;
				for (u = 1; u < 8; u++) {
					if ((i + u < 8) && (g + u < 8)) {
						if (flag == 0) { numofattonespot[i + u][g + u]++; }
						if (a[i + u][g + u] != 0) { flag = 1; }
					}
				}
				flag = 0;
				for (u = 1; u < 8; u++) {
					if ((i - u > -1) && (g + u < 8)) {
						if (flag == 0) { numofattonespot[i - u][g + u]++; }
						if (a[i - u][g + u] != 0) { flag = 1; }
					}
				}
				flag = 0;
				for (u = 1; u < 8; u++) {
					if ((i + u < 8) && (g - u > -1)) {
						if (flag == 0) { numofattonespot[i + u][g - u]++; }
						if (a[i + u][g - u] != 0) { flag = 1; }
					}
				}
				flag = 0;
				for (u = 1; u < 8; u++) {
					if ((i - u > -1) && (g - u > -1)) {
						if (flag == 0) { numofattonespot[i - u][g - u]++; }
						if (a[i - u][g - u] != 0) { flag = 1; }
					}
				}
			}
			else if (a[i][g] == 2) { //конь
				if ((i + 2 < 8) && (g - 1 > -1))  numofattonespot[i + 2][g - 1]++;
				if ((i + 2 < 8) && (g + 1 < 8))   numofattonespot[i + 2][g + 1]++;
				if ((i - 2 > -1) && (g - 1 > -1)) numofattonespot[i - 2][g - 1]++;
				if ((i - 2 > -1) && (g + 1 < 8))  numofattonespot[i - 2][g + 1]++;
				if ((i + 1 < 8) && (g - 2 > -1))  numofattonespot[i + 1][g - 2]++;
				if ((i + 1 < 8) && (g + 2 < 8))   numofattonespot[i + 1][g + 2]++;
				if ((i - 1 > -1) && (g - 2 > -1)) numofattonespot[i - 1][g - 2]++;
				if ((i - 1 > -1) && (g + 2 < 8))  numofattonespot[i - 1][g + 2]++;
			}
			else if (a[i][g] == 1) {  //ладья
				int flag = 0;
				int u;
				for (u = 1; u < 8; u++) {
					if (i + u < 8) {
						if (flag == 0) { numofattonespot[i + u][g]++; }
						if (a[i + u][g] != 0) { flag = 1; }
					}
				}
				flag = 0;
				for (u = 1; u < 8; u++) {
					if (i - u > -1) {
						if (flag == 0) { numofattonespot[i - u][g]++; }
						if (a[i - u][g] != 0) { flag = 1; }
					}
				}
				flag = 0;
				for (u = 1; u < 8; u++) {
					if (g - u > -1) {
						if (flag == 0) { numofattonespot[i][g - u]++; }
						if (a[i][g - u] != 0) { flag = 1; }
					}
				}
				flag = 0;
				for (u = 1; u < 8; u++) {
					if (g + u < 8) {
						if (flag == 0) { numofattonespot[i][g + u]++; }
						if (a[i][g + u] != 0) { flag = 1; }
					}
				}
			}
			else if (a[i][g] == -6) { //для пешки
				if ((i - 1 <= 7) && (g - 1 >= 0)) numofattonespot[i - 1][g - 1]--;
				if ((i - 1 <= 7) && (g + 1 <= 7)) numofattonespot[i - 1][g + 1]--;
			}
			else if (a[i][g] == -5) {   //короля
				if ((i + 1 <= 7) && (g - 1 >= 0)) numofattonespot[i + 1][g - 1]--;
				if ((i + 1 <= 7) && (g + 1 <= 7))numofattonespot[i + 1][g + 1]--;
				if (i + 1 <= 7) numofattonespot[i + 1][g]--;
				if (g + 1 <= 7) numofattonespot[i][g + 1]--;
				if (g - 1 >= 0) numofattonespot[i][g - 1]--;
				if ((i - 1 >= 0) && (g - 1 >= 0)) numofattonespot[i - 1][g - 1]--;
				if (i - 1 >= 0) numofattonespot[i - 1][g]--;
				if ((i - 1 >= 0) && (g + 1 <= 7)) numofattonespot[i - 1][g + 1]--;
			}
			else if (a[i][g] == -4) {  //ферзя
				numofattofbferz(i, g, a, numofattonespot);
			}
			else if (a[i][g] == -3) {    //слон
				int flag = 0;
				for (u = 1; u < 8; u++) {
					if ((i + u < 8) && (g + u < 8)) {
						if (flag == 0) { numofattonespot[i + u][g + u]--; }
						if (a[i + u][g + u] != 0) { flag = 1; }
					}
				}
				flag = 0;
				for (u = 1; u < 8; u++) {
					if ((i - u > -1) && (g + u < 8)) {
						if (flag == 0) { numofattonespot[i - u][g + u]--; }
						if (a[i - u][g + u] != 0) { flag = 1; }
					}
				}
				flag = 0;
				for (u = 1; u < 8; u++) {
					if ((i + u < 8) && (g - u > -1)) {
						if (flag == 0) { numofattonespot[i + u][g - u]--; }
						if (a[i + u][g - u] != 0) { flag = 1; }
					}
				}
				flag = 0;
				for (u = 1; u < 8; u++) {
					if ((i - u > -1) && (g - u > -1)) {
						if (flag == 0) { numofattonespot[i - u][g - u]--; }
						if (a[i - u][g - u] != 0) { flag = 1; }
					}
				}
			}
			else if (a[i][g] == -2) { //конь
				if ((i + 2 < 8) && (g - 1 > -1))  numofattonespot[i + 2][g - 1]--;
				if ((i + 2 < 8) && (g + 1 < 8))   numofattonespot[i + 2][g + 1]--;
				if ((i - 2 > -1) && (g - 1 > -1)) numofattonespot[i - 2][g - 1]--;
				if ((i - 2 > -1) && (g + 1 < 8))  numofattonespot[i - 2][g + 1]--;
				if ((i + 1 < 8) && (g - 2 > -1))  numofattonespot[i + 1][g - 2]--;
				if ((i + 1 < 8) && (g + 2 < 8))   numofattonespot[i + 1][g + 2]--;
				if ((i - 1 > -1) && (g - 2 > -1)) numofattonespot[i - 1][g - 2]--;
				if ((i - 1 > -1) && (g + 2 < 8))  numofattonespot[i - 1][g + 2]--;
			}
			else if (a[i][g] == -1) {  //ладья
				int flag = 0;
				int u;
				for (u = 1; u < 8; u++) {
					if (i + u < 8) {
						if (flag == 0) { numofattonespot[i + u][g]--; }
						if (a[i + u][g] != 0) { flag = 1; }
					}
				}
				flag = 0;
				for (u = 1; u < 8; u++) {
					if (i - u > -1) {
						if (flag == 0) { numofattonespot[i - u][g]--; }
						if (a[i - u][g] != 0) { flag = 1; }
					}
				}
				flag = 0;
				for (u = 1; u < 8; u++) {
					if (g - u > -1) {
						if (flag == 0) { numofattonespot[i][g - u]--; }
						if (a[i][g - u] != 0) { flag = 1; }
					}
				}
				flag = 0;
				for (u = 1; u < 8; u++) {
					if (g + u < 8) {
						if (flag == 0) { numofattonespot[i][g + u]--; }
						if (a[i][g + u] != 0) { flag = 1; }
					}
				}
			}
		}
	}
	long double sum = 0;
	for (i = 0; i < 8; i++) {
		for (g = 0; g < 8; g++) {
			if ((abs(a[i][g]) == 2) || (abs(a[i][g]) == 3)) { sum = sum + 0.03 * numofattonespot[i][g]; }
			else if (abs(a[i][g]) == 4) { sum = sum + 0.09 * numofattonespot[i][g]; }
			else if (abs(a[i][g]) == 1) { sum = sum + 0.05 * numofattonespot[i][g]; }
			else if (abs(a[i][g]) == 6) { sum = sum + 0.03 * numofattonespot[i][g]; }
		}
	}
	//for white
	if (xw != -1) {
		if ((xw + 1 < 8) && (yw + 1 < 8) && (xw + 1 > -1) && (yw + 1 > -1)) { sum = sum + 0.1 * numofattonespot[xw + 1][yw + 1]; }
		if ((xw + 1 < 8) && (yw < 8) && (xw + 1 > -1) && (yw > -1)) { sum = sum + 0.1 * numofattonespot[xw + 1][yw]; }
		if ((xw + 1 < 8) && (yw - 1 < 8) && (xw + 1 > -1) && (yw - 1 > -1)) { sum = sum + 0.1 * numofattonespot[xw + 1][yw - 1]; }
		if ((xw - 1 < 8) && (yw + 1 < 8) && (xw - 1 > -1) && (yw + 1 > -1)) { sum = sum + 0.1 * numofattonespot[xw - 1][yw + 1]; }
		if ((xw - 1 < 8) && (yw < 8) && (xw - 1 > -1) && (yw > -1)) { sum = sum + 0.1 * numofattonespot[xw - 1][yw]; }
		if ((xw - 1 < 8) && (yw - 1 < 8) && (xw - 1 > -1) && (yw - 1 > -1)) { sum = sum + 0.1 * numofattonespot[xw - 1][yw - 1]; }
		if ((xw < 8) && (yw + 1 < 8) && (xw > -1) && (yw + 1 > -1)) { sum = sum + 0.1 * numofattonespot[xw][yw + 1]; }
		if ((xw < 8) && (yw - 1 < 8) && (xw > -1) && (yw - 1 > -1)) { sum = sum + 0.1 * numofattonespot[xw][yw - 1]; }
		sum = sum + 0.12 * numofattonespot[xw][yw];

	}
	//for black
	if (xb != -1) {
		if ((xb + 1 < 8) && (yb + 1 < 8) && (xb + 1 > -1) && (yb + 1 > -1)) {
			sum = sum + 0.1 * numofattonespot[xb + 1][yb + 1];
		}
		if ((xb + 1 < 8) && (yb < 8) && (xb + 1 > -1) && (yb > -1)) {
			sum = sum + 0.1 * numofattonespot[xb + 1][yb];
		}
		if ((xb + 1 < 8) && (yb - 1 < 8) && (xb + 1 > -1) && (yb - 1 > -1)) {
			sum = sum + 0.1 * numofattonespot[xb + 1][yb - 1];
		}
		if ((xb - 1 < 8) && (yb + 1 < 8) && (xb - 1 > -1) && (yb + 1 > -1)) {
			sum = sum + 0.1 * numofattonespot[xb - 1][yb + 1];
		}
		if ((xb - 1 < 8) && (yb < 8) && (xb - 1 > -1) && (yb > -1)) {
			sum = sum + 0.1 * numofattonespot[xb - 1][yb];
		}
		if ((xb - 1 < 8) && (yb - 1 < 8) && (xb - 1 > -1) && (yb - 1 > -1)) {
			sum = sum + 0.1 * numofattonespot[xb - 1][yb - 1];
		}
		if ((xb < 8) && (yb + 1 < 8) && (xb > -1) && (yb + 1 > -1)) {
			sum = sum + 0.1 * numofattonespot[xb][yb + 1];
		}
		if ((xb < 8) && (yb - 1 < 8) && (xb > -1) && (yb - 1 > -1)) {
			sum = sum + 0.1 * numofattonespot[xb][yb - 1];
		}
		sum = sum + 0.12 * numofattonespot[xb][yb];
	}
	return sum;
}

double Evaluate(const vector<vector<int>>& theMatrix, bool whites_turn)
{
	double res = 0;
	if (check_mate(theMatrix, whites_turn) == 2)
		return define_color(whites_turn) * -200;
	res += MatAdv(theMatrix);
	res += PawnAdv(theMatrix, whites_turn);
	res += ActivyAdv(theMatrix);
	res += KingDefenceAdv(theMatrix);
	return res;
}
