#include <iostream>

int main()
{
    int testCount;
    std::cin >> testCount;
    for (int test = 0; test < testCount; test++)
    {
        std::string input;
        int x, y;
        bool xGreater = 0;
        std::cin >> x;
        std::cin >> y;
        std::cin >> input;
        xGreater = x > y;
        char last = '!';
        for (int i = 0; i < input.length(); i++)
        {
            if (input.at(i) == '?')
            {
                char local = last;
                if (i < input.length() - 2)
                {
                    for (int j = 0; j < input.length(); j++)
                    {
                        if (input.at(j) == 'C')
                        {
                            if (local == '!')
                                local = 'C';
                            else if (local == 'J')
                            {
                                if (xGreater)
                                    local = 'J';
                            }
                            break;
                        }
                        else if (input.at(j) == 'J')
                        {
                            if (local == '!')
                                local = 'J';
                            else if (local == 'C')
                            {
                                if (!xGreater)
                                    local = 'C';
                            }
                            break;
                        }
                    }
                }
                input[i] = local;
            }
            last = input.at(i);
        }

        int min = 0;
        for (int i = 0; i < input.length() - 1; i++)
        {
            if (input.at(i) == 'J' && input.at(i + 1) == 'C')
                min += y;
            else if (input.at(i) == 'C' && input.at(i + 1) == 'J')
                min += x;
        }
        // std::cout << input << std::endl;
        std::cout << "Case #" << test << ": " << min << std::endl;
    }
    return 0;
}