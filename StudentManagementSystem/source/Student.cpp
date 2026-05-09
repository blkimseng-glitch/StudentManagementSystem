#include "Student.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void addStudent(vector<Student> &students)
{
    string name, gender;
    int ID;
    float average;

    cout << "Enter student ID: ";
    cin >> ID;
    cin.ignore();

    cout << "Enter student Name: ";
    getline(cin, name);

    do
    {
        cout << "Enter student Gender (M/F): ";
        cin >> gender;

           if (gender == "m")
            gender = "M";
        if (gender == "f")
            gender = "F";

        if (gender != "M" && gender != "F")
        {
            cout << "\033[31m[!] Invalid input! Please enter 'M' for Male or 'F' for Female.\033[0m" << endl;
        }
    } while (gender != "M" && gender != "F");

    cout << "Enter student Average: ";
    cin >> average;

    students.push_back(Student(ID, name, gender, average));
    cout << "Student added successfully.\n";
}

void searchStudent(const vector<Student> &list)
{
    int searchId;
    cout << "Enter student ID to search: ";
    cin >> searchId;

    auto it = find_if(list.begin(), list.end(), [searchId](const Student &student)
                      { return student.getId() == searchId; });

    if (it != list.end())
    {
        cout << "Student found:" << endl;
        cout << left << setw(10) << "ID"
             << left << setw(20) << "Name"
             << left << setw(10) << "Gender"
             << left << setw(10) << "Average" << endl;
        cout << left << setw(10) << it->getId()
             << left << setw(20) << it->getName()
             << left << setw(10) << it->getGender()
             << left << setw(10) << it->getAverage() << endl;
    }
    else
    {
        cout << "Student not found." << endl;
    }
}


void deleteStudent(vector<Student> &list)
{
    int id;
    cout << "\n[-] Enter student ID to delete: ";
    cin >> id;
    auto it = remove_if(list.begin(), list.end(), [id](const Student &student)
                        { return student.getId() == id; });

    if (it != list.end())
    {
        list.erase(it, list.end());
        cout << "Student deleted successfully!" << endl;
    }
    else
    {
        cout << "Student not found!\n"
             << endl;
    }
}