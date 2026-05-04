#include "Student.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

 struct Student
    {
        string name,gender;
        int id;
        float average;
    };
    

void addStudent(vector<Student>& students){Student newStudent;
    cout<< "Enter student Name: ";
    cin.ignore();
    getline(cin,newStudent.name);

    cout<< "Enter student Gender: ";
    cin>>newStudent.gender;
    
    cout<< "Enter student ID: ";
    cin >> newStudent.id;

    cout<< "Enter student Average: ";
    cin >>newStudent.average;

    students.push_back(newStudent);
    cout<< "Student added successfully.\n";

}