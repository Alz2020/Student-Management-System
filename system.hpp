// header guard
#ifndef SYSTEM_HPP
#define SYSTEM_HPP
#include <string>
#include<vector>
#include <memory>
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
    ~Student() = default;  
};

// class for representing a course
class Course {
    private:
    std::string courseName;
    int courseID;
    public:
    // constructor
    Course(const std::string &courseName, int courseID);
    //getter 
    int getID() const;

    // display course info
    void displayInfo() const;
    ~Course() = default;
};

// management system class
class ManagementSystem {
    private:
    std::vector<std::unique_ptr<Student>> student;
    std::vector<std::unique_ptr<Course>> course;
    public:
    // a new student
    void addStudent(const std::string &name, int age, int studnet);
    // a new course
    void addCourse(const std::string &courseName, int courseID);

    //display students
    void displaystudents()const;
    //display courses
    void displaycourses()const;
    
    //retrieve a student by id 
    Student* getStudentById(int studentID);
    ~ManagementSystem() = default;

};


#endif