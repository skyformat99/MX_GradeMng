// AddStudent.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MX_GradeMng.h"
#include "AddStudent.h"
#include "afxdialogex.h"


// CAddStudent �Ի���

IMPLEMENT_DYNAMIC(CAddStudent, CDialogEx)

CAddStudent::CAddStudent(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_stu_name(_T(""))
	//, m_stu_number(_T(""))
{

}

CAddStudent::~CAddStudent()
{
}

void CAddStudent::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_stu_name);
//	DDX_Text(pDX, IDC_EDIT2, m_stu_number);
}


BEGIN_MESSAGE_MAP(CAddStudent, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CAddStudent::OnBnClickedCancel)
END_MESSAGE_MAP()


// CAddStudent ��Ϣ�������


void CAddStudent::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}
