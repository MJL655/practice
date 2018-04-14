#if !defined(AFX_ZHUCE_H__88E79FCC_73F5_4DB3_BA52_80554CBF6C2F__INCLUDED_)
#define AFX_ZHUCE_H__88E79FCC_73F5_4DB3_BA52_80554CBF6C2F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Zhuce.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Zhuce dialog
struct vip1
{
	char user_name[20];
	char password[7];
};
class Zhuce : public CDialog
{
// Construction
public:
	Zhuce(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Zhuce)
	enum { IDD = IDD_DIALOG3 };
	CEdit	m_again;
	CEdit	m_edit2;
	CEdit	m_edit1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Zhuce)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Zhuce)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZHUCE_H__88E79FCC_73F5_4DB3_BA52_80554CBF6C2F__INCLUDED_)
