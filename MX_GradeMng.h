
// MX_GradeMng.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMX_GradeMngApp: 
// �йش����ʵ�֣������ MX_GradeMng.cpp
//

class CMX_GradeMngApp : public CWinApp
{
public:
	CMX_GradeMngApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMX_GradeMngApp theApp;