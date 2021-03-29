#include <iostream>
#include <cmath>

int main()
{
    int testCount, pCorrect;
    std::cin >> testCount;
    std::cin >> pCorrect;
    bool players[100][1000];
    float qSkill[1000];
    float pSkill[100];
    for (int test = 0; test < testCount; test++)
    {
        for (int i = 0; i < 100; i++)
        {
            std::string questions;
            std::cin >> questions;
            for (int j = 0; j < 1000; j++)
            {
                if (questions[j] == '1')
                    players[i][j] = 1;
                else
                    players[i][j] = 0;
            }
        }

        for (int i = 0; i < 1000; i++)
        {
            qSkill[i] = 3.0f;
            for (int j = 0; j < 100; j++)
                qSkill[i] -= players[j][i] * 0.01f;
        }

        for (int i = 0; i < 100; i++)
        {
            pSkill[i] = 0.0f;
            for (int j = 0; j < 1000; j++)
            {
                if (players[i][j])
                    pSkill[i] += qSkill[j];
                else
                    pSkill[i] -= 1 - qSkill[j];
            }
        }

        float maxErr = 0.0f;
        int maxdex = 0;
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 1000; j++)
            {
                float prob = 1 / (1 + std::exp(qSkill[j] - pSkill[i]));
            }
        }

        std::cout << "Case #" << test + 1 << ": " << 0 << std::endl;
    }
    return 0;
}