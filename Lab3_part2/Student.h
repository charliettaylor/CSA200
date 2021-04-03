#ifndef STUDENT_H
#define STUDENT_H

class Student
{
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