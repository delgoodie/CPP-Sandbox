#include <iostream>
#include <cstdio>
#include <math.h>
#include <string>

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

void printMap(Territory **);
int randInt(int);
void setup(Territory **);
bool loop();

int randInt(int max)
{
    return (int)(((double)rand() / (double)RAND_MAX) * max);
}

void printMap(Territory **map)
{
    std::cout << "MAP:" << std::endl
              << "  ";
    for (int i = 0; i < MAP_WIDTH; i++)
        std::cout << (char)(i + 65) << " ";
    std::cout << std::endl;
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        std::cout << i << " ";
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            switch (*(*(map + i) + j))
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

void setup(Territory **map)
{
    int startX = randInt(MAP_WIDTH);
    int startY = randInt(MAP_HEIGHT);
    int numMoves = randInt(MAP_TERRITORY_SIZE) + 50;
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {

            *(*(map + i) + j) = EMPTY;
        }
    }

    *(*(map + startY) + startX) = HEALTHY;
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
            if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT && *(*(map + y) + x) == EMPTY)
            {
                *(*(map + y) + x) = HEALTHY;
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
    std::cout << "Enter the starting coordinates: [A-" << (char)(MAP_WIDTH + 65) << ", 0-" << MAP_HEIGHT << "]" << std::endl;
    char ret[5];
    std::cin >> ret;
    int x;
    int y;
    if (ret[0] - 65 > -1 && ret[0] - 65 < MAP_WIDTH && ret[3] - 48 > -1 && ret[3] - 48 < MAP_HEIGHT)
    {
        x = (ret[0] - 65);
        y = (ret[3] - 48);
        *(*(map + y) + x) = INFECTED;
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
    Territory **map = new Territory *[MAP_HEIGHT];
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        map[i] = new Territory[MAP_WIDTH];
    }
    setup(map);
    while (!gameOver)
    {
        if (loop())
            gameOver = true;
    }
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        delete[] * (map + i);
    }
    delete[] map;
    std::cout << "Game Over!" << std::endl;
    std::cin;
    return 0;
}