#pragma once


// CAddStudent �Ի���

class CAddStudent : public CDialogEx
{
	DECLARE_DYNAMIC(CAddStudent)

public:
	CAddStudent(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddStudent();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	// ��ӵ�ѧ������
	CString m_stu_name;
	// ��ӵ�ѧ��ѧ��
	//CString m_stu_number;
	afx_msg void OnBnClickedCancel();
};
