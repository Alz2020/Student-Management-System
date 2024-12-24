#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <sstream>

// base class person
class Person {
protected:
    int IDNumber;
    std::string name;

public:
    Person(int id = 0, const std::string& name = "") : IDNumber(id), name(name) {}

    //getter and setter for id number
    int getIDNumber() const { return IDNumber; }
    void setIDNumber(int id) { IDNumber = id; }

    //getter and setter for name
    const std::string& getName() const {return name; }
    void setName(const std::string& newName) {name = newName; }

    //virtual function for displaying information
    virtual void displayInfo() const {
        std::cout <<std::left <<std::setw(12) <<IDNumber << std::setw(20) << name;
    }
    // virtual destructor 
    virtual ~Person() = default;
};



// derived class : student
class Student : public Person {
private:
    float marks;
public:
    Student(int id =0, const std::string& name="", float marks =0.0f)
    : Person(id, name), marks(marks) {}
    // getter and setter for marks
float getMarks() const { return marks; }
void setMarks(float newMarks) { marks = newMarks; }
// override displayInfo to include marks
void displayInfo() const override {
    Person::displayInfo();
    std::cout << std::setw(10) << marks << std
    }
};

// function for file handling 

void saveToFile(const std::vector<std::unique_ptr<Student>>& students, const std::string& filename);
// load from file 
void loadFromFile(std::vector<std::unique_ptr<Student>>& students, const std::string& filename);




#endif // !STUDENT_HPP

