#include <ctime>
#include <cstdlib>
#include "snake.h"
Snake::Snake(bool***& board, int size):board_size(size){
    mode = directions[0];
    board = new bool**[size];
    for(int i = 0; i < size; i++){
        board[i] = new bool*[size];
        for(int j = 0; j < size; j++){
             board[i][j] = new bool[2];
             board[i][j][0] = false;
             board[i][j][1] = false;
        }
    }
    board[0][0][0] = true;
    generateNewApple(board);
    dq.push_back(new int[2] {0, 0});
}
bool Snake::moveBody(bool***& board){
    //board -> {{{False, False}, 열}, 행}
    int goCol = mode[0], goRow = mode[1];
    int* cal = dq.front();
    int movedCol = cal[0] + goCol, movedRow = cal[1] + goRow;
    if(movedCol < 0 || movedRow < 0 || movedCol == board_size || movedRow == board_size || board[movedCol][movedRow][0]) return false;
    dq.push_front(new int[2] {movedCol, movedRow});
    board[movedCol][movedRow][0] = true;
    if(!board[movedCol][movedRow][1]){
        int* tail = dq.back();
        dq.pop_back();
        board[tail[0]][tail[1]][0] = false;
    }
    else{
        board[movedCol][movedRow][1] = false;
        score++;
        generateNewApple(board);
    }
    return true;
}
void Snake::changeDirection(int modeInt){
    mode = directions[modeInt];
}
void Snake::generateNewApple(bool***& board){
    srand(time(0));
    int randomCol = rand() % board_size;
    int randomRow = rand() % board_size;
    if(board[randomCol][randomRow][0]) generateNewApple(board);
    board[randomCol][randomRow][1] = true;
}
int Snake::getScore(){return score;}