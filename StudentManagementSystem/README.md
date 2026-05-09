# StudentManagementSystem



 switch (choice)
            {
            case 1:
               displayP(students);
                break;
            case 2:
                searchStudent(students);
                break;
            case 3:
                sortStudents(students);
                break;
            case 4:
                displayPagination(students);
                break;
            case 5:
                if (currentRole == UserRole::Admin)
                    addStudent(students);
                break;
            case 6:
                if (currentRole == UserRole::Admin)
                    deleteStudent(students);
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
                choice = 8;
                break;
            default:
                cout << RED << "Invalid option!" << RESET;
                break;
            }

            if (choice != 8)
            {
                cout << "\n\n"
                     << WHITE << "Press Enter to return to menu...";
                cin.ignore(1000, '\n');
                cin.get();
            }





void displayAll(const vector<Student> &students)
{
    if (students.empty())
    {
        cout << "\033[31m" << "\n[!] No students found." << "\033[0m" << endl;
        return;
    }

    const string RESET = "\033[0m";
    const string BOLD = "\033[1m";
    const string HEAD_COLOR = "\033[1;33m"; // លឿងដិត
    const string LINE_COLOR = "\033[34m";   // ខៀវ

    string border = "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";

    // កែត្រង់នេះ៖ ដូរពី __LINE__ មក LINE_COLOR
    cout << "\n"
         << LINE_COLOR << border << endl;

    printf("%s", HEAD_COLOR.c_str());
    printf("  %-8s %-20s %-12s %-12s %-8s\n", "ID", "NAME", "GENDER", "AVERAGE", "GRADE");
    printf("%s", RESET.c_str());

    // កែត្រង់នេះ៖ ដូរពី __LINE__ មក LINE_COLOR
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
               gColor.c_str(), grade.c_str(), RESET.c_str()); // បន្ថែមពណ៌នៅទីនេះ
    }

    cout << LINE_COLOR << border << RESET << endl;
    cout << "Total Students: " << BOLD << students.size() << RESET << "\n"
         << endl;
}

void displayPagination(const vector<Student> &list)
{
    if (list.empty())
    {
        cout << "No data available." << endl;
        return;
    }

    int pageSize = 5;
    int totalStudents = list.size();
    int totalPages = (totalStudents + pageSize - 1) / pageSize;
    int currentPage = 0;

    TableRenderer renderer;

    while (true)
    {

        system("cls");

        cout << "--- Page " << (currentPage + 1) << " of " << totalPages << " ---" << endl;

        renderer.displayHeader();

        int start = currentPage * pageSize;
        int end = min(start + pageSize, totalStudents);

        for (int i = start; i < end; ++i)
        {
            renderer.displayRow(list[i]);
        }

        cout << "\n[N] Next Page | [P] Previous Page | [Q] Quit: ";
        char choice;
        cin >> choice;

        if (tolower(choice) == 'n')
        {
            if (currentPage < totalPages - 1)
                currentPage++;
            else
                cout << "You are already on the last page!" << endl;
        }
        else if (tolower(choice) == 'p')
        {
            if (currentPage > 0)
                currentPage--;
            else
                cout << "You are already on the first page!" << endl;
        }
        else if (tolower(choice) == 'q')
        {
            break;
        }
    }
}

