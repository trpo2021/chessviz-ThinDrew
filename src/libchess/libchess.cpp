#include <stdio.h>
#include <string>
using namespace std;

bool friendly_fire_(char table[8][8], int y_end, int x_end, int &swing){
	if (table[y_end][x_end]  >= 'a'  and swing == 0)
		return true;
	if (table[y_end][x_end]  < 'Z' and swing == 1)
		return true;
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