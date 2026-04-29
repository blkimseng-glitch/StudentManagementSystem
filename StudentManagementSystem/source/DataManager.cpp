#include "Student.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <xlnt/xlnt.hpp>

using namespace xlnt;
using namespace std;


void SaveToExcel(const vector<Student>& list) {
workbook wb;
worksheet ws = wb.active_sheet();
ws.title("sheet1");

ws.cell("A1").value("ID");
ws.cell("B1").value("Name");
ws.cell("C1").value("Gender");
ws.cell("D1").value("Average");

int row =2;
for (auto student : list){
    ws.cell("A"+to_string(row)).value(to_string(student.getId()));
    ws.cell("B" + to_string(row)).value(student.getName());
ws.cell("C" + to_string(row)).value(student.getGender());
    ws.cell("D"+to_string(row)).value(to_string(student.getAverage()));
    row++;
}
wb.save("SaveToExcel.xlsx");
cout<<"Data saved to exel successfully!"<<endl;
}
vector<Student> LoadFromExcel( const string& filename){
    vector<Student> studentList;
    workbook wb;
    try{
        wb.load(filename);

    }catch(...){
        cout<<"Error loading excel file!"<<endl;
        return studentList;
    }
    worksheet ws = wb.active_sheet();
    for(auto row : ws.rows(false)){
        if(row[0].to_string()=="ID")continue;
        int id = stoi(row[0].to_string());
        string name = row[1].to_string();
        string gender =row[2].to_string();
        float average = stof(row[3].to_string());
        studentList.push_back(Student(id, name, gender, average));
    }
    return studentList;
}