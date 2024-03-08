#ifndef SNAKE_H
#define SNAKE_H
#include <deque>
using namespace std;
class Snake{
    private:
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int* mode;
        int board_size;
        int score = 0;
        deque<int*> dq;
        void generate(int mode, bool***&); // 1: apple, 2: 줄어듦, 3: 장애물
        void generateNewApple(bool***&);
        void generateNewPoison(bool***&);
        void generateNewWall(bool***&);
    public:
        Snake(bool***&, int);
        bool moveBody(bool***&);
        //0: 오른쪽, 1: 아래쪽, 2: 왼쪽, 3: 위쪽
        void changeDirection(int);
        int getScore();
};
#endif