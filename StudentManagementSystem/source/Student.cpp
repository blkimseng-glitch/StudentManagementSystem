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

    cout << "Enter student Gender: ";
    cin >> gender;

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

void sortStudents(vector<Student> &list)
{
    sort(list.begin(), list.end(), [](const Student &a, const Student &b)
         {
             return a.getAverage() > b.getAverage(); // Sort in descending order
         });

    cout << "Students sorted by average grade:" << endl;
    cout << left << setw(10) << "ID"
         << left << setw(20) << "Name"
         << left << setw(10) << "Gender"
         << left << setw(10) << "Average" << endl;
    for (const auto &student : list)
    {
        cout << left << setw(10) << student.getId()
             << left << setw(20) << student.getName()
             << left << setw(10) << student.getGender()
             << left << setw(10) << student.getAverage() << endl;
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