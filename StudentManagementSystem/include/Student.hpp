#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class Student {

private:
    int id;
    string name;
    string gender; 
    float average;

public:
    // OOP constructor
    Student(int id, string name, string gender, float average) {
        this->id = id;
        this->name = name;
        this->gender = gender;
        this->average = average;
    }

    // OOP getter and setter
    int getId() const {
        return id;
    }

    string getName() const { 
        return name;
    }

    string getGender() const { 
        return gender;
    }

    float getAverage() const { 
        return average;
    }

    // setters
    void setName(string name) {
        this->name = name;
    }

    void setAverage(float average) {
        this->average = average;
    }

  
    void displayRow() const {
        cout << left << setw(10) << id
             << left << setw(20) << name
             << left << setw(10) << gender
             << left << setw(10) << average
             << endl;
    }
};


void addStudent(vector<Student>& students);
void searchStudent(const vector<Student>& list);
void sortStudents(vector<Student>& list);
void deleteStudent(vector<Student>& students);
void displayAll(const vector<Student>& list);
void displayPagination(const vector<Student>& list);
void saveToExcel(const vector<Student>& list);

#endif

