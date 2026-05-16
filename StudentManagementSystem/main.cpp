#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <math.h>
#include "Student.hpp"
#include "UserManager.hpp"

using namespace std;

const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";

void gotoxy(int x, int y)
{
    COORD coord = {(short)x, (short)y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void showUltraHackerIntro()
{
    system("cls");
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(0));

    for (int r = 0; r < 20; r++)
    {
        SetConsoleTextAttribute(h, 10); // ពណ៌បៃតង
        for (int i = 0; i < 50; i++)
        {
            double angle = (rand() % 360) * 3.14 / 180;
            int x = 40 + (int)(r * 2 * cos(angle));
            int y = 12 + (int)(r * sin(angle));
            if (x > 0 && x < 80 && y > 0 && y < 25)
            {
                gotoxy(x, y);
                cout << (rand() % 2);
            }
        }
        Sleep(40);
    }

    string title = "STUDENT MANAGEMENT SYSTEM";
    string dev = "DEVELOPED BY:  (GROUP 1)";
    string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@#$%^&*";

    gotoxy(25, 12);
    for (int i = 0; i < title.length(); i++)
    {

        for (int j = 0; j < 5; j++)
        {
            gotoxy(25 + i, 12);
            SetConsoleTextAttribute(h, 11); // ពណ៌ Cyan
            cout << chars[rand() % chars.length()];
            Sleep(10);
        }
        gotoxy(25 + i, 12);
        SetConsoleTextAttribute(h, 15); // ពណ៌សភ្លឺ
        cout << title[i];
    }

    gotoxy(23, 14);
    SetConsoleTextAttribute(h, 14); // ពណ៌លឿង
    cout << dev;

    gotoxy(25, 16);
    SetConsoleTextAttribute(h, 8); // ពណ៌ប្រផេះ
    cout << "[";
    for (int i = 0; i < 25; i++)
    {
        SetConsoleTextAttribute(h, 10);
        cout << (char)219;
        Sleep(50);
    }
    cout << "] 100%";

    SetConsoleTextAttribute(h, 15);
    gotoxy(30, 18);
    cout << "ACCESS GRANTED!";

    Sleep(1500);
    SetConsoleTextAttribute(h, 7);
    system("cls");
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));

    showUltraHackerIntro();
    vector<Student> students;
    bool systemRunning = true;

    while (systemRunning)
    {
        system("cls");
        // --- LOGIN HEADER ---
        cout << CYAN << "==================================================" << endl;
        cout << BOLD << WHITE << "            WELCOME TO STUDENT SYSTEM           " << RESET << endl;
        cout << CYAN << "==================================================" << RESET << endl;

        UserRole currentRole = UserManager::login();
        if (currentRole == UserRole::None)
        {
            cout << RED << "\n[!] Login Failed. Try again." << RESET << endl;
            Sleep(1500);
            continue;
        }

        int choice;
        do
        {
            system("cls");
            // --- MAIN MENU HEADER (Simple & Clean) ---
            cout << BLUE << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
            cout << BOLD << YELLOW << "           STUDENT MANAGEMENT SYSTEM            " << RESET << endl;

            string roleLabel, roleColor;
            if (currentRole == UserRole::Admin)
            {
                roleLabel = "ADMIN";
                roleColor = RED;
            }
            else if (currentRole == UserRole::Teacher)
            {
                roleLabel = "TEACHER";
                roleColor = GREEN;
            }
            else
            {
                roleLabel = "STUDENT";
                roleColor = CYAN;
            }

            cout << WHITE << "  Logged in as: " << BOLD << roleColor << roleLabel << RESET << endl;
            cout << BLUE << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET << endl;

            // --- MENU OPTIONS ---
            cout << "  " << CYAN << BOLD << "1." << RESET << " Display All Students" << endl;
            cout << "  " << CYAN << BOLD << "2." << RESET << " Search Student" << endl;
            cout << "  " << CYAN << BOLD << "3." << RESET << " Sort Students" << endl;

            if (currentRole == UserRole::Admin)
            {
                cout << MAGENTA << "  ──────────────── ADMIN MENU ──────────────────" << RESET << endl;
                cout << "  " << MAGENTA << BOLD << "4." << RESET << " Add New Student" << endl;
                cout << "  " << MAGENTA << BOLD << "5." << RESET << " Delete Student" << endl;
                cout << "  " << MAGENTA << BOLD << "6." << RESET << " Save Data to Excel" << endl;
            }

            cout << YELLOW << "  ──────────────────────────────────────────────" << RESET << endl;
            cout << "  " << CYAN << BOLD << "7." << RESET << " Logout" << endl;
            cout << "  " << RED << BOLD << "8." << RESET << " Exit System" << endl;
            cout << YELLOW << "  ──────────────────────────────────────────────" << RESET << endl;

            cout << BOLD << "  Select Option > " << RESET;
            if (!(cin >> choice))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            // --- SWITCH CASES ---
            switch (choice)
            {
            case 1:
                displayStudent(students);
                break;
            case 2:
                searchStudent(students);
                break;
            case 3:
                sortStudents(students);
                break;
            case 4:
                if (currentRole == UserRole::Admin)
                    addStudent(students);
                break;
            case 5:
                if (currentRole == UserRole::Admin)
                    deleteStudent(students);
                break;
            case 6:
                if (currentRole == UserRole::Admin)
                    updateStudent(students);
                break;
            case 7:
                if (currentRole == UserRole::Admin)
                    saveToExcel(students);
                break;

            case 8:
                cout << "\nLogging out...";
                Sleep(1000);
                break;
            case 9:
                systemRunning = false;
                choice = 7;
                break;
            default:
                cout << RED << "Invalid option!" << RESET;
                break;
            }

            if (choice != 7)
            {
                cout << "\n\n"
                     << WHITE << "Press Enter to return to menu...";
                cin.ignore(1000, '\n');
                cin.get();
            }

        } while (choice != 7);
    }
    return 0;
}