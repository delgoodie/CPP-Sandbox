#include <iostream>
#include <string>

class Person
{
public:
    short weight, age;
    std::string name;
    Person(std::string _name, short _age, short _weight)
    {
        name = _name;
        age = _age;
        weight = _weight;
    }
};

int main()
{
    Person g("will", 17, 145);
    std::cout << g.name << " is " << std::to_string(g.age) << " years old and weighs " << g.weight << " pounds" << std::endl;
    std::cin;
    return 0;
}