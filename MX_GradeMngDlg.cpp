
// MX_GradeMngDlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMX_GradeMngDlg 对话框



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


// CMX_GradeMngDlg 消息处理程序

BOOL CMX_GradeMngDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMX_GradeMngDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMX_GradeMngDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//添加班级的按钮
//显示添加班级对话框
void CMX_GradeMngDlg::OnBnClickedAddgradeButton1()    
{
	// TODO: 在此添加控件通知处理程序代码
	CAddGrade addgradedlg;  //这是添加班级对话框的实例
	if(addgradedlg.DoModal() == IDOK)
	{
		if(addgradedlg.m_GradeName == "")
		{
			MessageBox(L"你输入的不能为空！");
			
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
				MessageBox(L"该班级已经存在！", L"友情提示！");
			}
			
		}	
	}

}

//删除班级按钮
void CMX_GradeMngDlg::OnBnClickedDeletegradeButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_GradeList.GetCurSel() < 0)
		MessageBox(L"你还没有选定班级，请重新选择一个班级！");
	else
	{
		CString str;
		m_GradeList.GetText(m_GradeList.GetCurSel(), str);
		//MessageBox(L"你确定要删除班级 " + str);
		int nvalue = MessageBox(L"是否真的要删除班级 " + str, L"友情提示！", 4 + 32 + 256);
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
//判断班级是否已经存在
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

//添加学生函数的按钮
void CMX_GradeMngDlg::OnBnClickedAddstudentButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	
	if(m_GradeList.GetCurSel() < 0)
	{
		MessageBox(TEXT("请选定一个班级再为其添加学生！"));
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
					MessageBox(L"你输入的不能为空！");
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

//删除学生按钮
void CMX_GradeMngDlg::OnBnClickedDeletestudentButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_GradeList.GetCurSel() < 0 || m_StuList.GetCurSel() < 0)
		MessageBox(L"你还没有选定班级或者学生，请重新选择一个班级或学生！");
	else
	{
		CString stu_str, gra_str;
		m_StuList.GetText(m_StuList.GetCurSel(), stu_str);
		m_GradeList.GetText(m_GradeList.GetCurSel(), gra_str);
		int nvalue = MessageBox(L"是否真的要删除班级 " + gra_str + " 学生 " + stu_str, L"友情提示！", 4 + 32 + 256);
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

//添加班级
void CMX_GradeMngDlg::addGrade(CGrade &g)           
{
	grades[gradeNumber++] = g;
}

//删除班级
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

//获取班级数量
int CMX_GradeMngDlg::getGradeNumber()                
{
	return gradeNumber;
}

//删除学生
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
	// TODO: 在此添加控件通知处理程序代码
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
