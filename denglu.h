#if !defined(AFX_DENGLU_H__354471A1_CE39_484A_915C_E8C63B89FEAA__INCLUDED_)
#define AFX_DENGLU_H__354471A1_CE39_484A_915C_E8C63B89FEAA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// denglu.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// denglu dialog
struct vip
{
	char user_name[20];
	char password[7];
};
class denglu : public CDialog
{
// Construction
public:
	denglu(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(denglu)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(denglu)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(denglu)
	virtual void OnOK();
	afx_msg void OnCancle();
	virtual BOOL OnInitDialog();
	afx_msg void OnNew();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DENGLU_H__354471A1_CE39_484A_915C_E8C63B89FEAA__INCLUDED_)
