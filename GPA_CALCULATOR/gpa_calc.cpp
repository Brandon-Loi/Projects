#include "gpa_calc.h"

double gradeToPoints(Grade grade){
    switch (grade)
    {
    case A: return 4.0;
    case B: return 3.0;
    case C: return 2.0;
    case D: return 1.0;
    case F: return 0.0;
    default: return 0.0; // In the case of default just assume 0.0
    }
}

void Student::addCourse(Course course){
    courses.push_back(course);
}

double Student::calculateGPA(){
    double total_Points = 0.0;
    int gpa;

    if(courses.size() == 0){
        cerr << "ERROR: The Courses list is empty for the student." << endl;
        return 0;
    }

    for(Course course : courses){
        total_Points += gradeToPoints(course.grade) * course.credits;
        gpa += course.credits;
    }

    return gpa > 0 ? total_Points / gpa : 0;
}
