#include "stdafx.h"
#include "Student.h"


CStudent::CStudent()
{
	name = "noname";
}


CStudent::~CStudent()
{
}

CString CStudent::getname()
{
	return name;
}

void CStudent::setName(CString name)
{
	this->name = name;
}