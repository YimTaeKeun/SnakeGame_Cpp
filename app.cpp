#include <conio.h>
#include "snake.cpp"
#include <iostream>
#include <Windows.h>
using namespace std;
bool*** board;
int board_size;
void printBoard();
void initiallizeBoard();
void inputDirection(Snake&);
int main(){
    cout << "Input Board Size: ";
    cin >> board_size;
    Snake mySnake(board, board_size);
    printBoard();
    bool isContinue = false;
    do{
        system("cls");
        isContinue = mySnake.moveBody(board);
        cout << "Score:" << mySnake.getScore() << endl << endl;
        printBoard();
        inputDirection(mySnake);
        Sleep(100);
    }while(isContinue);
    system("cls");
    cout << "Score:" << mySnake.getScore() << endl << endl;
    printBoard();
    _getch();
    return 0;
}
void initiallizeBoard(){
    board = new bool**[board_size];
    for(int i = 0; i < board_size; i++){
        board[i] = new bool*[board_size];
        for(int j= 0; j < board_size; j++){
             board[i][j] = new bool[2];
             board[i][j][0] = false;
             board[i][j][1] = false;
        }
    }
    printBoard();
}
void printBoard(){
    for(int i = 0; i < board_size + 2; i++) cout << "- ";
    cout << endl;
    for(int i = 0; i < board_size; i++){
        cout << "- ";
        for(int j = 0; j < board_size; j++){
            if(board[i][j][0]) cout << "B ";
            else if(board[i][j][1]) cout << "A ";
            else cout << "  ";
        }
        cout << "-" << endl;
    }
    for(int i = 0; i < board_size + 2; i++) cout << "- ";
    cout << endl;
}
void inputDirection(Snake& mySnake){
    if (_kbhit()) {  // 키보드 입력이 있는지 확인
        switch (_getch()) {  // 키보드 입력 받기 (Windows에서만 동작)
            case 'a':
                mySnake.changeDirection(2);
                break;
            case 'd':
                mySnake.changeDirection(0);
                break;
            case 'w':
                mySnake.changeDirection(3);
                break;
            case 's':
                mySnake.changeDirection(1);
                break;
        }
    }
}
//print ■