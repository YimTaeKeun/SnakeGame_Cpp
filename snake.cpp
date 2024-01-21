#include "snake.h"
Snake::Snake(bool*** board, int size){
    mode = directions[0];
    board = new bool**[size];
    for(int i = 0; i < size; i++){
        board[i] = new bool*[size];
        for(int j = 0; j < size; j++) board[i][j] = new bool[2];
    }
    board[0][0][0] = true;
}
bool Snake::moveBody(bool*** board){
    //board -> {{{False, False}, 열}, 행}
}
void Snake::changeDirection(int modeInt){
    mode = directions[modeInt];
}