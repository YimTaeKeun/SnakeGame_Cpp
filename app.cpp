#include "snake.cpp"
#include <iostream>
#include <Windows.h>
using namespace std;
bool*** board;
int board_size;
void printBoard();
void initiallizeBoard();
int main(){
    cout << "Input Board Size: ";
    cin >> board_size;
    Snake mySnake(board, board_size);
    printBoard();
    bool isContinue = false;
    do{
        system("cls");
        isContinue = mySnake.moveBody(board);
        printBoard();
        Sleep(150);
    }while(isContinue);
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
            else cout << "* ";
        }
        cout << "-" << endl;
    }
    for(int i = 0; i < board_size + 2; i++) cout << "- ";
    cout << endl;
}
//print ■