#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector>
#include <fstream>

// define a structure to store student details
struct Student {
    int IDNumber;
    std::string name;
    float marks;
};
// function declarations
void displayMenu();
void addStudent(std::vector<Student>& students);
void editStudent(std::vector<Student>& students);
void searchStudent(const std::vector<Student>& students);
void showAllStudents(const std::vector<Student>& students);
void saveToFile(const std::vector<Student>& students, const std::string& filename){
    std::ofstream file(filename, std::ios::out);
    if(file.is_open()){
        for(const auto& student : students){
            file << student.IDNumber << "," << student.name << "," << student.marks << "\n";
        }
        file.close();
        std::cout << "\033[1;32mData saved successfully!\033[0m\n";
    } else {
        std::cout << "\033[1;31mUnable to save data!\033[0m\n";
    }
}


#endif // !STUDENT_HPP

