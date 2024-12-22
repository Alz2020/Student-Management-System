#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector>

// define a structure to store student details
struct Student {
    int IDNumber;
    std::string Name;
    float marks;
};
// function declarations
void displayMenu();
void addStudent(std::vector<Student>& students);
void editStudent(std::vector<Student>& students);
void searchStudent(const std::vector<Student>& students);
void showAllStudent(const std::vector<Student>& students)



#endif // !STUDENT_HPP

