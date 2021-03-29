#include <iostream>

int costFunc(int numsOriginal[], int count)
{
    int nums[count];
    for (int i = 0; i < count; i++)
        nums[i] = numsOriginal[i];
    int c = 0;
    for (int i = 0; i < count; i++)
    {
        int min = i;
        for (int j = i; j < count; j++)
        {
            if (nums[j] < nums[min])
                min = j;
        }
        c += min - i + 1;
        for (int q = i, p = min; q < p; q++, p--)
        {
            int temp = nums[q];
            nums[q] = nums[p];
            nums[p] = temp;
        }
    }
    return c - 1;
}

int main()
{
    int testCount;
    std::cin >> testCount;
    for (int test = 0; test < testCount; test++)
    {
        int count, cost;
        std::cin >> count;
        std::cin >> cost;
        int nums[count];
        for (int i = 0; i < count; i++)
            nums[i] = i;
        int it = 0;
        while (costFunc(nums, count) != cost && it < 500000)
        {
            int i1 = rand() % count;
            int i2 = rand() % count;
            int temp = nums[i1];
            nums[i1] = nums[i2];
            nums[i2] = temp;
            it++;
        }
        std::cout << "Case #" << test + 1 << ": ";
        if (it == 500000)
            std::cout << "IMPOSSIBLE";
        else
            for (int i = 0; i < count; i++)
                std::cout << nums[i] + 1 << " ";
        std::cout << std::endl;
    }
    return 0;
}