#if !defined(AFX_ADD_H__930F323D_54D4_4B04_B020_462234FA9BE7__INCLUDED_)
#define AFX_ADD_H__930F323D_54D4_4B04_B020_462234FA9BE7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Add.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Add dialog
struct Person
{
	char name[17];
	char id[15];
	char sex[5];
	char year[5];
	char month[3];
	char place[21];
	char salary[6];


};

class Add : public CDialog
{
// Construction
public:
	Add(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Add)
	enum { IDD = IDD_CPerson };
	CComboBox	m_placechange;
	CButton	m_strOKText;
	CString	m_name;
	CString	m_salary;
	CString	m_id;
	CString	m_month;
	CString	m_year;
	int		m_sex;
	CString	m_place1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Add)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Add)
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnMale();
	afx_msg void OnFamale();
	afx_msg void OnSearch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADD_H__930F323D_54D4_4B04_B020_462234FA9BE7__INCLUDED_)
