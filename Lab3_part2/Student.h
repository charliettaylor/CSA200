/*
    Taylor, Charlie
    Ziller, Joseph

    April 5,2021

    CS A200
    Lab 3: Stacks Part 2
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class Student
{
    friend std::ostream& operator<<(std::ostream& out, const Student&);
public:
    Student() : id(0), grade('X') {}
    Student(int newId, char newGrade) :
        id(newId), grade(newGrade) {}
    ~Student() {}
private:
    int id;
    char grade;
};

#endif