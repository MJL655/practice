#if !defined(AFX_NAMEID_H__B06964EA_D167_4746_901E_A12AA74E3AB7__INCLUDED_)
#define AFX_NAMEID_H__B06964EA_D167_4746_901E_A12AA74E3AB7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NAMEID.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// NAMEID dialog

class NAMEID : public CDialog
{
// Construction
public:
	NAMEID(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(NAMEID)
	enum { IDD = IDD_DIALOG5 };
	CString	m_nameid;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(NAMEID)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(NAMEID)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NAMEID_H__B06964EA_D167_4746_901E_A12AA74E3AB7__INCLUDED_)
