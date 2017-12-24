#pragma once


// CAddGrade 对话框

class CAddGrade : public CDialogEx
{
	DECLARE_DYNAMIC(CAddGrade)

public:
	CAddGrade(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddGrade();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AddGradeDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 添加的班级名称
	CString m_GradeName;
};
