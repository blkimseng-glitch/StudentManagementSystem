
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Student.hpp" 
<<<<<<< HEAD
#include <tabulate/table.hpp>
=======
>>>>>>> 74e429e769fd0c30e256e45768ee39e1cf803ae7

using namespace std;


class TableRenderer {
private:
    int columnWidths[4] = {7, 20, 10, 15};
    const string GREEN = "\033[32m";
    const string RESET = "\033[0m";

    void drawBorder() {
        cout << GREEN << "+";
        for (int width : columnWidths) {
            cout << string(width, '-') << "+";
        }
        cout << RESET << endl;
    }

public:
    void displayHeader() {
        drawBorder();
        cout << GREEN << "| " << RESET << left 
             << setw(columnWidths[0]-2) << "ID" << GREEN << " | " << RESET
             << setw(columnWidths[1]-2) << "Name" << GREEN << " | " << RESET
             << setw(columnWidths[2]-2) << "Gender" << GREEN << " | " << RESET
             << setw(columnWidths[3]-2) << "Average" << GREEN << " |" << RESET << endl;
        drawBorder();
    }

   
    void displayRow(const Student& s) {
        cout << GREEN << "| " << RESET << left 
             << setw(columnWidths[0]-2) << s.getId() << GREEN << " | " << RESET
             << setw(columnWidths[1]-2) << s.getName() << GREEN << " | " << RESET
             << setw(columnWidths[2]-2) << s.getGender() << GREEN << " | " << RESET
             << fixed << setprecision(2) << setw(columnWidths[3]-2) << s.getAverage() << GREEN << " |" << RESET << endl;
        drawBorder();
    }
};

void displayAll(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students to display." << endl;
        return;
    }

    TableRenderer renderer;
    renderer.displayHeader();

    for (const Student& s : students) {
        renderer.displayRow(s);
    }
}

void displayPagination(const vector<Student>& list) {
    if (list.empty()) {
        cout << "No data available." << endl;
        return;
    }

    int pageSize = 5; 
    int totalStudents = list.size();
<<<<<<< HEAD
    int totalPages = (totalStudents + pjmageSize - 1) / pageSize; 
=======
    int totalPages = (totalStudents + pageSize - 1) / pageSize; 
>>>>>>> 74e429e769fd0c30e256e45768ee39e1cf803ae7
    int currentPage = 0;

    TableRenderer renderer;

    while (true) {
        
        system("cls"); 

        cout << "--- Page " << (currentPage + 1) << " of " << totalPages << " ---" << endl;
        
        renderer.displayHeader();

    
        int start = currentPage * pageSize;
        int end = min(start + pageSize, totalStudents);

        for (int i = start; i < end; ++i) {
            renderer.displayRow(list[i]);
        }

        cout << "\n[N] Next Page | [P] Previous Page | [Q] Quit: ";
        char choice;
        cin >> choice;

        if (tolower(choice) == 'n') {
            if (currentPage < totalPages - 1) currentPage++;
            else cout << "You are already on the last page!" << endl;
        } 
        else if (tolower(choice) == 'p') {
            if (currentPage > 0) currentPage--;
            else cout << "You are already on the first page!" << endl;
        } 
        else if (tolower(choice) == 'q') {
            break;
        }
    }
}
