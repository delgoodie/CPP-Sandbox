#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<int>> pCn_or(std::vector<int> p, int n, std::vector<int> l)
{
    std::vector<std::vector<int>> result = {};
    for (int i = 0; i < p.size(); i++)
    {
        std::vector<int> n_p = p;
        std::vector<int> n_l = l;
        n_l.push_back(n_p[i]);
        n_p.erase(n_p.begin() + i);
        if (n > 1)
        {
            std::vector<std::vector<int>> it = pCn_or(n_p, n - 1, n_l);
            result.insert(result.end(), it.begin(), it.end());
        }
        else
            result.push_back(n_l);
    }
    return result;
}

std::vector<std::vector<int>> pCn_uo(std::vector<int> p, int n, std::vector<int> l)
{
    if (p.size() == n)
        return std::vector<std::vector<int>>{p};
    std::vector<std::vector<int>> result = {};
    for (int i = 0; i < p.size(); i++)
    {
        std::vector<int> n_l = l;
        n_l.push_back(p[i]);
        std::vector<int> n_p(p.begin() + i + 1, p.end());
        if (n > 1)
        {
            std::vector<std::vector<int>> it = pCn_or(n_p, n - 1, n_l);
            result.insert(result.end(), it.begin(), it.end());
        }
        else
            result.push_back(n_l);
    }
    return result;
}

std::vector<std::vector<int>> permute(int n)
{
    std::vector<int> p = {};
    for (int i = 0; i < n; i++)
        p.push_back(i);
    return pCn_or(p, n, std::vector<int>{});
}

int main()
{
    // std::vector<std::vector<int>> combos = pCn_or(std::vector<int>{1, 2, 3, 4}, 2, std::vector<int>{});
    std::vector<std::vector<int>> combos = pCn_uo(std::vector<int>{1, 2, 3, 4}, 4, std::vector<int>{});
    // std::vector<std::vector<int>> combos = permute(3);
    for (int i = 0; i < combos.size(); i++)
    {
        for (int j = 0; j < combos[i].size(); j++)
            std::cout << combos[i][j] << " ";
        std::cout << std::endl;
    }
}
