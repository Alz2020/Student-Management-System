#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "student.hpp"

// function to display the main menu
void displayMenu() {
    std::cout <<"\033[1;36m\n*******************************************\n";
    std::cout <<"*          Student Management System       *\n";
    std::cout <<"\n*******************************************\n\033[0m";

    std::cout <<"\033[1;32m1 - Add Student\n2 - Edit Student\n3 - Search Student\n";
    std::cout <<"4 - Show All Student\n5 - Quit program\n6 - Save to file\n7 - Load from file\n";
    std::cout << "\033[0mEnter your choice: ";
}
// function to add student 
void addStudent(std::vector<std::unique_ptr<Student>>& students){
    int id;
    std::string name;
    float marks;

    std::cout << "Enter ID number:";
    std::cin >> id;
    std::cin.ignore(); // clear the input buffer

    std::cout << "Enter name:";
    std::getline(std::cin, name);

    std::cout <<"Enter marks: ";
    std::cin >> marks;

    auto newStudent = std::make_unique<Student>(id, name, marks);
    students.push_back(std::move(newStudent)); 
    std::cout << "\033[1;32mStudent added successfully!\033[0m\n";
}

//  Function to edit an existing student 
void editStudent(std::vector<std::unique_ptr<Student>>& students) {
    int id;
    std::cout << "Enter the ID number of the student to edit:";
    std::cin >> id;

    for (auto& student : students){
        if (student->getIDNumber() == id){
            std::string newName;
            float newMarks;

            std::cout << "Enter new name:";
            std::cin.ignore(); // to clear buffer before accepting new name
            std::getline(std::cin, newName);

            std::cout <<"Enter new marks:";
            std::cin >> newMarks;
            student->setName(newName);
            student->setMarks(newMarks);
            std::cout << "\033[1;32mStudent record update successfully!\033[0m\n";
            return;
        }
    }
    std::cout << "\033[1;31mNo student found with the given ID number.\033[0m\n";
}
// function for search for a student
void searchStudent(std::vector<std::unique_ptr<Student>>& students) {
    int id;
    std::cout << "Enter the ID number of the student to search ";
    std::cin >> id;
    for (const auto& student : students){
        if (student->getIDNumber() == id){
            std::cout << "\n\033[1;36mStudent Details:\033[0m\n";
            student->displayInfo();
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