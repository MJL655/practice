// Zhuce.cpp : implementation file
//

#include "stdafx.h"
#include "Keshe.h"
#include "Zhuce.h"
#include "fstream.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Zhuce dialog


Zhuce::Zhuce(CWnd* pParent /*=NULL*/)
	: CDialog(Zhuce::IDD, pParent)
{
	//{{AFX_DATA_INIT(Zhuce)
	//}}AFX_DATA_INIT
}


void Zhuce::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Zhuce)
	DDX_Control(pDX, IDC_EDIT2, m_again);
	DDX_Control(pDX, IDC_EDIT3, m_edit2);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Zhuce, CDialog)
	//{{AFX_MSG_MAP(Zhuce)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Zhuce message handlers

void Zhuce::OnOK() 
{
	
	// TODO: Add extra validation here	
	CString csX1;  
    m_edit1.GetWindowText(csX1);
	CString csX3;  
    m_again.GetWindowText(csX3);
	CString csX2;  
	m_edit2.GetWindowText(csX2);
	fstream infile("d:\\personvip.txt",ios::in|ios::nocreate);
	vip1 p[100];
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
	int x=0;
	for(j=0;j<n;j++)
		{
			if(csX1==p[j].user_name)
			{
				x=1;
				MessageBox("该用户名存在，请直接登录！");
				CDialog::OnOK();
				break;
			}
		}
	if(x==0)
	{
		if(csX3==csX2)
		{
			fstream outfile("d:\\personvip.txt",ios::out|ios::ate );
			CString str;
			str=csX1+" "+csX2;
			outfile<<str;
			outfile<<endl;
			outfile.close();
			MessageBox("保存成功！");
   			CDialog::OnOK();
		}
		else
		{
			MessageBox("两次输入的密码不一致！","错误");	
	    	GetDlgItem(IDC_EDIT3)->SetFocus();
		}
	}
}
