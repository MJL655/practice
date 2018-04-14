// KesheView.cpp : implementation of the CKesheView class
//

#include "stdafx.h"
#include "Keshe.h"

#include "KesheDoc.h"
#include "KesheView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKesheView

IMPLEMENT_DYNCREATE(CKesheView, CFormView)

BEGIN_MESSAGE_MAP(CKesheView, CFormView)
	//{{AFX_MSG_MAP(CKesheView)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_DOUBLECLICKED(IDC_BUTTON_ADD, OnDoubleclickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_QUIT, OnButtonQuit)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE, OnButtonChange)
	ON_BN_CLICKED(IDC_BUTTON_DEL, OnButtonDel)
	ON_BN_CLICKED(IDC_BUTTON1_Search, OnBUTTON1Search)
	ON_BN_CLICKED(IDC_PRINT, OnMyPrint)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKesheView construction/destruction

CKesheView::CKesheView()
	: CFormView(CKesheView::IDD)
{
	//{{AFX_DATA_INIT(CKesheView)
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CKesheView::~CKesheView()
{
}

void CKesheView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKesheView)
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
	//}}AFX_DATA_MAP
}

BOOL CKesheView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CKesheView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	CRect rect;   
    // ��ȡ��������б���ͼ�ؼ���λ�úʹ�С   
	m_ListCtrl.GetClientRect(&rect);   
	// Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����   
	m_ListCtrl.SetExtendedStyle(m_ListCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);   
	m_ListCtrl.InsertColumn(0, _T("���"), LVCFMT_LEFT, rect.Width()/7);   
    m_ListCtrl.InsertColumn(1, _T("����"), LVCFMT_LEFT, rect.Width()/6);   
    m_ListCtrl.InsertColumn(2, _T("�Ա�"), LVCFMT_LEFT, rect.Width()/8);
	m_ListCtrl.InsertColumn(3, _T("��������"),LVCFMT_LEFT , rect.Width()/5);
	m_ListCtrl.InsertColumn(4, _T("ְλ"), LVCFMT_LEFT, rect.Width()/5);
	m_ListCtrl.InsertColumn(5, _T("н��"), LVCFMT_LEFT, rect.Width()/6);

/*	m_ListCtrl.InsertItem(0, _T("001"));   
    m_ListCtrl.SetItemText(0, 1, _T("�ϼ���"));   
    m_ListCtrl.SetItemText(0, 2, _T("Ů")); 
	m_ListCtrl.SetItemText(0, 3, _T("1998��01��"));     
	m_ListCtrl.SetItemText(0, 4, _T("����ʦ"));   
	m_ListCtrl.SetItemText(0, 5, _T("10000")); 

    m_ListCtrl.InsertItem(1, _T("002"));   
    m_ListCtrl.SetItemText(1, 1, _T("���"));   
    m_ListCtrl.SetItemText(1, 2, _T("Ů"));   
	m_ListCtrl.SetItemText(1, 3, _T("1998��05��"));   
	m_ListCtrl.SetItemText(1, 4, _T("CEO"));   
	m_ListCtrl.SetItemText(1, 5, _T("20000"));  
	
  
	m_ListCtrl.InsertItem(0, _T("003"));  
    m_ListCtrl.SetItemText(0, 1, _T("������"));   
    m_ListCtrl.SetItemText(0, 2, _T("��")); 
	m_ListCtrl.SetItemText(0, 3, _T("1976��7��"));     
	m_ListCtrl.SetItemText(0, 4, _T("���ι���ʦ"));   
	m_ListCtrl.SetItemText(0, 5, _T("11000")); 

	m_ListCtrl.InsertItem(0, _T("004"));   
    m_ListCtrl.SetItemText(0, 1, _T("���"));   
    m_ListCtrl.SetItemText(0, 2, _T("Ů")); 
	m_ListCtrl.SetItemText(0, 3, _T("1978��5��"));     
	m_ListCtrl.SetItemText(0, 4, _T("�쵼"));   
	m_ListCtrl.SetItemText(0, 5, _T("14000")); 

	m_ListCtrl.InsertItem(0, _T("005"));   
    m_ListCtrl.SetItemText(0, 1, _T("������"));   
    m_ListCtrl.SetItemText(0, 2, _T("Ů")); 
	m_ListCtrl.SetItemText(0, 3, _T("1997��11��"));     
	m_ListCtrl.SetItemText(0, 4, _T("����"));   
	m_ListCtrl.SetItemText(0, 5, _T("8000"));
	
	m_ListCtrl.InsertItem(0, _T("006"));   
    m_ListCtrl.SetItemText(0, 1, _T("������"));   
    m_ListCtrl.SetItemText(0, 2, _T("��")); 
	m_ListCtrl.SetItemText(0, 3, _T("1998��6��"));     
	m_ListCtrl.SetItemText(0, 4, _T("����"));   
	m_ListCtrl.SetItemText(0, 5, _T("5000")); 

	m_ListCtrl.InsertItem(0, _T("007"));   
    m_ListCtrl.SetItemText(0, 1, _T("������"));   
    m_ListCtrl.SetItemText(0, 2, _T("��")); 
	m_ListCtrl.SetItemText(0, 3, _T("1996��5��"));     
	m_ListCtrl.SetItemText(0, 4, _T("����"));   
	m_ListCtrl.SetItemText(0, 5, _T("13000")); */

}

/////////////////////////////////////////////////////////////////////////////
// CKesheView printing

BOOL CKesheView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CKesheView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CKesheView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CKesheView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CKesheView diagnostics

#ifdef _DEBUG
void CKesheView::AssertValid() const
{
	CFormView::AssertValid();
}

void CKesheView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CKesheDoc* CKesheView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKesheDoc)));
	return (CKesheDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKesheView message handlers
#include"Add.h"
#include "fstream.h"
void CKesheView::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	
    Add dlg;
	if(IDOK != dlg.DoModal())
		return;

	LVFINDINFO info;
	info.flags = LVFI_PARTIAL|LVFI_STRING;
	info.psz = dlg.m_id;

	if (m_ListCtrl.FindItem(&info)!=-1)   //���ҵ�
	{
		CString str;
		str.Format("���Ϊ%s����Ա��Ϣ�Ѿ���ӹ���",dlg.m_id);
		MessageBox(str);
		return;
	}
	
	m_ListCtrl.InsertItem(0, dlg.m_id);
	m_ListCtrl.SetItemText(0, 1,dlg.m_name);
    if (dlg.m_sex==0)
		m_ListCtrl.SetItemText(0,2,"��");
	else if(dlg.m_sex==1)
	    m_ListCtrl.SetItemText(0,2,"Ů");
	if(dlg.m_year!=NULL&&dlg.m_month!=NULL)
		m_ListCtrl.SetItemText(0, 3,dlg. m_year + "��"+ dlg.m_month + "��");
	m_ListCtrl.SetItemText(0, 4,dlg.m_place1);
	m_ListCtrl.SetItemText(0, 5,dlg. m_salary);
}


void CKesheView::OnDoubleclickedButtonAdd() 
{
	// TODO: Add your control notification handler code here
	
}

void CKesheView::OnButtonQuit() 
{
	// TODO: Add your control notification handler code here
	if(MessageBox("ȷ��Ҫ�˳�����",TEXT("��ʾ"),MB_OKCANCEL|MB_ICONWARNING) != IDOK)
		return;
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(),WM_CLOSE,0,0);

}

void CKesheView::OnButtonChange() 
{
	// TODO: Add your control notification handler code here

// ��ȡ��ѡ����б���������
	POSITION pos;
	pos = m_ListCtrl.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		MessageBox("�㻹û��ѡ���б��",TEXT("��ʾ"),MB_ICONWARNING);
		return;
	}
	int nItem = m_ListCtrl.GetNextSelectedItem( pos );
	Add dlg;
	dlg.m_id = m_ListCtrl.GetItemText( nItem, 0);
	dlg.m_name = m_ListCtrl.GetItemText( nItem, 1);
	if (m_ListCtrl.GetItemText( nItem, 2)=="Ů")
		dlg.m_sex=TRUE;
	else
		dlg.m_sex=FALSE;
	CString date = m_ListCtrl.GetItemText( nItem, 3);
	//��ȡ�ַ���
	int a = date.Find("��");
	int b = date.Find("��");
	dlg.m_year = date.Left(a);
	dlg.m_month = date.Mid(a+2,b-a-1);	//һ������ռ�����ַ�
	dlg.m_place1 = m_ListCtrl.GetItemText( nItem, 4);
	dlg.m_salary = m_ListCtrl.GetItemText( nItem, 5);
	UpdateData(FALSE);
	if(IDOK != dlg.DoModal())
		return;
	m_ListCtrl.SetItemText(nItem, 0,dlg.m_id);
	m_ListCtrl.SetItemText(nItem, 1,dlg.m_name);
	if (dlg.m_sex)
		m_ListCtrl.SetItemText(nItem,2,"Ů");
	else
		m_ListCtrl.SetItemText(nItem,2,"��");
	m_ListCtrl.SetItemText(nItem, 3, dlg.m_year + "��"+ dlg.m_month + "��");
	m_ListCtrl.SetItemText(nItem, 4, dlg.m_place1);
	m_ListCtrl.SetItemText(nItem, 5, dlg.m_salary);
	
}


void CKesheView::OnButtonDel() 
{
	// TODO: Add your control notification handler code here
	POSITION pos;
	pos = m_ListCtrl.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		MessageBox("�㻹û��ѡ���б��",TEXT("��ʾ"),MB_ICONWARNING);
		return;
	}
	int nItem = m_ListCtrl.GetNextSelectedItem( pos );
	if(MessageBox("ȷ��Ҫɾ������Ա��Ϣ��",TEXT("��ʾ"),MB_OKCANCEL|MB_ICONWARNING) != IDOK)
		return;
	m_ListCtrl.DeleteItem( nItem );

	
}
#include "search.h"
#include "Add.h"
#include "ID.h"
#include "NAMEID.h"
void CKesheView::OnBUTTON1Search() //����Ա��
{
	// TODO: Add your control notification handler code here
	search dll;
	dll.DoModal();
	if(!dll.m_switch)
	{
	ID dlg;
	dlg.DoModal();
	Add dl;
	int t=-1;
	int i;
	BOOL temp;
	UpdateData(TRUE);
	for(i=0;i<m_ListCtrl.GetItemCount();i++)
	{	BOOL temp=FALSE;
		if(dlg.m_id==m_ListCtrl.GetItemText(i,0))
		{
			t=i;
			dl.m_id = m_ListCtrl.GetItemText( i, 0);
        	dl.m_name = m_ListCtrl.GetItemText( i, 1);
	        if (m_ListCtrl.GetItemText( i, 2)=="Ů")
	           	dl.m_sex=TRUE;
			else
				dl.m_sex=FALSE;
			CString date = m_ListCtrl.GetItemText( i, 3);
			//��ȡ�ַ���
			int a = date.Find("��");
			int b = date.Find("��");
			dl.m_year = date.Left(a);
			dl.m_month = date.Mid(a+2,b-a-1);	//һ������ռ�����ַ�
			dl.m_place1 = m_ListCtrl.GetItemText( i, 4);
			dl.m_salary = m_ListCtrl.GetItemText( i, 5);
			UpdateData(FALSE);
			temp=TRUE;
		
            dl.DoModal();
			break;
		}
	}
		if(temp==FALSE)
		{
			MessageBox("û�д�ѧ���ļ�¼��");
	        UpdateData(FALSE);
			return;
		}

    if(t!=-1)
	{
		m_ListCtrl.SetItemText(t, 0,dl.m_id);
		m_ListCtrl.SetItemText(t, 1,dl.m_name);
		if (dl.m_sex==0)
			m_ListCtrl.SetItemText(t,2,"��");
		else if(dl.m_sex==1)
		  m_ListCtrl.SetItemText(t,2,"Ů");
		if(dl.m_year!=NULL&&dl.m_month!=NULL)
			m_ListCtrl.SetItemText(t, 3,dl. m_year + "��"+ dl.m_month + "��");
		m_ListCtrl.SetItemText(t, 4, dl.m_place1);
		m_ListCtrl.SetItemText(t, 5, dl.m_salary);
	}
	}
	else 
	{
        NAMEID dlg;
		dlg.DoModal();
		Add dl;
    	int t=-1;
		int i;
		BOOL temp;
		UpdateData(TRUE);
		for(i=0;i<m_ListCtrl.GetItemCount();i++)
		{	BOOL temp=FALSE;
			if(dlg.m_nameid==m_ListCtrl.GetItemText(i,1))
			{
				t=i;
				dl.m_id = m_ListCtrl.GetItemText( i, 0);
				dl.m_name = m_ListCtrl.GetItemText( i, 1);
				if (m_ListCtrl.GetItemText( i, 2)=="Ů")
					dl.m_sex=TRUE;
				else
					dl.m_sex=FALSE;
				CString date = m_ListCtrl.GetItemText( i, 3);
				//��ȡ�ַ���
				int a = date.Find("��");
				int b = date.Find("��");
				dl.m_year = date.Left(a);
				dl.m_month = date.Mid(a+2,b-a-1);	//һ������ռ�����ַ�
				dl.m_place1 = m_ListCtrl.GetItemText( i, 4);
				dl.m_salary = m_ListCtrl.GetItemText( i, 5);
				UpdateData(FALSE);
				temp=TRUE;
		
				dl.DoModal();
				break;
			}
		}
		if(temp==FALSE)
		{
			MessageBox("û�д�ѧ���ļ�¼��");
		    UpdateData(FALSE);
			return;
		}

	    if(t!=-1)
		{
			m_ListCtrl.SetItemText(t, 0,dl.m_id);
			m_ListCtrl.SetItemText(t, 1,dl.m_name);
			if (dl.m_sex==0)
				m_ListCtrl.SetItemText(t,2,"��");
			else if(dl.m_sex==1)
				m_ListCtrl.SetItemText(t,2,"Ů");
			if(dl.m_year!=NULL&&dl.m_month!=NULL)
				m_ListCtrl.SetItemText(t, 3,dl. m_year + "��"+ dl.m_month + "��");
			m_ListCtrl.SetItemText(t, 4, dl.m_place1);
			m_ListCtrl.SetItemText(t, 5, dl.m_salary);
		}

	}
	
}

void CKesheView::OnMyPrint() 
{
	// TODO: Add your control notification handler code here
	BOOL end=FALSE;
	char q[100];
	int row=0,column=0;
	fstream infile("d:\\person.txt",ios::in|ios::nocreate);
	if(!infile)
	{
		MessageBox("��û�б�����Ϣ��");
		return;
	}
	while(1)
	{
		m_ListCtrl.InsertItem(m_ListCtrl.GetItemCount(),NULL,NULL);
		for(column=0;column<6;column++)
		{
			if(!(infile>>q))
			{
				end=TRUE;
				break;
			}
			m_ListCtrl.SetItemText(row,column,q);
		}
		row++;
		if(TRUE==end)
			break;

	}
	infile.close();
	
}

void CKesheView::OnSave() 
{
	// TODO: Add your control notification handler code here
		CString str;
		fstream outfile("d:\\person.txt",ios::out);
		int count=m_ListCtrl.GetItemCount();
		for(int i=0;i<=count;i++)
		{
			for(int j=0;j<6;j++)
			{
				str=m_ListCtrl.GetItemText(i,j);
				str+=' ';
				outfile<<str;
			}
			outfile<<endl;
		}
		outfile.close();
		MessageBox("����ɹ���");
	
}
