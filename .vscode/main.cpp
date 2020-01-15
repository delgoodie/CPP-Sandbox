#include <iostream>
const int mapHeight = 5;
const int mapWidth = 5;
void setup(char map[mapHeight][mapWidth], bool gameOver)
{
    
}

class Territory{
    public:
        bool occupies(int x, int y);
    private:
        int map[0][0];
};

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