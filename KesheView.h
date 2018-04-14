// KesheView.h : interface of the CKesheView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_KESHEVIEW_H__625213BF_3C93_4DBC_9AF1_AD26C7C4C858__INCLUDED_)
#define AFX_KESHEVIEW_H__625213BF_3C93_4DBC_9AF1_AD26C7C4C858__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CKesheView : public CFormView
{
protected: // create from serialization only
	CKesheView();
	DECLARE_DYNCREATE(CKesheView)

public:
	
	//{{AFX_DATA(CKesheView)
	enum { IDD = IDD_KESHE_FORM };
	CListCtrl	m_ListCtrl;
	//}}AFX_DATA

// Attributes
public:
	//CKesheDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKesheView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CKesheView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CKesheView)
	afx_msg void OnButtonAdd();
	afx_msg void OnDoubleclickedButtonAdd();
	afx_msg void OnButtonQuit();
	afx_msg void OnButtonChange();
	afx_msg void OnButtonDel();
	afx_msg void OnBUTTON1Search();
	afx_msg void OnMyPrint();
	afx_msg void OnSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in KesheView.cpp
//inline CKesheDoc* CKesheView::GetDocument()
  // {// return (CKesheDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KESHEVIEW_H__625213BF_3C93_4DBC_9AF1_AD26C7C4C858__INCLUDED_)
