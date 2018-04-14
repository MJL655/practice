// Keshe.h : main header file for the KESHE application
//

#if !defined(AFX_KESHE_H__DCD02E64_512A_497F_AD15_23D47178A917__INCLUDED_)
#define AFX_KESHE_H__DCD02E64_512A_497F_AD15_23D47178A917__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CKesheApp:
// See Keshe.cpp for the implementation of this class
//

class CKesheApp : public CWinApp
{
public:
	CKesheApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKesheApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CKesheApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KESHE_H__DCD02E64_512A_497F_AD15_23D47178A917__INCLUDED_)
