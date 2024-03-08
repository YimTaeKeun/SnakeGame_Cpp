#include <ctime>
#include <cstdlib>
#include "snake.h"
Snake::Snake(bool***& board, int size):board_size(size){
    mode = directions[0];
    board = new bool**[size];
    for(int i = 0; i < size; i++){
        board[i] = new bool*[size];
        for(int j = 0; j < size; j++){
             board[i][j] = new bool[4];
             // board[i][j]에 장애물, 길이 줄어드는 아이템을 포함하는 배열 만들기
             /*
             0: snake 위치파악
             1: 사과 유무
             2: 길이 줄어드는 애 유무
             3: 장애물 파악
             */
             fill_n(board[i][j], 4, false);
            //  board[i][j][0] = false;
            //  board[i][j][1] = false;
        }
    }
    board[0][0][0] = true;
    generate(0, board);
    // generateNewApple(board);
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
    if(board[movedCol][movedRow][1]){
        board[movedCol][movedRow][1] = false;
        score++;
        generateNewApple(board);
    }
    else if(board[movedCol][movedRow][2]){
        // 줄어드는 애 만났을 때(꼬리가 줄어드는 걸로)
        board[movedCol][movedRow][2] = false;
        int* tail = dq.back();
        dq.pop_back();
        board[tail[0]][tail[1]][0] = false;

        tail = dq.back();
        dq.pop_back();
        board[tail[0]][tail[1]][0] = false;
        if(dq.size() == 0) return false;
        generateNewPoison(board);
    }
    else if(board[movedCol][movedRow][3]){
        // 장애물 만났을 때
        return false;
    }
    else{
        int* tail = dq.back();
        dq.pop_back();
        board[tail[0]][tail[1]][0] = false;
    }
    return true;
}
void Snake::changeDirection(int modeInt){
    mode = directions[modeInt];
}
void Snake::generateNewApple(bool***& board){
    srand(time(0));
    int randomCol = 0, randomRow = 0;
    do{
        randomCol = rand() % board_size;
        randomRow = rand() % board_size;
    }while(board[randomCol][randomRow][0] || board[randomCol][randomRow][2] || board[randomCol][randomRow][3]);
    board[randomCol][randomRow][1] = true;
    // 이 함수에 랜덤으로 아이템을 생성하는 기능을 생성
    // 랜덤 아이템은 1부터 3까지만 생서되도록
}
void Snake::generateNewPoison(bool***& board){
    srand(time(0));
    int randomCol = 0, randomRow = 0;
    do{
        randomCol = rand() % board_size;
        randomRow = rand() % board_size;
    }while(board[randomCol][randomRow][0] || board[randomCol][randomRow][1] || board[randomCol][randomRow][3]);
    board[randomCol][randomRow][2] = true;
}
void Snake::generateNewWall(bool***& board){
    srand(time(0));
    int randomCol = 0, randomRow = 0;
    do{
        randomCol = rand() % board_size;
        randomRow = rand() % board_size;
    }while(board[randomCol][randomRow][0] || board[randomCol][randomRow][1] || board[randomCol][randomRow][2]);
    board[randomCol][randomRow][3] = true;
}
int Snake::getScore(){return score;}
void Snake::generate(int mode, bool***& board){
    switch (mode)
    {
    case 1:
        generateNewApple(board);
        break;
    case 2:
        generateNewPoison(board);
        break;
    case 3:
        generateNewWall(board);
        break;
    default:
        generateNewApple(board);
        generateNewPoison(board);
        generateNewWall(board);
    }
}