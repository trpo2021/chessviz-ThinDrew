#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

bool friendly_fire_(char table[8][8], int y_end, int x_end, int &swing){
	if (table[y_end][x_end]  >= 'a'  and swing == 0)
		return true;
	if (table[y_end][x_end]  < 'Z' and swing == 1)
		return true;
	return false;
}

bool white_step(char table[8][8], int y, int x, int &swing){ //Проверка на регистр и смена хода
	if (table[y][x] < 'Z'){
		swing++;
		return true;	
	}
	return false;
}

bool black_step(char table[8][8], int y, int x, int &swing){ //Проверка на регистр и смена хода
	if(table[y][x] > 'a'){
		swing--;
		return true;
	}
	
	return false;
}

bool border_check(string input, const int size_str)
{
    int border_check = 0; //будет равен 4, если мы не вышли за границы
    for (int i = 0; i < size_str; i++) {
        if ((input[i] >= 'a' && input[i] <= 'h') || (input[i] >= '0' && input[i] <= '9')) {
            border_check++;
        }
    }
    if (border_check != 4) {
        return false;
    }
    return true;
}

bool figure_check(char table[8][8], int y, int x, char input)
{ // Проверка типа фигуры
    if ((input + 32) == table[y][x] || input == table[y][x])
        return true;
    else
        return false;
}

bool pawn_check(char table[8][8], int y, int x)
{ // Проверка - не является ли пешка фигурой
    if ((table[y][x] == 'P') || (table[y][x] == 'p'))
        return true;
    else
        return false;
}

bool type_check(char table[8][8], int y, int x, int y_end, int x_end, char input, bool& friendly_fire, int& swing)
{ // Проверка на тип хода (перемещение, взятие)
    bool t = false;
    if (input == '-' && table[y_end][x_end] == ' ' && table[y][x] != ' ') {
        t = true;
        return t;
    }
    if (input == 'x' && table[y_end][x_end] != ' ' && table[y][x] != ' ') {
        friendly_fire = friendly_fire_(table, y_end, x_end, swing);
        t = true;
        return t;
    }

    return t;
}

bool move_check(char table [8][8], int y, int x, int y_end, int x_end) { // Проверка на соблюдение правил движения фигур
	int dx, dy;
	if (table[y][x] == 'N' || table[y][x] == 'n') {
		dx = x_end-x;
		dy = y_end-y;
		if (abs(dx)==2 and abs(dy)==1) return true;
		if (abs(dx)==1 and abs(dy)==2) return true;
		else return false;
	}
	if (table[y][x] == 'B' || table[y][x] == 'b') {
		int i, j;
		dx = x_end-x;
		dy = y_end-y;
		if (abs(dx)!=abs(dy)) return false;
		cout << abs(dx) << " " << abs(dy) << endl;
		dx/=abs(dx);
		dy/=abs(dy);
		for (i=x+dx, j=y+dy; i != x_end; i+=dx, j+=dy) {
			cout << table[j][i] << " " << j << " " << i << endl;
			if(table[j][i]!=' ') return false;
		}
		return true;
	}
	if (table[y][x] == 'R' || table[y][x] == 'r') {
		int i, j;
		dx = x_end-x;
		dy = y_end-y;
		cout << abs(dx) << " " << abs(dy) << endl;
		if (dx != 0 && dy == 0) {
			dx/=abs(dx);
			for (i = x+dx, j = y+dy; i != x_end; i+=dx){
				cout << table[j][i] << " " << j << " " << i << endl;
				if(table[j][i]!=' ') return false;
			}
			return true;
		}
		
		if (dy != 0 && dx == 0){
			dy/=abs(dy);
			for (i = x+dx, j = y+dy; j != y_end; j+=dy){
				cout << table[j][i] << " " << j << " " << i << endl;
				if(table[j][i]!=' ') return false;
			}
			return true;
		}
		return false;
	}
	else return false;
}

void print_board(char table[8][8])
{ // вывод доски
    for (int i = 0; i < 8; ++i) {
        printf("%d ", 8 - i);
        for (int j = 0; j < 8; ++j) {
            printf("%c ", table[i][j]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}