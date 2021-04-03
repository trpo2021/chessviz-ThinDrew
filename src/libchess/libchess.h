#include <string>
using namespace std;

void print_board(char table[8][8]);
bool figure_check(char table[8][8], int y, int x, char input);
bool pawn_check(char table[8][8], int y, int x);
bool border_check(string input, const int size_str);
bool type_check(char table[8][8], int y, int x, int y_end, int x_end, char input, bool& friendly_fire, int& swing);
bool friendly_fire_(char table[8][8], int y_end, int x_end, int &swing);