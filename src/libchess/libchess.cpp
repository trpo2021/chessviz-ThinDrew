#include <stdio.h>

bool figure_check(char table[8][8], int y, int x, char input)
{ // Проверка типа фигуры
    if ((input + 32) == table[y][x] || input == table[y][x])
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