#include <iostream>
#include "student.h"

using namespace std;

// full constructor
Student::Student(string sID, string fName, string lName, string email,
                 int years, int courseDays[], DegreeProgram program) {
    studentID = sID;
    firstName = fName;
    lastName = lName;
    emailAddr = email;
    age = years;
    for (int i = 0; i < 3; i++) {
        daysInCourse[i] = courseDays[i];
    }
    degreeProgram = program;
}

// default constructor
Student::Student() {
    studentID = "";
    firstName = "";
    lastName = "";
    emailAddr = "";
    age = 0;
    for (int i = 0; i < 3; i++) {
        daysInCourse[i] = 0;
    }
    degreeProgram = SECURITY;
}

// destructor
Student::~Student() {
    // nothing to manually free
}

// --- accessors ---
string Student::getID() const { return studentID; }
string Student::getFirstName() const { return firstName; }
string Student::getLastName() const { return lastName; }
string Student::getEmail() const { return emailAddr; }
int Student::getAge() const { return age; }

int* Student::getCourseDays() {
    return daysInCourse;
}

DegreeProgram Student::getProgram() const { return degreeProgram; }

// --- mutators ---
void Student::setID(string sID) { studentID = sID; }
void Student::setFirstName(string fName) { firstName = fName; }
void Student::setLastName(string lName) { lastName = lName; }
void Student::setEmail(string email) { emailAddr = email; }
void Student::setAge(int years) { age = years; }

void Student::setCourseDays(int courseDays[]) {
    for (int i = 0; i < 3; i++) {
        daysInCourse[i] = courseDays[i];
    }
}

void Student::setProgram(DegreeProgram program) { degreeProgram = program; }

// print student data tab-separated in the required format
void Student::print() const {
    cout << studentID << "\t"
         << "First Name: " << firstName << "\t"
         << "Last Name: " << lastName << "\t"
         << "Age: " << age << "\t"
         << "daysInCourse: {" << daysInCourse[0] << ", "
         << daysInCourse[1] << ", " << daysInCourse[2] << "}" << "\t"
         << "Degree Program: " << degreeProgramStrings[degreeProgram]
         << endl;
}

