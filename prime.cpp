#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<int>> pCn_uo(std::vector<int> p, int n, std::vector<int> l)
{
    std::vector<std::vector<int>> result = {};
    for (int i = 0; i < p.size(); i++)
    {
        std::vector<int> n_l = l;
        n_l.push_back(p[i]);
        std::vector<int> n_p(p.begin() + i + 1, p.end());
        if (n > 1)
        {
            std::vector<std::vector<int>> it = pCn_uo(n_p, n - 1, n_l);
            result.insert(result.end(), it.begin(), it.end());
        }
        else
            result.push_back(n_l);
    }
    return result;
}

int solve(std::vector<int> primes)
{
    int sum = 0;
    for (int i = 0; i < primes.size(); i++)
        sum += primes[i];

    for (int i = primes.size() - 1; i > 0; i--)
    {
        std::vector<std::vector<int>> combos = pCn_uo(primes, i, std::vector<int>{});
        for (int j = combos.size() - 1; j >= 0; j--)
        {
            int p = 1;
            int s = sum;
            for (int q = 0; q < combos[j].size(); q++)
            {
                p *= combos[j][q];
                s -= combos[j][q];
            }
            if (p == s)
                return p;
        }
    }
    return 0;
}

int main()
{
    int testCount;
    std::cin >> testCount;
    for (int test = 0; test < testCount; test++)
    {
        int m;
        std::cin >> m;
        std::vector<int> p = {};
        for (int i = 0; i < m; i++)
        {
            int n, prime;
            std::cin >> prime;
            std::cin >> n;
            for (int j = 0; j < n; j++)
                p.push_back(prime);
        }
        std::cout << "Case #" << test + 1 << ": " << solve(p) << std::endl;
    }
    return 0;
}