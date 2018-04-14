// NAMEID.cpp : implementation file
//

#include "stdafx.h"
#include "Keshe.h"
#include "NAMEID.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// NAMEID dialog


NAMEID::NAMEID(CWnd* pParent /*=NULL*/)
	: CDialog(NAMEID::IDD, pParent)
{
	//{{AFX_DATA_INIT(NAMEID)
	m_nameid = _T("");
	//}}AFX_DATA_INIT
}


void NAMEID::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(NAMEID)
	DDX_Text(pDX, IDC_EDIT1, m_nameid);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(NAMEID, CDialog)
	//{{AFX_MSG_MAP(NAMEID)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// NAMEID message handlers
