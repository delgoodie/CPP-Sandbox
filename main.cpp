#include <iostream>
#include <cstdio>
#include <math.h>
#include <string>

const int MAP_HEIGHT = 10;           //The height of the map -- map.length
const int MAP_WIDTH = 20;            //The width of the map -- map[0].length
const int MAP_TERRITORY_SIZE = 40;   //The max number of healthy spaces that can randomly spawn
const int CURE_DIFFICULTY = 100;     //Higher CURE_DIFFICULTY decreases the chances that HEALTHY Territories will cure INFECTED Territories
const int INFECTION_DIFFICULTY = 100; //Higher INFECTION_DIFFICULTY decreases the chances that INFECTED Territories will infect HEALTHY Territories
const int REVIVAL_DIFFICULTY = 200;  //Higher REVIVAL_DIFFICULTY decreases the chances that a DEAD or EMPTY Territory will become a HEALTHY Territory
const int INITIAL_CURE = 5;          // The inital value of the cure
const int INITIAL_INFECTION = 5;     // The initial value of the infection

enum Territory //Each space of the map is a Territory enum representing its status
{
    EMPTY,
    HEALTHY,
    INFECTED,
    DEAD
};

void printMap(Territory **, int, int);      //prints the map to the console in battleship format -- rows alphabetically assigned, columns numerically assigned
int randInt(int);                           //generates a random integer between zero and specified argument
void setup(Territory **);                   //sets up map and prompts user for infection starting point
bool loop(Territory **, int *, int *);      //main game loop, calls all update funtions and returns true on game end
bool updateMap(Territory **, int *, int *); //determines game logic for each territory
int endCheck(Territory **map);              // -1 = LOSS, 1 = WIN, 0 = NO END

int randInt(int max)
{
    return (int)(((double)rand() / (double)RAND_MAX) * max);
}

void printMap(Territory **map, int cure, int infection)
{
    std::cout << "MAP:" << std::endl
              << "   ";
    for (int i = 0; i < MAP_WIDTH; i++)
        std::cout << (char)(i + 65) << " ";
    std::cout << std::endl;
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        if (i < 9)
            std::cout << i + 1 << "  ";
        else
            std::cout << i + 1 << " ";
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
    std::cout << "INFECTION: |";
    for (float i = 0.0; i < INFECTION_DIFFICULTY; i += INFECTION_DIFFICULTY / 10)
    {
        if (infection > i)
            std::cout << "#";
        else
            std::cout << " ";
    }
    std::cout << "|\tCURE: |";
    for (float i = 0.0; i < CURE_DIFFICULTY; i += CURE_DIFFICULTY / 10)
    {
        if (cure > i)
            std::cout << "#";
        else
            std::cout << " ";
    }
    std::cout << "|" << std::endl;
}

int endCheck(Territory **map)
{
    bool dead = false;
    bool healthy = false;
    bool infected = false;
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            if (healthy && infected)
                return 0;
            else if (*(*(map + i) + j) == DEAD)
                dead = true;
            else if (*(*(map + i) + j) == INFECTED)
                infected = true;
            else if (*(*(map + i) + j) == HEALTHY)
                healthy = true;
        }
    }
    if (!infected && healthy)
        return -1;
    else if (dead && !infected && !healthy)
        return 1;
    else
        return 0;
}

void setup(Territory **map)
{
    std::cout << std::endl;
    std::cout << "\t|    |\\    |    +------    +------    +-------    -----+-----    |      ====      |\\    |" << std::endl;
    std::cout << "\t|    | \\   |    |          |          |                |         |    //    \\\\    | \\   |" << std::endl;
    std::cout << "\t|    |  \\  |    +----      +----      |                |         |   ||      ||   |  \\  |" << std::endl;
    std::cout << "\t|    |   \\ |    |          |          |                |         |    \\\\    //    |   \\ |" << std::endl;
    std::cout << "\t|    |    \\|    |          +------    +-------         |         |      ====      |    \\|" << std::endl;
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
    printMap(map, 0, 0);
    bool validStart = false;
    while (!validStart)
    {
        char ret[5];
        int y;
        int x;

        std::cout << "Enter the starting coordinates: [A-" << (char)(MAP_WIDTH + 64) << ", 0-" << MAP_HEIGHT << "]" << std::endl;
        std::cin >> ret >> y;

        x = ret[0];
        if (x >= 65 && x <= 90)
            x -= 65;
        else if (x >= 97 && x <= 122)
            x -= 97;
        else
        {
            std::cout << "Invalid X input! Must be [A-" << (char)(MAP_WIDTH + 64) << ", 0-" << MAP_HEIGHT << "]" << std::endl;
        }
        y -= 1;
        if (y < 0 || y > 100)
        {
            std::cout << "Invalid Y input! Must be [A-" << (char)(MAP_WIDTH + 64) << ", 0-" << MAP_HEIGHT << "]" << std::endl;
            continue;
        }

        if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT)
        {
            if (*(*(map + y) + x) == HEALTHY)
            {
                *(*(map + y) + x) = INFECTED;
                std::cout << "The infection begins!!!" << std::endl;
                validStart = true;
            }
            else
            {
                std::cout << "You chose an empty space! Please choose a healthy space!" << std::endl;
            }
        }
        else
        {
            std::cout << "Invalid input! Must be [A-" << (char)(MAP_WIDTH + 64) << ", 0-" << MAP_HEIGHT << "]" << std::endl;
        }
    }
}

bool updateMap(Territory **map, int *cure, int *infection)
{
    bool ret = false;
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            switch (*(*(map + i) + j))
            {
            case EMPTY: //EMPTY Territories have small chance to spawn into HEALTHY Territories
                if (randInt(REVIVAL_DIFFICULTY) == 67)
                {
                    *(*(map + i) + j) = HEALTHY;
                    ret = true;
                }
                break;
            case HEALTHY: //HEALTHY Territories have chance to cure INFECTED Territories directly above, below, right, or left
                if (randInt(CURE_DIFFICULTY) <= *cure)
                {
                    if (i != 0 && *(*(map + i - 1) + j) == INFECTED)
                    {
                        *(*(map + i - 1) + j) = HEALTHY;
                        *cure += 1;
                        ret = true;
                    }
                    else if (i != MAP_HEIGHT - 1 && *(*(map + i + 1) + j) == INFECTED)
                    {
                        *(*(map + i + 1) + j) = HEALTHY;
                        *cure += 1;
                        ret = true;
                    }
                    else if (j != 0 && *(*(map + i) + j - 1) == INFECTED)
                    {
                        *(*(map + i) + j - 1) = HEALTHY;
                        *cure += 1;
                        ret = true;
                    }
                    else if (j != MAP_WIDTH - 1 && *(*(map + i) + j + 1) == INFECTED)
                    {
                        *(*(map + i) + j + 1) = HEALTHY;
                        *cure += 1;
                        ret = true;
                    }
                }
                break;
            case INFECTED: //INFECTED Territories have chance to infect HEALTHY Territories directly above, below, right, or left
                if (randInt(INFECTION_DIFFICULTY) <= *infection)
                {
                    if (i != 0 && *(*(map + i - 1) + j) == HEALTHY)
                    {
                        *(*(map + i - 1) + j) = INFECTED;
                        *infection += 1;
                        ret = true;
                    }
                    else if (i != MAP_HEIGHT - 1 && *(*(map + i + 1) + j) == HEALTHY)
                    {
                        *(*(map + i + 1) + j) = INFECTED;
                        *infection += 1;
                        ret = true;
                    }
                    else if (j != 0 && *(*(map + i) + j - 1) == HEALTHY)
                    {
                        *(*(map + i) + j - 1) = INFECTED;
                        *infection += 1;
                        ret = true;
                    }
                    else if (j != MAP_WIDTH - 1 && *(*(map + i) + j + 1) == HEALTHY)
                    {
                        *(*(map + i) + j + 1) = INFECTED;
                        *infection += 1;
                        ret = true;
                    }
                }
                if (randInt(50) == 0)
                {
                    *(*(map + i) + j) = DEAD;
                    ret = true;
                }
                break;
            case DEAD: //DEAD Territories have small chance to come back as HEALTHY Territories
                if (randInt(4) == 0)
                {
                    *(*(map + i) + j) = EMPTY;
                    ret = true;
                }
                break;
            }
        }
    }
    return ret;
}

bool loop(Territory **map, int *cure, int *infection)
{
    if (updateMap(map, cure, infection))
    {
        printMap(map, *cure, *infection);
        std::cin.ignore();
    }
    if (endCheck(map) != 0)
        return true;
    return false;
}

int main()
{
    bool gameOver = false;
    Territory **map = new Territory *[MAP_HEIGHT];
    int cure = INITIAL_CURE;
    int infection = INITIAL_INFECTION;
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        map[i] = new Territory[MAP_WIDTH];
    }
    setup(map);
    while (!gameOver)
    {
        if (loop(map, &cure, &infection))
            gameOver = true;
    }
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        delete[] * (map + i);
    }
    delete[] map;
    std::cout << "Game Over!" << std::endl;
    std::cin.ignore();
    return 0;
}