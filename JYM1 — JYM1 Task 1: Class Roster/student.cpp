//
//  student.cpp
//  JYM1 — JYM1 Task 1: Class Roster
//
//  Created by Christian Duque on 9/8/24.
//

#include <iostream>
#include <iomanip>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"

using namespace std;

//  Default Constructor.

Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = -1;
    for (int i = 0; i < daysArray; i++)
        this->courseDays[i] = 0;
    
    this->degreeProgram =
    DegreeProgram::UNDECLARED;
}

Student::Student(string studentID,
                 string firstName,
                 string lastName,
                 string emailAddress,
                 int age,
                 int courseDays[],
                 DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < daysArray; i++)
        this->courseDays[i] = courseDays[i];

    this->degreeProgram = degreeProgram;
}

//  Deconstructor.

Student::~Student() {}

//  Accessor and Mutator.

string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return age; }
int* Student::getCourseDays() { return this->courseDays; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setCourseDays(int courseDays[]) {
    for(int i = 0; i < daysArray; i++) {
        this->courseDays[i] = courseDays[i];}
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

//  Print.

void Student::printHeader() {
    cout << "Student ID | First Name | Last Name | Email | Age | Days in Course | Degree Program\n";
}

void Student::print() {
    cout << this->getStudentID() << '\t';
    cout << "First Name: ""Last Name: " << this->getFirstName() << '\t';
    cout << "Last Name: " << this->getLastName() << '\t';
    cout << "Email: " << this->getEmailAddress() << '\t';
    cout << "Age: " << this->getAge() << '\t';
    cout << "daysInCourse: " << "{" << this->getCourseDays()[0]<< ", ";
    cout << this->getCourseDays()[1]<< ", ";
    cout << this->getCourseDays()[2]<< "}" << '\t';
    cout << degreeStr[this->getDegreeProgram()] << '\n';
}
