/*
    Taylor, Charlie
    Ziller, Joseph

    April 5,2021

    CS A200
    Lab 3: Stacks Part 2
*/

#include "Student.h"
using namespace std;

ostream& operator<<(ostream& out, const Student& student2Print)
{
    out << student2Print.grade << " " << student2Print.id;
    return out;
}