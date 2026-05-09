#include "UserManager.hpp"
#include <iostream>
#include <string>

using namespace std;

UserRole UserManager::login() // static method for user login
{
    string username, password;
    UserRole currentRole = UserRole::None;

    // --- ផ្នែកទី ១: ការធ្វើ Login ---
    cout << "========= LOGIN SYSTEM =========" << endl;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    // --- ផ្នែកទី ២: ការត្រួតពិនិត្យ Username និង Password ---

    if (username == "admin" && password == "123")
    {
        currentRole = UserRole::Admin;
    }
    else if (username == "teacher" && password == "123")
    {
        currentRole = UserRole::Teacher;
    }
    else if (username == "Student" && password == "123")
    {
        currentRole = UserRole::Student;
    }
    else
    {
        cout << "Incorrect username or password!" << endl;
        currentRole = UserRole::None;
    }

    return currentRole;
}