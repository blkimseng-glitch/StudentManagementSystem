#include "UserManager.hpp"
#include <iostream>
#include <string>

using namespace std;

UserRole UserManager::login()
{
    string username, password;
    UserRole currentRole = UserRole::None;

    // --- ផ្នែកទី ១: ការធ្វើ Login ---
    cout << "========= LOGIN SYSTEM =========" << endl;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    if (username == "admin" && password == "123")
    {
        currentRole = UserRole::Admin;
    }
    else if (username != "admin" && password != "123")
    {
        currentRole = UserRole::None;
        cout << "Incorrect username or password!  Please try again." << endl;
    }
    if (username == "teacher" && password == "123")
    {
        currentRole = UserRole::Teacher;
    }
    else if (username != "teacher" && password != "123")
    {
        currentRole = UserRole::None;
        cout << "Incorrect username or password!  Please try again." << endl;
    }
    if (username == "Student" && password == "123")
    {
        currentRole = UserRole::Student;
    }
    else if (username != "Student" && password != "123")
    {
        currentRole = UserRole::None;
        cout << "Incorrect username or password!  Please try again." << endl;
    }

    return currentRole;
}