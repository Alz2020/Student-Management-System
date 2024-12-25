#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
#include <limits>
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

// input validation helper function
template <typename T>
T getValidatedInput(const std::string& prompt) {
    T value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()){
            std::cin.clear();// Clear error 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// discard invalid input
            std::cerr << "\033[1;31mInvalid input. Please try again.\033[0m\n";
        } else {
            break;
        }
    }
    return value;
}

// function to add student 
template <typename T>
void addStudent(std::vector<std::unique_ptr<Student<T>>>& students){
    try {
        T id = getValidatedInput<T>("Enter ID number: ");
        std::cin.ignore(); 
    }
    std::string name;
    std::cout << "Enter name: ";
    std::getline(std::cin, name);

    float marks = getValidatedInput<float>("Enter marks (0-100):");
    if (marks < 0 || marks > 100) {
        throw std::invalid_argument("Marks must be between 0 and 100.");

    auto newStudent = std::make_unique<Student<T>>(id, name, marks);
    students.push_back(std::move(newStudent)); 
    std::cout << "\033[1;32mStudent added successfully!\033[0m\n";
} catch (const std::exception e){
    std::cerr << "\033[1;31m" << e.what() << "\033[0m\n";
}
}

//  Function to edit an existing student 
template <typename T>
void editStudent(std::vector<std::unique_ptr<Student<T>>>& students) {
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
template <typename T>
void searchStudent(std::vector<std::unique_ptr<Student<T>>>& students) {
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
template <typename T>
void showAllStudents(const std::vector<std::unique_ptr<Student<T>>>& students) {
    if (students.empty()) { // to check if there are no student to display
    std::cout << "\033[1;31mNo student to display.\033[0m\n";
    return;
}

std::cout << "\n\033[1;36mAll Students:\033[0m\n";
std::cout << std::left << std::setw(12) << "ID number"
        << std::setw(20) << "Name"
        << std::setw(10) << "Marks" << "\n";

for (const auto& student : students) {
    student->displayInfo();

    }
}
// save to file 
template <typename T>
void saveToFile(const std::vector<std::unique_ptr<Student<T>>>& students, const std::string& filename){
    try {
        std::ofstream outFile(filename);
        if (!outFile)
            throw std::ios_base::failure("Error opening file for saving.");
        for (const auto& student : students){
            outFile << student->getIDNumber() << " ,"
            << student->getName() << ", " 
            << student->getMarks() << "\n";
        }
        std::cout << "\033[1;32mStudents data saved successfully to file.\033[0m\n";
    } catch (const std::exception e) {
        std::cerr <<"\033[1;31mError: " << e.what() << "\033[0m\n";
    }
}

// load from file
template <typename T>
void loadFromFile(std::vector<std::unique_ptr<Student<T>>>& students, const std::string& filename){
    try {
        std::ifstream inFile(filename);
        if (!inFile)
            throw std::ios_base::failure("Error opening file for loading.");
        students.clear(); // clear list before loading
        std::string line;
        while (std::getline(inFile, line)) {
            std::istringstream iss(line);
            std::string idStr, name, marksStr;

            if (std::getline(iss, idStr, ',') &&
            std::getline(iss, name, ',') &&
            std::getline(iss, marksStr)) {
            T id = static_cast<T>(std::stol(idStr));
            float marks = std::stof(marksStr);
            auto newStudent = std::make_unique<Student<T>>(id, name, marks);
            students.push_back(std::move(newStudent));
            }
        }
        std::cout << "\033[1;32mStudents data loaded successfully from file.\033[0m\n";
    } catch (const std::exception e){
        std::cerr <<"\033[1;31mError: " << e.what() << "\033[0m\n";
    }
}

int main() {
    std::vector<std::unique_ptr<Student<int>>> students; // using 'int' as the ID type
    int choice;
    do{
        displayMenu();
        choice = getValidatedInput<int>("");

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
            saveToFile(students, "students.txt");
            break;
        case 6:       
            loadFromFile(students, "students.txt");
            break;
        case 7:
            std::cout << "\033[1;32mExiting \033[0m\n";
            break;
        default:
            std::cout << "\033[1;31mInvalid choice. Please try again.\033[0m\n";
        }
    }  while (choice != 7);
    return 0;
}