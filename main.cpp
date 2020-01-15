#include <iostream>
#include <cstdio>

const int mapHeight = 5;
const int mapWidth = 5;

void setup(char map[mapHeight][mapWidth], bool gameOver)
{
}

class Territory
{
public:
    bool occupies(int x, int y);

private:
    const int num = rand();
    int map[10][2];

    int **generateMap(int size)
    {
        int **map = 0;
        *map = new int[size];
        for (int i = 0; i < size; i++)
        {
            map[i] = new int[2];
            std::cout << sizeof(map) / sizeof(map[i]);
            for (int j = 0; j < sizeof(map) / sizeof(map[i]); j++)
            {
                map[i][j] = rand();
            }
        }

        return map;
    }
};

void print2dIntegerArray(int **array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size / sizeof(array[i]); j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int **generateMap(int size)
{
    int **map = 0;
    map = new int *[size];
    for (int i = 0; i < size; i++)
    {
        map[i] = new int[2];
        for (int j = 0; j < 2; j++)
        {
            map[i][j] = rand();
        }
    }

    return map;
}

void printMap(const char map[mapHeight][mapWidth])
{
    for (int i = 0; i < mapHeight; i++)
    {
        for (int j = 0; j < mapWidth; j++)
        {
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }
}

void loop()
{
}

int main()
{
    char map[mapHeight][mapWidth];
    bool gameOver;

    print2dIntegerArray(generateMap(4), 4);

    setup(map, gameOver);

    printMap(map);

    while (!gameOver)
    {
        loop();
    }
    std::cout << "Game Over!" << std::endl;
    std::cin;
    return 0;
}