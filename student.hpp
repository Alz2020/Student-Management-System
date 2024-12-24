#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <sstream>

// base class person
class Person {
protected:
    int IDNumber;
    std::string name;

public:
    Person(int id = 0, const std::string& name = "") : IDNumber(id), name(name) {}

    //getter and setter for id number
    int getIDNumber() const { return IDNumber; }
    void setIDNumber(int id) { IDNumber = id; }

    //getter and setter for name
    const std::string& getName() const {return name; }
    void setName(const std::string& newName) {name = newName; }

    //virtual function for displaying information
    virtual void displayInfo() const {
        std::cout <<std::left <<std::setw(12) <<IDNumber << std::setw(20) << name;
    }
    // virtual destructor 
    virtual ~Person() = default;
};



// derived class : student
class Student : public Person {
private:
    float marks;
public:
    Student(int id =0, const std::string& name="", float marks =0.0f)
    : Person(id, name), marks(marks) {}
    // getter and setter for marks
float getMarks() const { return marks; }
void setMarks(float newMarks) { marks = newMarks; }
// override displayInfo to include marks
void displayInfo() const override {
    Person::displayInfo();
    std::cout << std::setw(10) << marks << std
    }
};
// function declarations
void displayMenu();
void addStudent(std::vector<std::unique_ptr<Student>>& students);
void editStudent(std::vector<std::unique_ptr<Student>>& students);
void searchStudent(const std::vector<std::unique_ptr<Student>>& students);
void showAllStudents(const std::vector<std::unique_ptr<Student>>& students);

void saveToFile(const std::vector<std::unique_ptr<Student>>& students, const std::string& filename){
    std::ofstream file(filename, std::ios::out);
    if(file.is_open()){
        for(const auto& student : students){
            file << student->IDNumber << "," << student->name << "," << student->marks << "\n";
        }
        file.close();
        std::cout << "\033[1;32mData saved successfully!\033[0m\n";
    } else {
        std::cout << "\033[1;31mUnable to save data!\033[0m\n";
    }
}
// load from file 
void loadFromFile(std::vector<std::unique_ptr<Student>>& students, const std::string& filename){
        std::ifstream file(filename,std::ios::in);
        if (file.is_open()) {
        students.clear();
        std::string line;
        while (std::getline(file,line)) {
            auto student = std::make_unique<Student>();
            std::istringstream ss(line);
            std::string id, marks;
            std::getline(ss, id, ',');
            std::getline(ss, student->name, ',');
            std::getline(ss, marks, ',');
            student->IDNumber = std::stoi(id);
            student->marks = std::stof(marks);
            students.push_back(std::move(student));
        }
        file.close();
        std::cout << "\033[1;32mData loaded successfully!\033[0m\n";
    } else{
        std::cout << "\033[1;31mUnable to load data!\033[0m\n";
        } 
    }




#endif // !STUDENT_HPP

