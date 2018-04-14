// KesheDoc.cpp : implementation of the CKesheDoc class
//

#include "stdafx.h"
#include "Keshe.h"

#include "KesheDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKesheDoc

IMPLEMENT_DYNCREATE(CKesheDoc, CDocument)

BEGIN_MESSAGE_MAP(CKesheDoc, CDocument)
	//{{AFX_MSG_MAP(CKesheDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKesheDoc construction/destruction

CKesheDoc::CKesheDoc()
{
	// TODO: add one-time construction code here

}

CKesheDoc::~CKesheDoc()
{
}

BOOL CKesheDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CKesheDoc serialization

void CKesheDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CKesheDoc diagnostics

#ifdef _DEBUG
void CKesheDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKesheDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKesheDoc commands
