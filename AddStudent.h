#pragma once


// CAddStudent 对话框

class CAddStudent : public CDialogEx
{
	DECLARE_DYNAMIC(CAddStudent)

public:
	CAddStudent(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddStudent();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 添加的学生姓名
	CString m_stu_name;
	// 添加的学生学号
	//CString m_stu_number;
	afx_msg void OnBnClickedCancel();
};
