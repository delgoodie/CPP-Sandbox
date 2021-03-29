#include <iostream>

int main()
{
    int testCount;
    std::cin >> testCount;
    for (int test = 0; test < testCount; test++)
    {
        int count;
        std::cin >> count;
        int nums[count];
        for (int i = 0; i < count; i++)
        {
            std::cin >> nums[i];
        }
        int cost = 0;
        for (int i = 0; i < count; i++)
        {
            int min = i;
            for (int j = i; j < count; j++)
            {
                if (nums[j] < nums[min])
                    min = j;
            }
            cost += min - i + 1;
            for (int q = i, p = min; q < p; q++, p--)
            {
                int temp = nums[q];
                nums[q] = nums[p];
                nums[p] = temp;
            }
        }
        std::cout << "Case #" << test + 1 << ": " << cost - 1 << std::endl;
    }
    return 0;
}