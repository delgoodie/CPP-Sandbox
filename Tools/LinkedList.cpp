#include <iostream>
#include <string>
#include <vector>
#include <chrono>

struct Link
{
    int *value;
    Link *next;
    Link()
    {
        value = nullptr;
        next = nullptr;
    }
    Link(int *v)
    {
        value = v;
        next = nullptr;
    }
    Link(int *v, Link *n)
    {
        value = v;
        next = n;
    }
    ~Link()
    {
        delete value;
    }
};

class List
{
public:
    int length;

    List()
    {
        begin = nullptr;
        end = nullptr;
        length = 0;
    }

    List(int n)
    {
        begin = new Link(new int(0));
        length = n;
        Link *i = begin, *j = i;
        while (n > 1)
        {
            i = new Link(new int(0));
            j->next = i;
            j = i;
            n--;
        }
        end = i;
    }

    int at(int index)
    {
        if (index >= length || index < 0)
        {
            std::cout << "ERROR index out of bounds" << std::endl;
            return -1;
        }
        Link *i = begin;
        for (int j = 0; j < index; j++)
            if (i)
                i = i->next;
            else
            {
                std::cout << "ERROR Linked List Corrupted" << std::endl;
                return -1;
            }
        return *(i->value);
    }

    void at(int index, int value)
    {
        if (index >= length || index < 0)
        {
            std::cout << "ERROR index out of bounds" << std::endl;
            return;
        }
        Link *i = begin;
        for (int j = 0; j < index; j++)
            if (i)
                i = i->next;
            else
            {
                std::cout << "ERROR Linked List Corrupted" << std::endl;
                return;
            }
        i->value = new int(value);
    }

    int back()
    {
        return *(end->value);
    }

    void add(int value)
    {
        end->next = new Link(new int(value));
        end = end->next;
        length++;
    }

    int remove(int index)
    {
        if (index >= length || index < 0)
        {
            std::cout << "ERROR index out of bounds" << std::endl;
            return -1;
        }
        Link *i = begin, *l = i;
        for (int j = 0; j < index; j++)
            if (i)
            {
                l = i;
                i = i->next;
            }
            else
            {
                std::cout << "ERROR Linked List Corrupted" << std::endl;
                return -1;
            }
        if (index == length - 1)
        {
            l->next = nullptr;
            end = l;
        }
        else
            l->next = i->next;

        int result = *i->value;
        delete i;
        length--;
        return result;
    }

    ~List()
    {
        if (length == 0)
            return;
        Link *i = begin, *j;
        while (i)
        {
            j = i->next;
            delete i;
            i = j;
        }
    }

private:
    Link *begin;
    Link *end;
};

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    for (int t = 0; t < 100000; t++)
    {
        List l(10);
        for (int i = 0; i < 10; i++)
            l.at(i, i);
    }
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << duration.count() << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    for (int t = 0; t < 100000; t++)
    {
        std::vector<std::string> v(10);
        for (int i = 0; i < 10; i++)
            v[i] = std::string{"1010"};
    }
    auto stop2 = std::chrono::high_resolution_clock::now();

    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);

    std::cout << duration2.count() << std::endl;

    // std::cin.ignore();
    return 0;
}