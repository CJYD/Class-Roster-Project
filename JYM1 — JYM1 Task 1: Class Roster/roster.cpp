//
//  roster.cpp
//  JYM1 — JYM1 Task 1: Class Roster
//
//  Created by Christian Duque on 9/8/24.
//

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"

using namespace std;

const static int totalStudents = 5;
Student* classRosterArray[totalStudents] = {nullptr, nullptr, nullptr, nullptr, nullptr};

Student** Roster::getStudent()  {
    return classRosterArray;
}

//  Updates Roster.

void Roster::parse(std::string studentData) {
    size_t rhs = studentData.find(",");
    string studentID = studentData.substr(0, rhs);
    
    size_t lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string emailAddress = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stod(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int days1 = stod(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int days2 = stod(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int days3 = stod(studentData.substr(lhs, rhs - lhs));
    
    DegreeProgram degreeProgram;
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    if(studentData.substr(lhs, rhs - lhs) ==  "SECURITY") {
        degreeProgram = DegreeProgram::SECURITY;
    }
    else if (studentData.substr(lhs, rhs - lhs) == "NETWORK") {
        degreeProgram = DegreeProgram::NETWORK;
    }
    else {
        degreeProgram = DegreeProgram::SOFTWARE;
    }
    
    add(studentID, firstName, lastName, emailAddress, age, days1, days2, days3, degreeProgram);
}

//  Print student data.

void Roster::printAll() {
    
    Student::printHeader();
    
    cout << endl;
    
    for (int i = 0; i <=Roster::lastStudent; i++) {
        classRosterArray[i]->print();
        
     /*   cout << classRosterArray[i]->getStudentID(); cout << '\t';
        cout << "First Name: " << classRosterArray[i]->getFirstName(); cout << '\t';
        cout << "Last Name: " << classRosterArray[i]->getLastName(); cout << '\t';
        cout << "Email: " << classRosterArray[i]->getEmailAddress(); cout << '\t';
        cout << "Age: " << classRosterArray[i]->getAge(); cout << '\t';
        cout << "daysInCourse: " << "{" << classRosterArray[i]->getCourseDays()[0];
        cout << ", " << classRosterArray[i]->getCourseDays()[1];
        cout << ", " << classRosterArray[i]->getCourseDays()[2]; cout << "}" << '\t';
        cout << "Degree Program: " << degreeStr[classRosterArray[i]->getDegreeProgram()]; cout << endl;
        */
    }
}
     
//  Print by degree program.

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    Student::printHeader();
    for (int i = 0; i <= lastStudent; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
        cout << endl;
    }
}

//  Print invalid emails.

void::Roster::printInvalidEmails() {
    bool specialCharacters = false;
    for (int i = 0; i <= lastStudent; i++) {
        string email = (classRosterArray[i]->getEmailAddress());
        if (email.find(' ') != string::npos || (email.find('.') == string::npos || email.find('@') == string::npos)) {
            specialCharacters = true;
            cout << email << endl;;
        }
    }
}

//  Add students to class.

void Roster::add(string studentID,
                 string firstName,
                 string lastName,
                 string emailAddress,
                 int age,
                 int days1,
                 int days2,
                 int days3,
                 DegreeProgram degreeProgram) {
    int DaysInCourse[3] = { days1, days2, days3 };
    
    classRosterArray[++lastStudent] = new Student(studentID, firstName, lastName, emailAddress, age, DaysInCourse, degreeProgram);
}

//  Remove students from class.

void Roster::removeStudent(string studentID) {
    bool notStudent = false;
    for (int i = 0; i <= Roster::lastStudent; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            notStudent = true;
            if (i < totalStudents - 1 ) {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[totalStudents - 1 ];
                classRosterArray[totalStudents - 1 ] = temp;
            }
            Roster::lastStudent--;
        }
    }
        if (notStudent) {
            cout << studentID << endl;
            
        }
        else cout << studentID << " was not found." << endl;
    }

//  Print average days in course.

void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i <= Roster::lastStudent; i++) {
        if (classRosterArray[i]->getStudentID()==studentID)
            cout << studentID << ": ";
            cout << (classRosterArray[i]->getCourseDays()[0] +
                     classRosterArray[i]->getCourseDays()[1] +
                     classRosterArray[i]->getCourseDays()[2])/3.0 << endl;
    }
}

Roster::~Roster() {
    cout << "Program has ended, goodbye!" << endl;
    for (int i = 0; i < totalStudents; i++) {
        cout << endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
