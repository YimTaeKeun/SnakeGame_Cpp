#include "snake.h"
#include <iostream>
using namespace std;
bool*** board;
int board_size;
void printBoard();
int main(){
    return 0;
}
void printBoard(){
    for(int i = 0; i < board_size + 2; i++) cout << "- ";
    cout << endl;
    for(int i = 0; i < board_size; i++){
        cout << "- ";
        for(int j = 0; j < board_size; j++){
            if(board[i][j][0]) cout << "■ ";
            else if(board[i][j][1]) cout << "● ";
            else cout << "* ";
        }
        cout << "-" << endl;
    }
    for(int i = 0; i < board_size + 2; i++) cout << "- ";
}
//print ■