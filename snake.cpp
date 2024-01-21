#include "snake.h"
Snake::Snake(bool*** board, int size):board_size(size){
    mode = directions[0];
    board = new bool**[size];
    for(int i = 0; i < size; i++){
        board[i] = new bool*[size];
        for(int j = 0; j < size; j++) board[i][j] = new bool[2];
    }
    board[0][0][0] = true;
    dq.push_back({0, 0});
}
bool Snake::moveBody(bool*** board){
    //board -> {{{False, False}, 열}, 행}
    int goCol = mode[0], goRow = mode[1];
    int* cal = dq.front();
    int movedCol = cal[0] + goCol, movedRow = cal[1] + goRow;
    if(movedCol < 0 || movedRow < 0 || movedCol == board_size || movedRow == board_size) return false;
    dq.push_front({movedCol, movedRow});
    board[movedCol][movedRow][0] = true;
    if(!board[movedCol][movedRow][1]){
        int* tail = dq.back();
        dq.pop_back();
        board[tail[0]][tail[1]][0] = false;
    }
    else board[movedCol][movedRow][1] = false;
    return true;
}
void Snake::changeDirection(int modeInt){
    mode = directions[modeInt];
}