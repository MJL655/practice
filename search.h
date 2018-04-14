#if !defined(AFX_SEARCH_H__765AB086_6B27_432B_8D9B_A995DF17D098__INCLUDED_)
#define AFX_SEARCH_H__765AB086_6B27_432B_8D9B_A995DF17D098__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// search.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// search dialog

class search : public CDialog
{
// Construction
public:
	search(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(search)
	enum { IDD = IDD_DIALOG2 };
	int		m_switch;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(search)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(search)
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCH_H__765AB086_6B27_432B_8D9B_A995DF17D098__INCLUDED_)
