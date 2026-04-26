#include <iostream>
#include <vector>
#include <string>
#include "Student.hpp"
#include "UserManager.hpp"

using namespace std;

int main()
{
    system("cls");
    UserRole currentRole = UserManager::login();

    if (currentRole == UserRole::None)
    {
        cout << "\n[!] Invalid login credentials!" << endl;
        return 0;
    }

    vector<Student> students;
    int choice;

    do
    {
        cout << "\n==========================================" << endl;
        cout << "   STUDENT MANAGEMENT SYSTEM (GROUP 1)    " << endl;
        cout << "   Logged in as: " << (currentRole == UserRole::Admin ? "ADMIN" : "USER") << endl;
        cout << "==========================================" << endl;
        cout << "1. Display All Students (Tabular)    ]" << endl;
        cout << "2. Search Student (By ID)            " << endl;
        cout << "3. Sort Students (By Average)        " << endl;
        cout << "4. Pagination View (Bonus)           " << endl;

        if (currentRole == UserRole::Admin)
        {
            cout << "---------------- ADMIN MENU --------------" << endl;
            cout << "5. Add New Student                   " << endl;
            cout << "6. Delete Student                    " << endl;
            cout << "7. Save Data to Excel/CSV            " << endl;
        }

        cout << "0. Exit" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Select option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            displayAll(students);
            break;
        case 2:
            searchStudent(students);
            break;
        case 3:
            sortStudents(students);
            break;
        case 4:
            displayPagination(students);
            break;
        case 5:
            if (currentRole == UserRole::Admin)
                addStudent(students);
            else
                cout << "[!] You do not have permission to perform this action!" << endl;
            break;
        case 6:
            if (currentRole == UserRole::Admin)
                deleteStudent(students);
            else
                cout << "[!] You do not have permission to perform this action!" << endl;
            break;
        case 7:
            if (currentRole == UserRole::Admin)
                saveToExcel(students);
            else
                cout << "[!] You do not have permission to perform this action!" << endl;
            break;
        case 8:
            cout << "Exiting program... Goodbye!" << endl;
            break;
        default:
            cout << "[!] Invalid option! Please try again." << endl;
        }

        if (choice != 0)
        {
            cout << "\nPlease press Enter to continue...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 0);

    return 0;
}