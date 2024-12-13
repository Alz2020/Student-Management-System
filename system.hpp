// header guard
#ifndef SYSTEM_HPP
#define SYSTEM_HPP
#include <string>
#include<vector>
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
    virtual void displayInfo() const= 0;
    // destructor
    virtual ~Person() = default;
};

// derived  class for student
class Student : public Person {
    private:
    int studentID;
    // vector 
    std::vector<std::pair<std::string, double>> grades;
    public:
    //constructor
    Student(const std::string &name, int age, int studentID);
    // getter for ID 
    int getID() const;
    // add a grade for each course 
    void addGrade(const std::string &course, double grade);
    // override display info to show student details
    void displayInfo() const override;
    // destructor
    ¬Student() = default;
    
};

#endif