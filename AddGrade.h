#pragma once


// CAddGrade �Ի���

class CAddGrade : public CDialogEx
{
	DECLARE_DYNAMIC(CAddGrade)

public:
	CAddGrade(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddGrade();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AddGradeDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	// ��ӵİ༶����
	CString m_GradeName;
};
