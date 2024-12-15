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

// add a new student in management system
void ManagementSystem::addStudent(const std::string &name, int age, int studentID) {
    students.push_back(std::make_unique<Student>(name, age, studentID));

}

// display all courses in management system
void ManagementSystem::displayCourses() const {
    for (const auto &course: courses) {
        course->displayInfo();
    }
}
// display all students in management system
void ManagementSystem::displayStudents() const {
    for (const auto &student: students) {
        student->displayInfo();
    }
}

//get a student by ID in managment system class
Student* ManagementSystem::getStudentByID( int studentID) {
    Student *student = findByID(students, studentID);
    if (!student) {
        throw std::runtime_error("Student ID not found");
    }
    return student;
}