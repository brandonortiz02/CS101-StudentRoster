#include <iostream>
#include "roster.h"

using namespace std;

int main() {

    // F1 — course info header
    cout << "Course Title: Scripting and Programming - Applications — C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 900821299" << endl;
    cout << "Student Name: Brandon Ortiz" << endl;
    cout << endl;

    // A — student data with personal info as A5
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Brandon,Ortiz,therealboltgamez@gmail.com,23,40,45,50,SOFTWARE"
    };

    // F2 — create an instance of Roster
    Roster classRoster;

    // F3 — add each student to the roster
    int numStudents = sizeof(studentData) / sizeof(studentData[0]);
    for (int i = 0; i < numStudents; i++) {
        classRoster.parse(studentData[i]);
    }

    // F4 — pseudo code conversion

    cout << "--- All Students ---" << endl;
    classRoster.printAll();
    cout << endl;

    classRoster.printInvalidEmails();
    cout << endl;

    // loop through classRosterArray and print average days for each student
    cout << "Average days in course:" << endl;
    for (int i = 0; i < classRoster.rosterSize; i++) {
        classRoster.printAverageDaysInCourse(
            classRoster.classRosterArray[i]->getID()
        );
    }
    cout << endl;

    cout << "--- SOFTWARE Students ---" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    classRoster.remove("A3");
    cout << endl;

    cout << "--- All Students After Removing A3 ---" << endl;
    classRoster.printAll();
    cout << endl;

    classRoster.remove("A3");
    // expected: error message saying student A3 was not found

    // F5 — destructor releases memory automatically when classRoster goes out of scope
    return 0;
}

