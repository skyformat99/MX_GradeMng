
// MX_GradeMngDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "stdafx.h"
#include "MX_GradeMng.h"
#include "MX_GradeMngDlg.h"
#include "afxdialogex.h"
#include "AddGrade.h"
#include "Addstudent.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMX_GradeMngDlg �Ի���



CMX_GradeMngDlg::CMX_GradeMngDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MX_GRADEMNG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
	gradeNumber = 0;
}

void CMX_GradeMngDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_LIST1, gradelist);
	DDX_Control(pDX, IDC_LIST1, m_GradeList);
	DDX_Control(pDX, IDC_LIST2, m_StuList);
}

BEGIN_MESSAGE_MAP(CMX_GradeMngDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_AddGrade_BUTTON1, &CMX_GradeMngDlg::OnBnClickedAddgradeButton1)
	ON_BN_CLICKED(IDC_DeleteGrade_BUTTON2, &CMX_GradeMngDlg::OnBnClickedDeletegradeButton2)
	ON_BN_CLICKED(IDC_AddStudent_BUTTON3, &CMX_GradeMngDlg::OnBnClickedAddstudentButton3)
	ON_BN_CLICKED(IDC_DeleteStudent_BUTTON4, &CMX_GradeMngDlg::OnBnClickedDeletestudentButton4)
//	ON_WM_RBUTTONDBLCLK()
//	ON_LBN_DBLCLK(IDC_LIST1, &CMX_GradeMngDlg::OnLbnDblclkList1)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMX_GradeMngDlg::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// CMX_GradeMngDlg ��Ϣ�������

BOOL CMX_GradeMngDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMX_GradeMngDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMX_GradeMngDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMX_GradeMngDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//��Ӱ༶�İ�ť
//��ʾ��Ӱ༶�Ի���
void CMX_GradeMngDlg::OnBnClickedAddgradeButton1()    
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CAddGrade addgradedlg;  //������Ӱ༶�Ի����ʵ��
	if(addgradedlg.DoModal() == IDOK)
	{
		if(addgradedlg.m_GradeName == "")
		{
			MessageBox(L"������Ĳ���Ϊ�գ�");
			
		}
		else
		{
			CString name = addgradedlg.m_GradeName;

			if(IsIniGrades(name))
			{
				CGrade g(name);
				this->addGrade(g);
				this->m_GradeList.AddString(name);
			}
			else
			{
				MessageBox(L"�ð༶�Ѿ����ڣ�", L"������ʾ��");
			}
			
		}	
	}

}

//ɾ���༶��ť
void CMX_GradeMngDlg::OnBnClickedDeletegradeButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_GradeList.GetCurSel() < 0)
		MessageBox(L"�㻹û��ѡ���༶��������ѡ��һ���༶��");
	else
	{
		CString str;
		m_GradeList.GetText(m_GradeList.GetCurSel(), str);
		//MessageBox(L"��ȷ��Ҫɾ���༶ " + str);
		int nvalue = MessageBox(L"�Ƿ����Ҫɾ���༶ " + str, L"������ʾ��", 4 + 32 + 256);
		if (nvalue == IDYES)
		{
			this->deleteGrade(str);
			m_GradeList.DeleteString(m_GradeList.GetCurSel());
			m_StuList.ResetContent();
		}
		else
		{

		}

	}

}
//�жϰ༶�Ƿ��Ѿ�����
bool CMX_GradeMngDlg::IsIniGrades(CString name)
{
	bool flag = true;
	for(int i = 0;i<gradeNumber;i++)
	{	
		if (grades[i].getName() == name)
		{
			flag = false;
			break;
		}
			
	}
	return flag;
}

//���ѧ�������İ�ť
void CMX_GradeMngDlg::OnBnClickedAddstudentButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	if(m_GradeList.GetCurSel() < 0)
	{
		MessageBox(TEXT("��ѡ��һ���༶��Ϊ�����ѧ����"));
	}

	CString gradeName;
	m_GradeList.GetText(m_GradeList.GetCurSel(), gradeName);

	for (int i =0; i < gradeNumber; i++)
	{
		if (grades[i].getName() == gradeName)
		{
			CAddStudent addstudlg;
			if (addstudlg.DoModal() == IDOK)
			{
				if (addstudlg.m_stu_name == "" )
				{
					MessageBox(L"������Ĳ���Ϊ�գ�");
				}
				else
				{
					CStudent s;
					s.setName(addstudlg.m_stu_name);
					grades[i].addStudent(s);
					m_StuList.AddString(addstudlg.m_stu_name);
				}
		}
	}
	
	}

}

//ɾ��ѧ����ť
void CMX_GradeMngDlg::OnBnClickedDeletestudentButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_GradeList.GetCurSel() < 0 || m_StuList.GetCurSel() < 0)
		MessageBox(L"�㻹û��ѡ���༶����ѧ����������ѡ��һ���༶��ѧ����");
	else
	{
		CString stu_str, gra_str;
		m_StuList.GetText(m_StuList.GetCurSel(), stu_str);
		m_GradeList.GetText(m_GradeList.GetCurSel(), gra_str);
		int nvalue = MessageBox(L"�Ƿ����Ҫɾ���༶ " + gra_str + " ѧ�� " + stu_str, L"������ʾ��", 4 + 32 + 256);
		if (nvalue == IDYES)
		{
			this->deleteStudent(gra_str, stu_str);
			m_StuList.DeleteString(m_StuList.GetCurSel());
		}
		else
		{

		}


	}
}

//��Ӱ༶
void CMX_GradeMngDlg::addGrade(CGrade &g)           
{
	grades[gradeNumber++] = g;
}

//ɾ���༶
void CMX_GradeMngDlg::deleteGrade(CString name)
{
	int i;
	for (i = 0; i < 50; i++)
	{
		if (grades[i].getName() == name)
			break;
	}
	if (i >= gradeNumber)
		return;
	for (int j = i; j < gradeNumber; j++)
	{
		grades[j] = grades[j + 1];
		gradeNumber--;
	}
}

//��ȡ�༶����
int CMX_GradeMngDlg::getGradeNumber()                
{
	return gradeNumber;
}

//ɾ��ѧ��
void CMX_GradeMngDlg::deleteStudent(CString gstr, CString sstr)
{
	for (int i = 0;i < gradeNumber; i++)
	{
		if(grades[i].getName() == gstr)
		{
			grades[i].delStudent(sstr);
		}
	}
}

void CMX_GradeMngDlg::OnLbnSelchangeList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_StuList.ResetContent();

	CString str, name;
	CStudent *stu;
	m_GradeList.GetText(m_GradeList.GetCurSel(), str);
	for (int i = 0; i<gradeNumber; i++)
	{
		if (grades[i].getName() == str)
		{
			stu = grades[i].getstudents();
			for (int j = 0; j<grades[i].getNumber(); j++)
			{
				m_StuList.AddString(stu->getname());
				stu++;
			}

		}
	}
}
