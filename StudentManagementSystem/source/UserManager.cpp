#include "UserManager.hpp"
#include <iostream>
#include <string>

using namespace std;

UserRole UserManager::login() {
    string username, password;
    UserRole currentRole = UserRole::None;

    // --- ផ្នែកទី ១: ការធ្វើ Login ---
    cout << "========= LOGIN SYSTEM =========" << endl;
    cout << "Enter Username: "; cin >> username;
    cout << "Enter Password: "; cin >> password;

    if (username == "admin" && password == "123") {
        currentRole = UserRole::Admin;
    } else if (username == "teacher" && password == "123") {
        currentRole = UserRole::Teacher;
    } else {
        currentRole = UserRole::Student; 
    }

    

    return currentRole; 
}