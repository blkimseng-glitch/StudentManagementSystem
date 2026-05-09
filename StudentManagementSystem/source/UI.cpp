
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include "Student.hpp"

using namespace std;

string getGradeColor(const string &grade)
{
    if (grade == "A")
        return "\033[1;32m";
    if (grade == "B")
        return "\033[32m";
    if (grade == "C")
        return "\033[33m";
    if (grade == "D")
        return "\033[36m";
    if (grade == "E")
        return "\033[35m";
    return "\033[31m";
}

class TableRenderer
{
private:
    int columnWidths[5] = {7, 20, 10, 12, 7};
    const string GREEN = "\033[32m";
    const string RESET = "\033[0m";
    const string BOLD = "\033[1m";
    const string HEAD = GREEN + BOLD;
    const string LINE = GREEN + "  ──────────────────────────────────────────────" + RESET;

    void drawBorder()
    {
        cout << GREEN << "+";
        for (int width : columnWidths)
        {
            cout << string(width, '-') << "+";
        }
        cout << RESET << endl;
    }

public:
    void displayHeader()
    {
        drawBorder();
        cout << GREEN << "| " << RESET << left
             << setw(columnWidths[0] - 2) << "ID" << GREEN << " | " << RESET
             << setw(columnWidths[1] - 2) << "Name" << GREEN << " | " << RESET
             << setw(columnWidths[2] - 2) << "Gender" << GREEN << " | " << RESET
             << setw(columnWidths[3] - 2) << "Average" << GREEN << " | " << RESET
             << setw(columnWidths[4] - 2) << "Grade" << GREEN << " |" << RESET << endl; // បន្ថែម Grade
        drawBorder();
    }

    void displayRow(const Student &s)
    {
        string grade = s.getGrade();
        string gColor = getGradeColor(grade);

        cout << GREEN << "| " << RESET << left
             << setw(columnWidths[0] - 2) << s.getId() << GREEN << " | " << RESET
             << setw(columnWidths[1] - 2) << s.getName() << GREEN << " | " << RESET
             << setw(columnWidths[2] - 2) << s.getGender() << GREEN << " | " << RESET
             << fixed << setprecision(2) << setw(columnWidths[3] - 2) << s.getAverage() << GREEN << " | " << RESET
             << gColor << setw(columnWidths[4] - 2) << grade << GREEN << " |" << RESET << endl;
        drawBorder();
    }
};

void displayAll(const vector<Student> &students)
{
    if (students.empty())
    {
        cout << "\033[31m" << "\n[!] No students found." << "\033[0m" << endl;
        return;
    }

    const string RESET = "\033[0m";
    const string BOLD = "\033[1m";
    const string HEAD_COLOR = "\033[1;33m";
    const string LINE_COLOR = "\033[34m";

    string border = "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";

    cout << "\n"
         << LINE_COLOR << border << endl;
    printf("%s", HEAD_COLOR.c_str());
    printf("  %-8s %-20s %-12s %-12s %-8s\n", "ID", "NAME", "GENDER", "AVERAGE", "GRADE");
    printf("%s", RESET.c_str());
    cout << LINE_COLOR << border << RESET << endl;

    for (const auto &s : students)
    {
        string grade = s.getGrade();
        string gColor = getGradeColor(grade);

        printf("  %-8s %-20s %-12s %-12.2f %s%-8s%s\n",
               to_string(s.getId()).c_str(),
               s.getName().c_str(),
               s.getGender().c_str(),
               s.getAverage(),
               gColor.c_str(), grade.c_str(), RESET.c_str());
    }

    cout << LINE_COLOR << border << RESET << endl;
    cout << "Total Students: " << BOLD << students.size() << RESET << "\n"
         << endl;
}

void displayPagination(const vector<Student> &list)
{
    if (list.empty())
    {
        cout << "\033[31m" << "\n[!] No students found." << "\033[0m" << endl;
        return;
    }

    const string RESET = "\033[0m";
    const string BOLD = "\033[1m";
    const string HEAD_COLOR = "\033[1;33m";
    const string LINE_COLOR = "\033[34m";

    string border = "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";

    int pageSize = 5;
    int totalStudents = list.size();
    int totalPages = (totalStudents + pageSize - 1) / pageSize;
    int currentPage = 0;

    while (true)
    {
        system("cls");

        cout << "\n"
             << LINE_COLOR << border << endl;
        printf("%s", HEAD_COLOR.c_str());
        printf("  %-8s %-20s %-12s %-12s %-8s\n", "ID", "NAME", "GENDER", "AVERAGE", "GRADE");
        printf("%s", RESET.c_str());
        cout << LINE_COLOR << border << RESET << endl;

        int start = currentPage * pageSize;
        int end = min(start + pageSize, totalStudents);

        for (int i = start; i < end; ++i)
        {
            const Student &s = list[i];
            string grade = s.getGrade();
            string gColor = getGradeColor(grade);

            printf("  %-8s %-20s %-12s %-12.2f %s%-8s%s\n",
                   to_string(s.getId()).c_str(),
                   s.getName().c_str(),
                   s.getGender().c_str(),
                   s.getAverage(),
                   gColor.c_str(), grade.c_str(), RESET.c_str());
        }

        cout << LINE_COLOR << border << RESET << endl;
        cout << "Total Students: " << BOLD << totalStudents << RESET
             << "  |  Page " << BOLD << (currentPage + 1) << RESET
             << " of " << BOLD << totalPages << RESET << "\n\n";

        cout << "[N] Next  |  [P] Previous  |  [Q] Quit: ";
        char choice;
        cin >> choice;

        switch (tolower(choice))
        {
        case 'n':
            if (currentPage < totalPages - 1)
                currentPage++;
            else
                cout << "\033[33m[!] You are already on the last page!\033[0m\n";
            break;
        case 'p':
            if (currentPage > 0)
                currentPage--;
            else
                cout << "\033[33m[!] You are already on the first page!\033[0m\n";
            break;
        case 'q':
            return;
        }
    }
}

void displayStudent(const vector<Student> &students)
{
    const string RESET = "\033[0m";
    const string BOLD = "\033[1m";
    const string CYAN = "\033[1;36m";

    cout << "\n"
         << CYAN << "  [1] Display All Students" << RESET << endl;
    cout << CYAN << "  [2] Display with Pagination" << RESET << endl;
    cout << "\n  Choose: ";

    char choice;
    cin >> choice;

    switch (choice)
    {
    case '1':
        displayAll(students);
        break;
    case '2':
        displayPagination(students);
        break;
    default:
        cout << "\033[31m[!] Invalid choice!\033[0m\n";
        break;
    }
}

void sortStudents(vector<Student> &list)
{

    sort(list.begin(), list.end(), [](const Student &a, const Student &b)
         { return a.getAverage() > b.getAverage(); });

    const string HEAD = "\033[1;33m";
    const string RESET = "\033[0m";

    cout << "\nStudents sorted by average grade (Highest to Lowest):" << endl;

    // ២. បន្ថែមជួរឈរ GRADE ក្នុង Header
    cout << HEAD << left << setw(10) << "ID"
         << left << setw(20) << "Name"
         << left << setw(10) << "Gender"
         << left << setw(12) << "Average"
         << left << setw(10) << "Grade" << RESET << endl;

    for (const auto &student : list)
    {
        string grade = student.getGrade();

        string gColor = getGradeColor(grade);

        cout << left << setw(10) << student.getId()
             << left << setw(20) << student.getName()
             << left << setw(10) << student.getGender()
             << left << setw(12) << fixed << setprecision(2) << student.getAverage()
             << gColor << left << setw(10) << grade << RESET << endl;
    }
}
