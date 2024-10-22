//
//  roster.h
//  JYM1 — JYM1 Task 1: Class Roster
//
//  Created by Christian Duque on 9/8/24.
//

#pragma once

#include <iostream>
#include <iomanip>
#include "roster.h"
#include "student.h"
#include "degree.h"

using namespace std;

//  Roster Class.

class Roster {
public:
    int lastStudent = -1;
    static const int totalStudents = 5;
    Student** getStudent();
    
public:

    void parse(string studentData);
    void add(string studentID,
             string firstName,
             string lastName,
             string emailAddress,
             int age,
             int days1,
             int days2,
             int days3,
             DegreeProgram degreeProgram);
    
    void printAll();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    void printInvalidEmails();
    void printAverageDaysInCourse(string studentID);
    void removeStudent(string studentID);
    
    //  Deconstructor.
    
    ~Roster();
};


