#include <iostream>
#include <string>
#include <vector>

struct Link
{
    void *val;
    Link *next;
    Link()
    {
        val = nullptr;
        next = nullptr;
    }
    Link(void *v)
    {
        val = v;
        next = nullptr;
    }
    Link(void *v, Link *n)
    {
        val = v;
        next = n;
    }
};

class List
{
public:
    List()
    {
        begin = nullptr;
    }

    List(int n)
    {
        begin = new Link(0);
        Link *i = begin, *j = i;
        while (n > 1)
        {
            i = new Link(0);
            j->next = i;
            j = i;
            n--;
        }
    }

    int at(int index)
    {
        Link *i = begin;
        for (int j = 0; j < index; j++)
            if (i)
                i = i->next;
            else
            {
                std::cout << "ERROR index out of bounds" << std::endl;
                return -1;
            }
        return *((int *)i->val);
    }

    int length()
    {
        int l = 1;
        Link *i = begin;
        while (i)
        {
            i = i->next;
            l++;
        }
        return l;
    }

    List Add(int value)
    {
        return *this;
    }

private:
    Link *begin;
};

main()
{
    for (int i = 0; i < 10; i++)
    {
    }
}