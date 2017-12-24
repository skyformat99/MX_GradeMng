#include "stdafx.h"
#include "Grade.h"
//#include"Student.h"

CGrade::CGrade()
{
	name = "noname";
	studentNumber = 0;
}

CGrade::~CGrade()
{
}

CGrade::CGrade(CString name)
{
	this->name = name;
	studentNumber = 0;
}

void CGrade::setName(CString name)
{
	this->name = name;
}

CString CGrade::getName()
{
	return name;
}

int CGrade::getNumber()
{
	return studentNumber;
}

CStudent* CGrade::getstudents()
{
	return students;
}

void CGrade::addStudent(CStudent &student)
{
	students[studentNumber++]= student;
	
}

void CGrade::delStudent(CString name)
{
	int i;
	for (i = 0;i<50;i++)
	{
		if (students[i].getname() == name) 
			break;
	}
	if (i >= 50) return;
	for (int j = i; j < studentNumber; j++)
	{
		students[j] = students[j + 1];
	}
	studentNumber--;
}