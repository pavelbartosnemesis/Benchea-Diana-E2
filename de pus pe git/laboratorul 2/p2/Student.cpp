#pragma warning(disable : 4996).
#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

void Student::setname(char name[100]) 
{
	strcpy(nume, name);
}

char* Student::getname()
{
	return nume;
}

void Student::setmath(float nota)
{
	mate = nota;
}

void Student::seteng(float nota)
{
	eng = nota;
}

void Student::sethis(float nota)
{
	ist = nota;
}

float Student::getmath()
{
	return mate;
}
float Student::geteng()
{
	return eng;
}
float Student::gethis()
{
	return ist;
}
float Student::getgrade()
{
	float avg = (mate + ist + eng) / 3;
	return avg;
}