#ifndef SNAKE_H
#define SNAKE_H
using namespace std;
class Snake{
    private:
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int* mode;
    public:
        Snake();
        bool moveBody();
        void changeDirection();
};
#endif