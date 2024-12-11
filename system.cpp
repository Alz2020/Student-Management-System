#include "system.hpp"
#include <iostream>
using namespace std;

student rec[50];
int ts;

void get_data(int i){
    cout << "Enter the number of student: ";
    cin >> rec[i].id;
    cout <<"Enter student name:";
    cin >> rec[i].name;
    cout << "Enter student age: ";
    cin >> rec[i].age;
    cout << "Enter student grade: ";
    cin >> rec[i].grade;
    cout<< "Enter email:";
    cin >> rec[i].email;
    cout << "Enter student gender: ";
    cin >> rec[i].gender;
}

void display_data(int searchkey){
    int i = searchkey;
    cout << "Student ID: " << rec[i].id << endl;
    cout << "Student Name: " << rec[i].name << endl;
    cout << "Student Age: " << rec[i].age << endl;
    cout << "Student Grade: " << rec[i].grade << endl;
    cout << "Student Email: " << rec[i].email << endl;
    cout << "Student Gender: " << rec[i].gender << endl;

}

void search_student(int searchkey) {
    for (int i = 0; i <= ts; i++) {
        if (rec[i].id==searchkey){
            cout << "id" << "name"<<"age" << "grade" << "email" << "gender" << endl;
            display_data(i);
        }
    }
}

void add_student() {
    for (int i = 0; i <= ts; i++) {
        get_data(i);
    }
    system("CLS");
    cout << endl;
    cout << "---Student record Table ---" << endl;
    cout << "id" << "name"<<"age" << "grade" << "email" << "gender" << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i <= ts; i++) {
        display_data(i);
        system("pause");
    }
}

void edit_student(int id) {
    for (int i = 0; i <= ts; i++) {
        if (rec[i].id == id) {
            cout<< "\nExisted info about this student";
            cout << "--------------------------------";
            cout << "id" << "name"<<"age" << "grade" << "email" << "gender" << endl;
            cout << "---------------------------" << endl;
            display_data(i);
            cout << "\nEnter new info: ";
            get_data(i);
            cout << "Student record updated successfully!" << endl;
            system ("pause");
        }
    }
}


