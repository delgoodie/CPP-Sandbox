#include <iostream>

int main()
{
    int testCount, length, queries;
    std::cin >> testCount;
    std::cin >> length;
    std::cin >> queries;
    int nums[length];
    for (int test = 0; test < testCount; test++)
    {
        for (int i = 0; i < length; i++)
            nums[i] = i;

        bool sorted = 0;
        while (!sorted)
        {
            sorted = 1;
            for (int i = 0; i < length - 2; i++)
            {
                int med;
                std::cout << nums[i] + 1 << " " << nums[i + 1] + 1 << " " << nums[i + 2] + 1 << std::endl;
                std::cin >> med;
                if (med != i + 1)
                {
                    sorted = 0;
                    int temp = nums[med];
                    nums[med] = nums[i + 1];
                    nums[i + 1] = temp;
                }
            }
        }
        for (int i = 0; i < length; i++)
            std::cout << nums[i] << " ";
        std::cout << std::endl;
    }
    return 0;
}