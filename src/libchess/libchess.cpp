#include <stdio.h>

bool border_check(string input, const int size_str)
{
    int border_check = 0; //будет равен 4, если мы не вышли за границы
    for (int i = 0; i < size_str; i++) {
        if ((input[i] >= 'a' && input[i] <= 'h') || (input[i] >= '0' && input[i] <= '9')) {
            border_check++; //будет равен 4, если мы не вышли за границы
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