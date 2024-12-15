#include "ManagementSystem.hpp"

int main()
{
    ManagementSystem system;
    int choice;

    while (true)
    {
        std::cout << "\n1. Add Student\n2. Add Course\n2. Display Students\n4. Display Courses\n5.Exit\nChoose an option: ";
        std::cin >> choice;

        try
        {
            if (choice == 1)
            {
                std::string name;
                int age, id;
                std::cout << "Enter student name, age, and ID:";
                std::cin >> name >> age >> id;
                system.addStudent(name, age, id);
            }
            else if (choice == 2)
            {
                std::string courseName;
                int courseID;
                std::cout << "Enter course name and ID:";
                std::cin >> courseName >> courseID;
                system.addCourse(courseName, courseID);
            }
            else if (choice == 3)
            {
                system.displayStudents();
            }
            else if (choice == 4)
            {
                system.displayCourses();
            }
            else if (choice == 5)
            {
                break;
            }
            else
            {
                std::cout << "Invalid coption. Try again.\n";
            }
        }
        catch (const std::exception &e)
        {
        }
        std::cerr << "Error:" << e.what() << '\n';
        {
        }
        {
        }
        {
        }
    }
    return 0;
}
