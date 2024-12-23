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
// load from file 
void loadFromFile(std::vector<Student>& students, const std::string& filename){
    // improve error handling
    try {
        std::ifstream file(filename,std::ios::in);
        if (!file) throw std::ios_base::failure("Failed to open file");
    
    std::ifstream file(filename, std::ios::in);
    if (file.is_open()) {
        students. clear();
        Student temp;
        std::string line;
        while (std::getline(file,line)) {
            std::istringstream ss(line);
            std::string id, marks;
            std::getline(ss, id, ',');
            std::getline(ss, temp.name, ',');
            std::getline(ss, marks, ',');
            temp.IDNumber = std::stoi(id);
            temp.marks = std::stof(marks);
            students.push_back(temp);
        }
        std::cout << "\033[1;32mData loaded successfully!\033[0m\n";
    } else{
        std::cerr << "\033[1;31mUnable to load data!\033[0m\n";
    } catch (const std::exception& e){
        std::cerr << "\033[1;31mError: " << e.what() << "\033[0m\n";
        }
    }

}


#endif // !STUDENT_HPP

