#include <iostream>
#include <sstream>
#include "roster.h"

using namespace std;

// constructor — start with zero students and null pointers
Roster::Roster() {
    rosterSize = 0;
    for (int i = 0; i < 5; i++) {
        classRosterArray[i] = nullptr;
    }
}

// destructor — free every student that was allocated
Roster::~Roster() {
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] != nullptr) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
        }
    }
}

// split a CSV row and hand the pieces to add()
void Roster::parse(string row) {
    stringstream ss(row);
    string token;
    string fields[9];
    int idx = 0;

    while (getline(ss, token, ',') && idx < 9) {
        fields[idx++] = token;
    }

    string sID   = fields[0];
    string fName = fields[1];
    string lName = fields[2];
    string email = fields[3];
    int years    = stoi(fields[4]);
    int d1       = stoi(fields[5]);
    int d2       = stoi(fields[6]);
    int d3       = stoi(fields[7]);
    string dp    = fields[8];

    DegreeProgram program;
    if (dp == "SECURITY")      program = SECURITY;
    else if (dp == "NETWORK")  program = NETWORK;
    else                       program = SOFTWARE;

    add(sID, fName, lName, email, years, d1, d2, d3, program);
}

// create a new Student on the heap and store the pointer
void Roster::add(string studentID, string firstName, string lastName,
                 string emailAddress, int age, int daysInCourse1,
                 int daysInCourse2, int daysInCourse3,
                 DegreeProgram degreeProgram) {

    int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    classRosterArray[rosterSize] = new Student(studentID, firstName, lastName,
                                               emailAddress, age, days,
                                               degreeProgram);
    rosterSize++;
}

// remove by ID — swap with last element to keep the array compact
void Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i < rosterSize; i++) {
        if (classRosterArray[i]->getID() == studentID) {
            found = true;
            delete classRosterArray[i];
            // move the last element into this slot
            classRosterArray[i] = classRosterArray[rosterSize - 1];
            classRosterArray[rosterSize - 1] = nullptr;
            rosterSize--;
            cout << "Student " << studentID << " removed." << endl;
            break;
        }
    }
    if (!found) {
        cout << "ERROR: Student with ID " << studentID << " not found." << endl;
    }
}

// call each student's print()
void Roster::printAll() const {
    for (int i = 0; i < rosterSize; i++) {
        classRosterArray[i]->print();
    }
}

// find a student by ID, then compute the average of their 3 course-day values
void Roster::printAverageDaysInCourse(string studentID) const {
    for (int i = 0; i < rosterSize; i++) {
        if (classRosterArray[i]->getID() == studentID) {
            int* days = classRosterArray[i]->getCourseDays();
            int total = days[0] + days[1] + days[2];
            cout << "Student ID: " << studentID
                 << ", average days in course: " << (total / 3) << endl;
            return;
        }
    }
}

// check every student's email for basic validity
void Roster::printInvalidEmails() const {
    cout << "Invalid emails:" << endl;
    for (int i = 0; i < rosterSize; i++) {
        string e = classRosterArray[i]->getEmail();

        bool noAt   = (e.find('@') == string::npos);
        bool noDot  = (e.find('.') == string::npos);
        bool hasSpace = (e.find(' ') != string::npos);

        if (noAt || noDot || hasSpace) {
            cout << e << endl;
        }
    }
}

// print only those students whose program matches
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    cout << "Students in program: "
         << degreeProgramStrings[degreeProgram] << endl;
    for (int i = 0; i < rosterSize; i++) {
        if (classRosterArray[i]->getProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

