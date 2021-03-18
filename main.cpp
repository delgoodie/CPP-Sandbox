#include <iostream>
#include <cstdio>
#include <math.h>
#include <string>
#include "infection.h"

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

int main()
{
    ListNode g = ListNode();
    std::cout << g.val << std::endl;
    std::cin.ignore();
    return 0;
}