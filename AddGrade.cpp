// AddGrade.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "stdafx.h"
#include "MX_GradeMng.h"
#include "AddGrade.h"
#include "afxdialogex.h"


// CAddGrade �Ի���

IMPLEMENT_DYNAMIC(CAddGrade, CDialogEx)

CAddGrade::CAddGrade(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_AddGradeDlg, pParent)
	
	, m_GradeName(_T(""))
{

}

CAddGrade::~CAddGrade()
{
}

void CAddGrade::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, GradeName);
	DDX_Text(pDX, IDC_EDIT1, m_GradeName);
}


BEGIN_MESSAGE_MAP(CAddGrade, CDialogEx)
END_MESSAGE_MAP()


// CAddGrade ��Ϣ�������
