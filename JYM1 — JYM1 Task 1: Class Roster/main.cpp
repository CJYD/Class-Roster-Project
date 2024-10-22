//
//  main.cpp
//  JYM1 — JYM1 Task 1: Class Roster
//
//  Created by Christian Duque on 9/8/24.
//

#include <iostream>
#include <iomanip>
#include <string>
#include "degree.h"
#include "roster.h"
#include "student.h"


using namespace std;

//  Student data with personal info.

int main() {
    const int studentTotal = 5;
    const string studentData[5] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Christian,Duque,cduque10@wgu.edu,24,3,4,7,SOFTWARE"
    };
    
    //  Print out of course title, language used, WGU student ID, and name.
    
    auto courseTitle = "Scripting and Programming - Applications - C867";
    auto programmingLanguage = "C++";
    auto wguStudentID = "012282017";
    auto myName = "Christian Duque";
    
    cout << courseTitle << ", " << programmingLanguage << ", " << wguStudentID << ", " << myName << "." << endl;
    
    cout << endl;
    
    //  Roster Instance.
    
    Roster classRoster;
    
    //  Pseudo code.
    
    cout << "Student data: " << endl;
    for (int i = 0; i < studentTotal; i++ ) classRoster.parse(studentData[i]);
    cout << endl;
    classRoster.printAll();
    cout << endl;
    
    cout << "Invalid emails: " << endl << endl;
    classRoster.printInvalidEmails();
    cout << endl;
    
    cout << "Software degree program: " << endl << endl;
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    
    cout << "Average days in course: " << endl << endl;
    for (int i = 0; i < studentTotal; i++)
        classRoster.printAverageDaysInCourse(classRoster.getStudent()[i]->getStudentID());
   
    
    cout << endl;
    
    cout << "Remove the student A3: " << endl << endl;
    classRoster.removeStudent("A3");
    
    cout << endl;
    
    cout << "Students remaining after removing student: " << endl << endl;
    classRoster.printAll();
    
    cout << endl;
    
    cout << "Try to remove student A3 again: " << endl << endl;
    classRoster.removeStudent("A3");
    
    cout << endl;

    
    return 0;
}
