#ifndef GPA_CALC_H
#define GPA_CALC_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// enum Grade
enum Grade {
    A = 4, // Standard Grade Point System, A = 4.0
    B = 3, // Standard Grade Point System, B = 3.0
    C = 2, // Standard Grade Point System, C = 2.0
    D = 1, // Standard Grade Point System, D = 1.0
    F = 0  // Standard Grade Point System, F = 0.0
};

Grade getGradeFromInput(char gradeChar){
    switch(gradeChar) {
        case 'A' : return A;
        case 'B' : return B;
        case 'C' : return C;
        case 'D' : return D;
        case 'F' : return F;
        default :
            cout << "Invalid Input: Defaulting to F" << endl;
            return F;
    }
}

// Classes for Courses and Student ID
class Course {
    public:
        string courseName;
        int credits;
        Grade grade;

        Course(string name, int crds, Grade grd) : courseName(name), credits(crds), grade(grd) {}
};

class Student {
    public:
        string name;
        int studentID;
        vector<Course> courses;

    void addCourse(Course);
    double calculateGPA();
};

// GPA FUNCTIONS
double gradeToPoints(Grade grade);

#endif // GPA_CALC_H
