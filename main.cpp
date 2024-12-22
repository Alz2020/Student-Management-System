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