#pragma once

#include <string>
#include "degree.h"

using std::string;

class Student {

public:
    // constructor with all fields
    Student(string sID, string fName, string lName, string email,
            int years, int courseDays[], DegreeProgram program);

    // default constructor
    Student();

    // destructor
    ~Student();

    // --- accessors ---
    string getID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmail() const;
    int getAge() const;
    int* getCourseDays();
    DegreeProgram getProgram() const;

    // --- mutators ---
    void setID(string sID);
    void setFirstName(string fName);
    void setLastName(string lName);
    void setEmail(string email);
    void setAge(int years);
    void setCourseDays(int courseDays[]);
    void setProgram(DegreeProgram program);

    // prints this student's data in the required format
    void print() const;

private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddr;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;
};

