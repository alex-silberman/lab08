// file: r_functions.cpp
// Alex Silberman
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
// Define the functions, per the list in r_headers.h

//pre: array is an UndergradStudents array, size is the amounnt of students
//post: uses a bubble sort to alphabetize using the last name
void NameSort(UndergradStudents array[], int size) {
    for (int pass = 0; pass < size - 1; pass++) { // compare students and swap if out of order
        for (int i = 0; i < size - 1 - pass; i++) {
            if (array[i].lastName > array[i + 1].lastName) {
                UndergradStudents temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp; // swap student
            }
        }
    }
}


// Pre: us is an empty array with space for 20 students
// Post: fills the array with student data entered by the user, size stores the number of students
void InitializeStructures(UndergradStudents us[], int &size) {
    cout << "STUDENT RECORDS:" << endl;

    size = 0;

    while (size < 20) { // continue asking for student data until quit or array fills up

        int studentNum = size + 1;

        cout << "Student ";
        if (studentNum < 10) 
            cout << "0";
        cout << studentNum << ":Enter first name (or x to quit): ";

        string first;
        cin >> first;

        if (first == "x")
            break;
        
        us[size].studentID = studentNum;
        us[size].firstName = first;

        cout << "Student ";
        if (studentNum < 10) 
            cout << "0";
        cout << studentNum << ":Enter last name: ";
        cin >> us[size].lastName;

        cout << "Student ";
        if (studentNum < 10)
            cout << "0";
        cout << studentNum << ":Enter major: ";
        cin >> us[size].major;

        cout << "Student ";
        if (studentNum < 10) 
            cout << "0";
        cout << studentNum << ":Enter GPA Year 1: ";
        cin >> us[size].gpa1;

        cout << "Student ";
        if (studentNum < 10) 
            cout << "0";
        cout << studentNum << ":Enter GPA Year 2: ";
        cin >> us[size].gpa2;

        cout << "Student ";
        if (studentNum < 10) 
            cout << "0";
        cout << studentNum << ":Enter GPA Year 3: ";
        cin >> us[size].gpa3;

        cout << "Student ";
        if (studentNum < 10) 
            cout << "0";
        cout << studentNum << ":Enter GPA Year 4: ";
        cin >> us[size].gpa4;

        size++;
    }
}


//pre: us contains 'size' students with data
//post: students are sorted by last name and written to an output file
void WriteResults(ofstream &outf, UndergradStudents us[], int size) {

    NameSort(us, size); //sort students by last name

    outf.open(OUTPUTFILE);

    outf << "These are the results sorted by last name:" << endl;

    for (int i = 0; i < size; i++) { // write student's information and GPA to the file

        float avg = (us[i].gpa1 + us[i].gpa2 + us[i].gpa3 + us[i].gpa4) / 4.0;

        avg = int(avg * 100 + 0.5) / 100.0;

        outf << "ID# " << us[i].studentID << ": "
             << us[i].lastName << ": "
             << us[i].firstName << ": "
             << us[i].major << ": "
             << avg << endl;
    }

    outf.close();
}