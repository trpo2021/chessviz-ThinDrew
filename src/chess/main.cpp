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

    int swing = 0;
    int party = 1;

    do {
        int index = 0; //будет прибавляться, если мы указываем тип фигуры
        string input; //входные данные
        bool flag = false, side, friendly_fire = true;
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

        if (border_check(input, size_str) == false){ // Проверка на соблюдение границы
        	cerr << "Ошибка: Выход за границы\n";
        	continue;
		}

		if (input.empty() || input.size() > size_str) {
    		cerr << "Ошибка: Строка либо пуста, либо больше, чем нужно" << endl;
    		continue;
		}

		if(index == 1){
	        if (figure_check(table, y, x, input[0]) == false){ // Проверка типа фигуры
	        	cerr << "Ошибка: Фигуры не соответствуют\n";
	        	continue;
			}
		}

		if(index == 0) { // Проверка - не является ли пешка фигурой
			if (pawn_check(table, y, x) == false) {
				cerr << "Ошибка: Эта фигура не является пешкой\n";
			
	        	continue;
			}
		}

		if (type_check(table, y, x, y_end, x_end, input[2+index], friendly_fire, swing) == false){ // Проверка на тип хода (перемещение, взятие)
			cerr << "Ошибка: Тип хода не соответствует действию\n"; 
			
			continue;
		}

		if (friendly_fire == false){
			cerr << "Ошибка: Вы не можете съесть своих\n";
			continue;
		}

		switch(swing){
        	case 0: 
				side = white_step(table, y, x, swing); //можем ввести только большой регистр, иначе side = false
        		break;
        	case 1: 
				side = black_step(table, y, x, swing); //можем ввести только маленький регистр, иначе side = false
				break;
		}
		

		if(side == false){ // Если ввели не тот регистр
			cerr << "Ошибка: Сейчас ходит противоположная сторона\n";
			continue;
		}

        //Перемещение фигуры
        table[y_end][x_end] = table[y][x];
        table[y][x] = ' ';
        //Вывод результата:
        print_board(table);

        switch (swing) {
        	case 1:
        		printf("\nХод чёрных: \n");
        		printf("%d. ", party);
        		break;
        	case 0:
        		printf("\nХод белых: \n");
        		party++;
        		printf("%d. ", party);
        		break;
		}

    } while (true);
}