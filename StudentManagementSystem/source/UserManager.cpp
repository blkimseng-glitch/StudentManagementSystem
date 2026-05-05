#include "UserManager.hpp"
#include <iostream>
#include <string>
using namespace std;

int main(){
    system("cls");

    UserRole UserManager::login() {
    string username, password;
    cout << "\n---------- LOGIN SYSTEM ----------" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username == "admin" && password == "admin123") {
        cout << "[!] Login successful as ADMIN." << endl;
        return UserRole::Admin;
    } 
    else if (username == "teacher" && password == "teacher123") {
        cout << "[!] Login successful as Teacher." << endl;
        return UserRole::Student;
    }
    } 
    else if (username == "student" && password == "student123") {
        cout << "[!] Login successful as Student." << endl;
        return UserRole::Student;
    }
    else {
        cout << "[X] Invalid credentials! Access denied." << endl;
        return UserRole::None; 
    }
    
}
