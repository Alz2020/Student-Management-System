// header guard
#ifndef SYSTEM_HPP
#define SYSTEM_HPP

// class
class Person
{
protected:
    std::string name;
    int age;
    public:
    // constructor
    Person(std::string &name, int age);
    // pure function 
    virtual void displayInfo() = 0;
    // destructor
    virtual ~Person() = default;

    
};

#endif