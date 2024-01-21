#ifndef SNAKE_H
#define SNAKE_H
#include <deque>
using namespace std;
class Snake{
    private:
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int* mode;
        int board_size;
        deque<int[]> dq;
    public:
        Snake(bool***, int);
        bool moveBody(bool***);
        //0: 오른쪽, 1: 아래쪽, 2: 왼쪽, 3: 위쪽
        void changeDirection(int);
};
#endif