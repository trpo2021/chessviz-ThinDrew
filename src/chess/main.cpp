#include <clocale>
#include <iostream>
#include <libchess/libchess.h>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    char table[8][8]; //объявление доски

    for (int i = 0; i < 8; ++i) //заполнение доски
        for (int j = 0; j < 8; ++j)
            table[i][j] = ' ';

    for (int i = 0; i < 8; ++i) {
        table[1][i] = 'p';
        table[6][i] = 'P';
    }

    table[0][0] = 'r';
    table[0][7] = 'r';
    table[7][0] = 'R';
    table[7][7] = 'R';
    table[0][1] = 'n';
    table[0][6] = 'n';
    table[7][1] = 'N';
    table[7][6] = 'N';
    table[0][2] = 'b';
    table[0][5] = 'b';
    table[7][2] = 'B';
    table[7][5] = 'B';
    table[0][3] = 'q';
    table[7][3] = 'Q';
    table[0][4] = 'k';
    table[7][4] = 'K';

    print_board(table);

    do {
        int index = 0; //будет прибавляться, если мы указываем тип фигуры
        string input; //входные данные
        input.clear();
        cin >> input;

        printf("\n");

        //конвертация из входных данных в координаты доски
        int x, x_end, y, y_end;
        x = input[0 + index] - 'a';
        x_end = input[3 + index] - 'a';
        y = input[1 + index] - '1';
        y_end = input[4 + index] - '1';
        y = 7 - y;
        y_end = 7 - y_end;

        printf("\nx: %d, y: %d, x_end: %d, y_end: %d\n", x, y, x_end, y_end); //сделано для понимания координат, можно убрать

        //Перемещение фигуры
        table[y_end][x_end] = table[y][x];
        table[y][x] = ' ';
        //Вывод результата:
        print_board(table);

    } while (true);
}