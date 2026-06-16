#include <iostream>
#include <fstream>

using namespace std;

struct Student {
    int roll;
    float marks;
};

const string FILE_NAME = "students.dat";

// ==================== ADD STUDENT ====================
void addStudent() {
    Student s;

    cout << "\nEnter Roll Number: ";
    cin >> s.roll;

    cout << "Enter Marks: ";
    cin >> s.marks;

    ofstream file(FILE_NAME, ios::binary | ios::app);

    file.write((char*)&s, sizeof(Student));

    file.close();

    cout << "Student Added Successfully!\n";
}

// ==================== VIEW ALL ====================
void viewAllStudents() {

    ifstream file(FILE_NAME, ios::binary);

    Student s;

    cout << "\n------ STUDENT RECORDS ------\n";

    while(file.read((char*)&s, sizeof(Student))) {

        cout << "Roll: "
             << s.roll
             << "  Marks: "
             << s.marks
             << endl;
    }

    file.close();
}

// ==================== COUNT RECORDS ====================
int getRecordCount() {

    ifstream file(FILE_NAME, ios::binary);

    file.seekg(0, ios::end);

    long size = file.tellg();

    file.close();

    return size / sizeof(Student);
}

// ==================== READ SPECIFIC RECORD ====================
void readRecord(int recordNo) {

    ifstream file(FILE_NAME, ios::binary);

    Student s;

    file.seekg(
        (recordNo - 1) * sizeof(Student)
    );

    file.read((char*)&s, sizeof(Student));

    cout << "\nRecord " << recordNo << endl;

    cout << "Roll: "
         << s.roll
         << endl;

    cout << "Marks: "
         << s.marks
         << endl;

    file.close();
}

// ==================== SEARCH STUDENT ====================
void searchStudent(int rollNo) {

    ifstream file(FILE_NAME, ios::binary);

    Student s;

    bool found = false;

    while(file.read((char*)&s, sizeof(Student))) {

        if(s.roll == rollNo) {

            cout << "\nStudent Found\n";

            cout << "Roll: "
                 << s.roll
                 << endl;

            cout << "Marks: "
                 << s.marks
                 << endl;

            found = true;

            break;
        }
    }

    if(!found) {
        cout << "\nStudent Not Found\n";
    }

    file.close();
}

// ==================== UPDATE RECORD ====================
void updateRecord(int recordNo) {

    fstream file(
        FILE_NAME,
        ios::binary | ios::in | ios::out
    );

    Student s;

    cout << "\nEnter New Roll Number: ";
    cin >> s.roll;

    cout << "Enter New Marks: ";
    cin >> s.marks;

    file.seekp(
        (recordNo - 1) * sizeof(Student)
    );

    file.write((char*)&s, sizeof(Student));

    file.close();

    cout << "Record Updated Successfully!\n";
}

// ==================== MAIN ====================
int main() {

    int choice;

    do {

        cout << "\n========== MENU ==========\n";

        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Count Records\n";
        cout << "4. Read Specific Record\n";
        cout << "5. Search By Roll Number\n";
        cout << "6. Update Record\n";
        cout << "0. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                addStudent();
                break;

            case 2:
                viewAllStudents();
                break;

            case 3:
                cout << "\nTotal Records = "
                     << getRecordCount()
                     << endl;
                break;

            case 4: {

                int recordNo;

                cout << "Enter Record Number: ";
                cin >> recordNo;

                readRecord(recordNo);

                break;
            }

            case 5: {

                int rollNo;

                cout << "Enter Roll Number: ";
                cin >> rollNo;

                searchStudent(rollNo);

                break;
            }

            case 6: {

                int recordNo;

                cout << "Enter Record Number To Update: ";
                cin >> recordNo;

                updateRecord(recordNo);

                break;
            }

            case 0:
                cout << "\nGoodbye!\n";
                break;

            default:
                cout << "\nInvalid Choice\n";
        }

    } while(choice != 0);

    return 0;
}