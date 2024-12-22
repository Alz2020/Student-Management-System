#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "student.hpp"

// function to display the main menu
void displayMenu() {
    std::cout <<"\033[1;36m";
    std::cout <<"\n*******************************************\n";
    std::cout <<"*          Student Management System       *\n";
    std::cout <<"\n*******************************************\n";
    std::cout <<"\033[0m";

    std::cout <<"\033[1;32m";
    std::cout <<"1 - Add Student\n";
    std::cout <<"2 - Edit Student\n";
    std::cout <<"3 - Search Student\n";
    std::cout <<"4 - Show All Student\n";
    std::cout <<"5 - Quit program\n";
    std::cout <<"\033[0m";
    std::cout << "Enter your choice: ";
}
// function to add student with pointer 
void addStudent(std::vector<Student>& students){
    Student newStudent;
    std::cout << "Enter ID number:";
    std::cin >> newStudent.IDNumber;
    std::cin.ignore(); // clear the input buffer

    std::cout << "Enter name:";
    std::getline(std::cin, newStudent.name);

    std::cout <<"Enter marks: ";
    std::cin >> newStudent.marks;

    students.push_back(newStudent); // add the new student to the vector
    std::cout << "\033[1;32mStudent added successfully!\033[0m\n";
}