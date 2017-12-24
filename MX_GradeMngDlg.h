
// MX_GradeMngDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include"Grade.h"


// CMX_GradeMngDlg 对话框
class CMX_GradeMngDlg : public CDialogEx
{
// 构造
public:
	CMX_GradeMngDlg(CWnd* pParent = NULL);	// 标准构造函数
	void addGrade(CGrade &g);            //添加班级
	void deleteGrade(CString name);		//删除班级
	int getGradeNumber();                //获取班级数量
	void deleteStudent(CString gstr, CString sstr); //删除学生
	

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MX_GRADEMNG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	CGrade grades[50];   //添加的班级成员
	int gradeNumber;		//班级数量

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAddgradeButton1();
	bool IsIniGrades(CString name);
	// 对应班级列表的变量
	CListBox m_GradeList;
	afx_msg void OnBnClickedDeletegradeButton2();
	afx_msg void OnBnClickedAddstudentButton3();
	// 显示的学生列表
	CListBox m_StuList;
	afx_msg void OnBnClickedDeletestudentButton4();
//	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
//	afx_msg void OnLbnDblclkList1();
	afx_msg void OnLbnSelchangeList1();
};
