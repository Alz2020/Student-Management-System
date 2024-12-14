#include "ManagementSystem.hpp"
#include <iostream>

// person class constructor
Person::Person(const std::string &name, int age) : name(name), age(age) {}

// student class constructor
Student::Student(const std::string &name, int age, int studentID)
    : Person(name, age), studentID(studentID) {}

int Student::getID() const
{
    return studentID;
}

void Student::addGrade(const std::string &course, double grade)
{
    grades.emplace_back(course, grade);
}

void Student::displayInfo() const
{
    std::cout << "Student ID:" << studentID << "\nName:" << name
            << "\nAge:" << age << "\nGrades:\n";
    for (const auto &grade : grades)
    {
        std::cout << "Course:" << grade.first << " -Grade: " << grade.second << '\n';
    }
}
// course class constructor
Course::Course(const std::string &courseName, int courseID)
    : courseName(courseName), courseID(courseID) {}
int Course::getID() const
{
    return courseID;
}
void Course::displayInfo() const {
    std::cout << "Course ID:" << courseID << "\nCourse Name:" << courseName << '\n';

}
// add a new course in management system
void ManagementSystem::addCourse(const std::string &courseName, int courseID) {
    courses.push_back(std::make_unique<Course>(courseName, courseID));
}
