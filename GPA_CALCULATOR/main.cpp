#include "gpa_calc.h"

int main(){
    // Construct Student
    Student student;

    cout << "Please enter your name.\n" << "Name: ";
    cin >> student.name;
    cout << endl;
    cout << "Please enter your stuID.\n" << "stuID: ";
    cin >> student.studentID;
    cout << endl;
    
    bool done = false;
    while(done){
        string d;
        string temp_name;
        int temp_num;
        char temp_char;
        Grade grade;
        
        // Asking for course name.
        cout << "Please enter your Course Name\n";
        cout << "Course Name: ";
        cin >> temp_name;
        cout << endl;

        // Asking for course Credits/Units
        cout << "Please enter the amount of units for the course\n";
        cout << "Number of Credits/Units: ";
        cin >> temp_num;
        toupper(temp_num);
        cout << endl;

        // Asking for course Letter Grade
        cout << "Please enter your letter grade (A, B, C, D, F)\n";
        cout << "Letter Grade: ";
        cin >> temp_char;
        toupper(temp_char);
        grade = getGradeFromInput(temp_char);
        cout << endl;

        student.addCourse(Course(temp_name, temp_num, grade));
        
        // Asking if done.
        cout << "Are you done adding courses?\n";
        cout << "(Y/N): ";
        cin >> d;
        if(d == "Y"){
            break;
        } else {
            continue;
        }
    }

    cout << "\nStudent Name: " << student.name << endl;
    cout << "Student ID Number: " << student.studentID << endl;
    cout << "GPA: " << student.calculateGPA() << endl;

    return 0;
}
