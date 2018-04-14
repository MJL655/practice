// denglu.cpp : implementation file
//

#include "stdafx.h"
#include "Keshe.h"
#include "denglu.h"
#include "fstream.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// denglu dialog


denglu::denglu(CWnd* pParent /*=NULL*/)
	: CDialog(denglu::IDD, pParent)
{
	//
	//GotoDlgCtrl((CEdit*)GetDlgItem(IDC_Name));
	//{{AFX_DATA_INIT(denglu)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void denglu::DoDataExchange(CDataExchange* pDX)
{
	
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(denglu)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(denglu, CDialog)
	//{{AFX_MSG_MAP(denglu)
	ON_BN_CLICKED(IDCANCLE, OnCancle)
	ON_BN_CLICKED(IDC_NEW, OnNew)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// denglu message handlers

void denglu::OnOK() 
{
	vip p[20];
	fstream infile("d:\\personvip.txt",ios::in|ios::nocreate);
	int n=0;
	char q[100];
	BOOL end=FALSE;
	// TODO: Add extra validation here
	while(1)
	{
		for(int i=0;i<2;i++)
		{
			if(!(infile>>q))
			{
				end=TRUE;
				break;
			}
			if(i==0)
				strcpy(p[n].user_name,q);
			else
				strcpy(p[n].password,q);
		}
	    if(TRUE==end)
	    	break;
    n++;
	}
	infile.close();

	int j;
	CString m_name,m_password;
	GetDlgItemText(IDC_Name,m_name);
	GetDlgItemText(IDC_Password,m_password);
	if(m_name==""||m_password=="")
	{
		MessageBox("用户名或密码不能为空！","提示");
		GetDlgItem(IDC_Name)->SetFocus();
	}
	else 
		for(j=0;j<n;j++)
		{
			if(m_name==p[j].user_name&&m_password==p[j].password)
			{
				MessageBox("欢迎进入L.H公司员工管理系统！","欢迎进入");
				CDialog::OnOK();
				break;
			}
		}
	if(j==n)
	 {
		MessageBox("用户名或密码不正确！请重新输入","错误");
		SetDlgItemText(IDC_Name,"");
		SetDlgItemText(IDC_Password,"");
		GetDlgItem(IDC_Name)->SetFocus();
	 }
}


void denglu::OnCancle() 
{
	// TODO: Add your control notification handler code here
		CDialog::OnCancel();
		exit(0);
}

BOOL denglu::OnInitDialog() 
{
	
	CDialog::OnInitDialog();
	GetDlgItem(IDC_Name)->SetFocus();
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
#include "Zhuce.h"
void denglu::OnNew() 
{
	// TODO: Add your control notification handler code here
    Zhuce dlg;
	dlg.DoModal();
	
}
