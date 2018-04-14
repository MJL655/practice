// ID.cpp : implementation file
//

#include "stdafx.h"
#include "Keshe.h"
#include "ID.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ID dialog


ID::ID(CWnd* pParent /*=NULL*/)
	: CDialog(ID::IDD, pParent)
{
	//{{AFX_DATA_INIT(ID)
	m_id = _T("");
	//}}AFX_DATA_INIT
}


void ID::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ID)
	DDX_Text(pDX, IDC_EDIT1, m_id);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ID, CDialog)
	//{{AFX_MSG_MAP(ID)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ID message handlers

void ID::OnOK() 
{
	// TODO: Add extra validation here  
//	CString c_user;  
  //  m_id.GetWindowText(c_user);  
	//MessageBox(CString(c_user));
	CDialog::OnOK();
}

void ID::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();

}
