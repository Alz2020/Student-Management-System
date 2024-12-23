#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <memory>
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
    //update menu options with file 
    std::cout << "6 - Save to file\n";
    std::cout << "7 - Load from file\n";
    std::cout <<"\033[0m";
    std::cout << "Enter your choice: ";
}
// function to add student 
void addStudent(std::vector<std::unique_ptr<Student>>& students){
    auto newStudent = std::make_unique<Student>();
    std::cout << "Enter ID number:";
    std::cin >> newStudent->IDNumber;
    std::cin.ignore(); // clear the input buffer

    std::cout << "Enter name:";
    std::getline(std::cin, newStudent->name);

    std::cout <<"Enter marks: ";
    std::cin >> newStudent->marks;

    students.push_back(std::move(newStudent)); 
    std::cout << "\033[1;32mStudent added successfully!\033[0m\n";
}

// create function to edit an existing student 
void editStudent(std::vector<std::unique_ptr<Student>>& students) {
    int IDNumber;
    std::cout << "Enter the ID number of the student to edit:";
    std::cin >> IDNumber;

    for (auto& student : students){
        if (student->IDNumber == IDNumber){
            std::cout << "Enter new name:";
            std::cin.ignore(); // to clear buffer before accepting new name
            std::getline(std::cin, student->name);

            std::cout <<"Enter new marks:";
            std::cin >> student->marks;
            std::cout << "\033[1;32mStudent record update successfully!\033[0m\n";
            return;
        }
    }
    std::cout << "\033[1;31mNo student found with the given ID number.\033[0m\n";
}
// function to search for a student
void searchStudent(std::vector<std::unique_ptr<Student>>& students) {
    int IDNumber;
    std::cout << "Enter the ID number of the student to search ";
    std::cin >> IDNumber;
    for (const auto& student : students){
        if (student->IDNumber == IDNumber){
            std::cout << "\nStudent Details:\n";
            std::cout << "ID Number: " << student->IDNumber << "\n";
            std::cout << "Name: " << student->name << "\n";
            std::cout << "Marks: " << student->marks << "\n";
            return;
        }
    }
    std::cout << "\033[1;31mNo student found with the given ID number.\033[0m\n";
}
// function to display all students
void showAllStudents(const std::vector<std::unique_ptr<Student>>& students) {
    if (students.empty()) { // to check if there are no student to display
    std::cout << "\033[1;31mNo student to display.\033[0m\n";
    return;
}

std::cout << "\n\033[1;36mAll Students:\033[0m\n";
std::cout << std::left << std::setw(12) << "ID number"
        << std::setw(20) << "Name"
        << std::setw(10) << "Marks" << "\n";

for (const auto& student : students) {
    std::cout << std::left << std::setw(12) << student->IDNumber
    << std::setw(20) << student->name
    << std::setw(10) << student->marks << "\n";
    }
}


int main() {
    std::vector<std::unique_ptr<Student>> students; 
    int choice;
    do{
        displayMenu();
        std::cin >> choice;
        switch (choice) {
        case 1:
            addStudent(students);
            break;
        case 2:
            editStudent(students);
            break;
        case 3:
            searchStudent(students);
            break;
        case 4:
            showAllStudents(students);
            break;
        case 5 :
            std::cout << "\033[1;32mExiting \033[0m\n";
            break;
        case 6:
            saveToFile(students, "students.txt");
            break;
        case 7:
            loadFromFile(students, "students.txt");
            break;
        default:
            std::cout << "\033[1;31mInvalid choice. Please try again.\033[0m\n";
        }
    }  while (choice != 5);
    return 0;
}