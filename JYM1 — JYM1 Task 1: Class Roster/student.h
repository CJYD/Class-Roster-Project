//
//  student.h
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

//  Student Class.

class Student {
    
public:
    
    const static int daysArray = 3;

private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int courseDays[daysArray];
    DegreeProgram degreeProgram;
    
public:
    
    //  Defualt constructor.
    
    Student();
    
    //  Constructor.
    
    Student(string studentID,
            string firstName,
            string lastName,
            string emailAddress,
            int age,
            int courseDays[],
            DegreeProgram degreeProgram);
    
    //  Deconstructor.
    
    ~Student();
    
    //  Accessors and Mutators.
    
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getCourseDays();
    DegreeProgram getDegreeProgram();
    
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setCourseDays(int courseDays[]);
    void setDegreeProgram(DegreeProgram degreeProgram);
    
    //  Print.
    
    static void printHeader();
    
    void print();
};

