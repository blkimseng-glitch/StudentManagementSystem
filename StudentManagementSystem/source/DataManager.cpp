#include "Student.hpp"
#include "UserManager.hpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <xlnt/xlnt.hpp>
using namespace std;
using namespace xlnt;

void saveToExcel(const vector<Student> &list)
{
    workbook wb;
    worksheet ws;

    ifstream file("SaveToExcel.xlsx");
    if (file.good())
    {
        wb.load("SaveToExcel.xlsx"); 
        ws = wb.active_sheet();
    }
    else
    {
        ws = wb.active_sheet();
        ws.title("sheet1");

        // header (only first time)
        ws.cell("A1").value("ID");
        ws.cell("B1").value("Name");
        ws.cell("C1").value("Gender");
        ws.cell("D1").value("Average");
    }


    int row = ws.highest_row() + 1;

   
    for (auto student : list)
    {
        ws.cell("A" + to_string(row)).value(student.getId());
        ws.cell("B" + to_string(row)).value(student.getName());
        ws.cell("C" + to_string(row)).value(student.getGender());
        ws.cell("D" + to_string(row)).value(student.getAverage());
        row++;
    }

    wb.save("SaveToExcel.xlsx");
    cout << "Data appended to Excel successfully!" << endl;
}