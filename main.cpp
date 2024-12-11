#include "system.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {

    system("CLS");
    system("color B1");
    int choices;
    int id;
    int searchkey;

    while (ts--){
    cout <<"\n ------------------------------------------------------"<< endl;
    cout << "---Welcome to the Software Development Student System---"<< endl;
    cout <<"\n ------------------------------------------------------"<< endl;
    cout <<"\n1-Add student" << endl;
    cout <<"\n2-Edit student" << endl;
    cout <<"\n3-Searche student" << endl;
    cout <<"\n4-Delete student" << endl;
    cout <<"\n5-Display all students" << endl;
    cout <<"\n6-Exit" << endl;
    cout <<"\n--------------------------------------------------------"<< endl;
    cout << "\nEnter your choice: ";

    cin >> choices;
    switch(choices){
        case 1:
            add_student();
            break;
        case 2:
            if (rec[0].id==0) {
                cout << "Please enter student first." << endl;
                system("pause");
                main();
                } else {
                    cout << "Student already exists." << endl;
                    cout << "id" << "name"<<"age" << "grade" << "email" << "gender" << endl;
                    cout << "-------------------------------------------" << endl;
                    for (int i = 0; i < rec[0].id; i++) {
                        display_data(i);
                }
                cout << "-------------------------------------------" << endl;
                cout << "\nEnter the id of the student to edit: ";
                cin >> id;

                if (id > ts || id < 0) {
                    cout << "Invalid id. Please try again." << endl;
                } else {
                    edit_student(id);
                }

            }
            break;

            case 3:
            if (rec[0].id==0) {
                cout << "Please enter student first." << endl;
                system("pause");
                main();
                } else {
                    cout << "Enter id of student you want to reasrch:";
                    cin >> searchkey;
                    search_student(searchkey);
                }
                break;

                case 4:
                    return 0;
                default:
                system("pause");
                main();
            }
        }
        return 0;
    }
    //         edit_student();
    //         break;
    //     case 3:
    //         search_student();
    //         break;
    //     case 4:
    //         delete_student();
    //         break;
    //     case 5:
    //         display_students();
    //         break;
    //     case 6:
    //         exit(0);
    //     default:
    //         cout<<"\nInvalid choice. Please try again."<<endl;
    // }

