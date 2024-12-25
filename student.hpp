#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <stdexcept>

// base class person  template
template <typename T>
class Person {
protected:
    T IDNumber;
    std::string name;

public:
    Person(T id = T(), const std::string& name = "") : IDNumber(id), name(name) {}

    //getter and setter for id number
    T getIDNumber() const { return IDNumber; }
    void setIDNumber(const T& id) { IDNumber = id; }

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
template <typename T>
class Student : public Person<T> {
private:
    float marks;
public:
    Student(T id = T(), const std::string& name="", float marks =0.0f)
        : Person<T>(id, name), marks(marks) {}
    // getter and setter for marks
float getMarks() const { return marks; }
void setMarks(float newMarks) { 
    if (newMarks <0 || newMarks > 100)
    throw std::invalid_argument(" Marks must be between 0 and 100.");
    marks = newMarks; 
 }
// override displayInfo to include marks
void displayInfo() const override {
    Person<T>::displayInfo();
    std::cout << std::setw(10) << marks << "\n";
    }
};

// function declarations 
template <typename T>
void saveToFile(const std::vector<std::unique_ptr<Student<T>>>& students, const std::string& filename);
// load from file 
template <typename T>
void loadFromFile(std::vector<std::unique_ptr<Student<T>>>& students, const std::string& filename);




#endif // !STUDENT_HPP

