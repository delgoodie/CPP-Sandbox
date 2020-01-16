#include <iostream>
#include <cstdio>
#include <math.h>

const int MAP_HEIGHT = 5;
const int MAP_WIDTH = 5;

void setup()
{
}

class Territory
{
public:
    int coords[2];
    enum Status = {NULL = 0, HEALTHY, INFECTED, DEAD}; // all map coords are territories but can be null spaces or land units
    Status status = Status.NULL;
    Territory();

private:
};

Territory::Territory()
{
}

void printMapconst()
{
    //re-written for territory array
}

void loop()
{
}

int main()
{
    while (!gameOver)
    {
        loop();
    }
    std::cout << "Game Over!" << std::endl;
    std::cin;
    return 0;
}