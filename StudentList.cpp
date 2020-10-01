// StudentList.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Program allows user to add, print, or delete students in a vector of student pointers.
// Author: Pranav Sharma
// DateL 9/30/2020

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
// initializes functions and vector pointer used to store Student pointers
void Add();
void Print();
void Delete();
struct Student;
vector<Student*>* vectptr = new vector<Student*>;
// the struct of Student
struct Student
{
    char first[80];
    char last[80];
    int id;
    float gpa;
};


int main()
{
    // Runs while user indicates they want to keep acessing the program
    bool playing = true;
    string input;
    while (playing == true) {
        // prompts user to enter a command, lets user know if the command is unreadable
        cout << "Enter a function\n";
        cin >> input;

        if (input == "ADD") {
            Add();
        }
        else if (input == "PRINT") {
            Print();
        }
        else if (input == "DELETE") {
            Delete();
        }
        else if (input == "QUIT") {
            playing = false;
        }
        else {
            cout << "Sorry! You didn't enter a proper function\n";
        }

    }
}

// Adds a Student pointer with properties to the vector using the vector pointer
void Add() {
    Student* s = new Student();
    cout << "Enter the student's first name: \n";
    cin >> s->first;
    cout << "Enter the student's last name: \n";
    cin >> s->last;
    cout << "Enter the student's ID: \n";
    cin >> s->id;
    cout << "Enter the student's GPA: \n";
    cin  >>s->gpa;
    (*vectptr).push_back(s);
}

// prints all the student properties of the students in the vector pointer
void Print() {
    bool ran = false;
    //code to iterate over a vector from: https://stackoverflow.com/questions/23318875/iterating-through-a-vector-of-pointers
    for (vector<Student*>::iterator it = (*vectptr).begin(); it != (*vectptr).end(); ++it) {
        ran = true;
        cout << "First name: " << (*it)->first << ", Last name: "<< (*it)->last << ", ID: " << (*it)->id << ", GPA: " << fixed << setprecision(2) << (*it)->gpa << endl;
    }
    // if the vector is empty, lets the user know
    if (ran == false) {
        cout << "Oops! Theres nothing in here\n";
    }
}

// Deletes a student pointer from the vector using the vector pointer
void Delete() {
    int input;
    int index = 0;
    cout << "Enter an ID to delete\n";
    cin >> input;
    for (vector<Student*>::iterator it = (*vectptr).begin(); it != (*vectptr).end(); ++it) {
        if ((*it)->id == input) {
            (*vectptr).erase((*vectptr).begin() + index);
            break;
        }
        index++;
    }
}

