#include <iostream>
#include <cstdio>
#include <math.h>
#include <string>
#include "infection.h"
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = nullptr;
    }
    ListNode(int v)
    {
        val = v;
        next = nullptr;
    }
    ListNode(int v, ListNode *n)
    {
        val = v;
        next = n;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists)
    {
        std::vector<ListNode> result = {ListNode()};
        ListNode newNode;
        bool end = 0;
        while (!end)
        {
            int mindex = 0;
            for (int i = 0; i < lists.size(); i++)
            {
                if (!lists[i])
                    continue;
                ListNode l = *lists[i];
                if (!lists[mindex] || lists[i]->val < lists[mindex]->val)
                    mindex = i;
            }

            if (!lists[mindex])
            {
                end = 1;
                result.back().next = nullptr;
            }
            else
            {
                result.push_back(ListNode(lists[mindex]->val));

                if (result.size() > 1)
                {
                    result[result.size() - 2].next = &(result.back());
                }
                lists[mindex] = lists[mindex]->next;
            }
        }

        return &result[0];
    }
};

int main()
{
    // std::vector<std::vector<ListNode>> inputNodes = {{ListNode(1), ListNode(4), ListNode(5)}, {ListNode(1), ListNode(3), ListNode(4)}, {ListNode(2), ListNode(6)}};
    // for (int i = 0; i < inputNodes.size(); i++)
    // {
    //     for (int j = 0; j < inputNodes[i].size() - 1; j++)
    //     {
    //         inputNodes[i][j].next = &inputNodes[i][j + 1];
    //     }
    // }

    // std::cout << "INPUT" << std::endl;
    // for (int i = 0; i < inputNodes.size(); i++)
    // {
    //     ListNode *n = &inputNodes[i][0];
    //     while (n)
    //     {
    //         std::cout << n->val << "  " << std::endl;
    //         n = n->next;
    //     }
    // }

    // std::vector<ListNode *> input;
    // for (int i = 0; i < inputNodes.size(); i++)
    //     input.push_back(&inputNodes[i][0]);

    // std::cout << "OUTPUT" << std::endl;

    // Solution s = Solution();
    // ListNode *n = s.mergeKLists(input);
    // while (n)
    // {
    //     std::cout << n->val << std::endl;
    //     n = n->next;
    // }

    void *ptr = malloc(sizeof(int));
    *((int *)ptr) = 5;
    std::cout << *((int *)ptr) << std::endl;
    free(ptr);
    std::cout << *((int *)ptr) << std::endl;

    std::cout << "press any key to exit" << std::endl;
    std::cin.ignore();
    return 0;
}