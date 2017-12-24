
// MX_GradeMngDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include"Grade.h"


// CMX_GradeMngDlg �Ի���
class CMX_GradeMngDlg : public CDialogEx
{
// ����
public:
	CMX_GradeMngDlg(CWnd* pParent = NULL);	// ��׼���캯��
	void addGrade(CGrade &g);            //��Ӱ༶
	void deleteGrade(CString name);		//ɾ���༶
	int getGradeNumber();                //��ȡ�༶����
	void deleteStudent(CString gstr, CString sstr); //ɾ��ѧ��
	

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MX_GRADEMNG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	CGrade grades[50];   //��ӵİ༶��Ա
	int gradeNumber;		//�༶����

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAddgradeButton1();
	bool IsIniGrades(CString name);
	// ��Ӧ�༶�б�ı���
	CListBox m_GradeList;
	afx_msg void OnBnClickedDeletegradeButton2();
	afx_msg void OnBnClickedAddstudentButton3();
	// ��ʾ��ѧ���б�
	CListBox m_StuList;
	afx_msg void OnBnClickedDeletestudentButton4();
//	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
//	afx_msg void OnLbnDblclkList1();
	afx_msg void OnLbnSelchangeList1();
};
