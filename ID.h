#if !defined(AFX_ID_H__CEBD7F76_A901_480C_8F85_EA168099FCE7__INCLUDED_)
#define AFX_ID_H__CEBD7F76_A901_480C_8F85_EA168099FCE7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ID.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ID dialog

class ID : public CDialog
{
// Construction
public:
	ID(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ID)
	enum { IDD = IDD_DIALOG4 };
	CString	m_id;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ID)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ID)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ID_H__CEBD7F76_A901_480C_8F85_EA168099FCE7__INCLUDED_)
