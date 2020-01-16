#include <iostream>
#include <cstdio>
#include <math.h>

const int MAP_HEIGHT = 10;
const int MAP_WIDTH = 20;
const int MAP_TERRITORY_SIZE = 40;
enum Territory
{
    EMPTY,
    HEALTHY,
    INFECTED,
    DEAD
};

int randInt(int max)
{
    return (int)(((double)rand() / (double)RAND_MAX) * max);
}

void printMap(Territory *map[MAP_HEIGHT][MAP_WIDTH])
{
    std::cout << "MAP:" << std::endl;
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            switch (*map[i][j])
            {
            case EMPTY:
                std::cout << "  ";
                break;
            case HEALTHY:
                std::cout << "O ";
                break;
            case INFECTED:
                std::cout << "% ";
                break;
            case DEAD:
                std::cout << "X ";
            }
        }
        std::cout << std::endl;
    }
}

void setup(Territory *map[MAP_HEIGHT][MAP_WIDTH])
{
    int startX = randInt(MAP_WIDTH);
    int startY = randInt(MAP_HEIGHT);
    int numMoves = randInt(MAP_TERRITORY_SIZE);
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {

            *map[i][j] = EMPTY;
        }
    }

    *map[startY][startX] = HEALTHY;
    for (int i = 0; i < numMoves; i++)
    {
        bool done = false;
        bool end = false;
        int x, y;
        int count = 0;
        while (!done)
        {
            y = startY + (rand() % 3 - 1);
            x = startX + (rand() % 3 - 1);
            count++;
            if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT && *map[y][x] == EMPTY)
            {
                *map[y][x] = HEALTHY;
                startX = x;
                startY = y;
                done = true;
            }
            else if (count > 20)
            {
                end = true;
                done = true;
            }
        }
        if (end)
            break;
    }

    printMap(map);
}

bool loop()
{
    return true;
}

int main()
{
    bool gameOver = false;
    Territory *map[MAP_HEIGHT][MAP_WIDTH];

    setup(map);
    while (!gameOver)
    {
        if (loop())
            gameOver = true;
    }
    std::cout << "Game Over!" << std::endl;
    std::cin;
    return 0;
}