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

// create function to edit an existing student 
void editStudent(std::vector<Student>& students){
    int IDNumber;
    std::cout << "Enter the ID number of the student to edit:";
    std::cin >> IDNumber;

    for (auto& student : students){
        if (student.IDNumber == IDNumber){
            std::cout << "Enter new name:";
            std::cin.ignore(); // to clear buffer before accepting new name
            std::getline(std::cin, student.name);

            std::cout <<"Enter new marks:";
            std::cin >> student.marks;
            std::cout << "\033[1;32mStudent record update successfully!\033[0m\n";
            return;
        }
    }
    std::cout << "\033[1;31mNo student found with the given ID number.\033[0m\n";
}
// function to search for a student
void searchStudent(std::vector<Student>& students){
    int IDNumber;
    std::cout << "Enter the ID number of the student to search ";
    std::cin >> IDNumber;
    for (const auto& student : students){
        if (student.IDNumber == IDNumber){
            std::cout << "\nStudent Details:\n";
            std::cout << "ID Number: " << student.IDNumber << "\n";
            std::cout << "Name: " << student.name << "\n";
            std::cout << "Marks: " << student.marks << "\n";
            return;
        }
    }
    std::cout << "\033[1;31mNo student found with the given ID number.\033[0m\n";
}