// Add.cpp : implementation file
//

#include "stdafx.h"
#include "Keshe.h"
#include "Add.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Add dialog
struct
{
	int id;
	char name[20];
	char sex[10];
	int year,month;
	char place[30];
	float salary;

}person[];

Add::Add(CWnd* pParent /*=NULL*/)
	: CDialog(Add::IDD, pParent)
{
	//{{AFX_DATA_INIT(Add)
	m_name = _T("");
	m_salary = _T("");
	m_id = _T("");
	m_month = _T("");
	m_year = _T("");
	m_sex = -1;

	m_place1 = _T("");
	//}}AFX_DATA_INIT
}


void Add::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Add)
	DDX_Control(pDX, IDC_PLACE, m_placechange);
	DDX_Control(pDX, IDOK, m_strOKText);
	DDX_Text(pDX, IDC_Name, m_name);
	DDX_Text(pDX, IDC_SALARY, m_salary);
	DDX_Text(pDX, IDC_ID, m_id);
	DDX_Text(pDX, IDC_MONTH, m_month);
	DDX_Text(pDX, IDC_YEAR, m_year);
	DDX_Radio(pDX, IDC_MALE, m_sex);
	DDX_CBString(pDX, IDC_PLACE, m_place1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Add, CDialog)
	//{{AFX_MSG_MAP(Add)
	ON_BN_CLICKED(IDC_MALE, OnMale)
	ON_BN_CLICKED(IDC_FAMALE, OnFamale)
//	ON_BN_CLICKED(IDC_SEARCH, OnSearch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Add message handlers

void Add::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
	return;
}
#include"Keshe.h"
#include "KesheDoc.h"
#include "KesheView.h"
#include "fstream.h"

void Add::OnOK() 
{
	int n=((CButton *)GetDlgItem(IDC_MALE))->GetCheck();
	int j=((CButton *)GetDlgItem(IDC_FAMALE))->GetCheck();
	// TODO: Add extra validation here
	UpdateData();
	m_id.TrimLeft();
	m_name.TrimLeft();
	if (m_id.IsEmpty())
		MessageBox("编号不能为空！",TEXT("提示"),MB_ICONWARNING);
	else if (m_name.IsEmpty())
		MessageBox("姓名不能为空！",TEXT("提示"),MB_ICONWARNING);
	else if (m_year.IsEmpty() || m_month.IsEmpty())
		MessageBox("出生日期不能为空！",TEXT("提示"),MB_ICONWARNING);
	else if(n==0&&j==0)
		MessageBox("性别不能为空！",TEXT("提示"),MB_ICONWARNING);
	else if (m_salary.IsEmpty())
		MessageBox("工资不能为空！",TEXT("提示"),MB_ICONWARNING);
	//else if(m_month>=12)
		//MessageBox("出生日期有误，请重新填写！",TEXT("提示"),MB_ICONWARNING);
	else	
	{
	
		CDialog::OnOK();
	}


}

void Add::OnMale() 
{
	// TODO: Add your control notification handler code here
	m_sex=0;
	
}

void Add::OnFamale() 
{
	// TODO: Add your control notification handler code here
	m_sex=1;
}

void Add::OnSearch() 
{
	// TODO: Add your control notification handler code here
	
}
