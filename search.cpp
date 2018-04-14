// search.cpp : implementation file
//

#include "stdafx.h"
#include "Keshe.h"
#include "search.h"
#include"ID.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// search dialog


search::search(CWnd* pParent /*=NULL*/)
	: CDialog(search::IDD, pParent)
{
	//{{AFX_DATA_INIT(search)
	m_switch = -1;
	//}}AFX_DATA_INIT
}


void search::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(search)
	DDX_Radio(pDX, IDC_RADIO1, m_switch);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(search, CDialog)
	//{{AFX_MSG_MAP(search)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// search message handlers

void search::OnRadio1() 
{
	// TODO: Add your control notification handler code here

	m_switch=1;
}

void search::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	m_switch=0;
}

void search::OnOK() 
{
	// TODO: Add extra validation here
/*	if(m_switch==1)
	{
		CDialog::OnOK();
		ID dlg;
		dlg.DoModal();
	}
	else
	{
        CDialog::OnOK();
	}*/
	CDialog::OnOK();
}
