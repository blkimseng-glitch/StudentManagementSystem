#include "Student.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void addStudent(vector<Student>& students)
{
    string name, gender;
    int ID;
    float average;

    cout << "Enter student Name: ";
    getline(cin,name);

    cout << "Enter student Gender: ";
    cin >> gender;

    cout << "Enter student ID: ";
    cin >> ID;
    cin.ignore();
    
     cout << "Enter student Average: ";
     cin >> average;

    students.push_back(Student(ID, name, gender, average));
    cout << "Student added successfully.\n";
}


