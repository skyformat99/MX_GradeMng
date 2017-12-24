// AddGrade.cpp : 实现文件
//

#include "stdafx.h"
#include "stdafx.h"
#include "MX_GradeMng.h"
#include "AddGrade.h"
#include "afxdialogex.h"


// CAddGrade 对话框

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


// CAddGrade 消息处理程序
