#pragma once

#include <string>
#include "student.h"

using std::string;

class Roster {

public:
    // keeps track of how many students are currently stored
    int rosterSize;

    // array of pointers to Student objects
    Student* classRosterArray[5];

    // constructor / destructor
    Roster();
    ~Roster();

    // parses a comma-delimited string and adds the student
    void parse(string row);

    // adds a student to classRosterArray
    void add(string studentID, string firstName, string lastName,
             string emailAddress, int age, int daysInCourse1,
             int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

    // removes a student by ID; prints error if not found
    void remove(string studentID);

    // prints all students
    void printAll() const;

    // prints the average days-in-course for a given student
    void printAverageDaysInCourse(string studentID) const;

    // prints emails that are missing '@' or '.', or contain a space
    void printInvalidEmails() const;

    // prints students who belong to a specific degree program
    void printByDegreeProgram(DegreeProgram degreeProgram) const;
};

