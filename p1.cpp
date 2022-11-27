#include <iostream>

int main()
{
    int testCount;
    std::cin >> testCount;
    for (int test = 0; test < testCount; test++)
    {
        int ops = 0;
        int n = 0;
        std::cin >> n;
        int nums[n];
        for (int i = 0; i < n; i++)
            std::cin >> nums[i];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] <= nums[i - 1])
            {
                while (nums[i] + 10 <= nums[i - 1])
                {
                    nums[i] *= 10;
                    ops++;
                }
                if (nums[i] <= nums[i - 1])
                {
                    nums[i] += nums[i - 1] - nums[i] + 1;
                    ops++;
                }
            }
        }
        std::cout << "Case #" << test + 1 << ": " << ops << std::endl;
    }
    return 0;
}