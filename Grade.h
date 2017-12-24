#pragma once
//using namespace std;
#include"Student.h"
class CGrade
{
protected:

	CString name;
	CStudent students[50];
	int studentNumber;

public:

	CGrade();
	CGrade(CString name);

	int  getNumber();

	CStudent* getstudents();
	CString getName();

	void addStudent(CStudent &student);
	void delStudent(CString name);
	void setName(CString name);

	~CGrade();

};

