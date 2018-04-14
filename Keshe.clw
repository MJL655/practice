; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Keshe.h"
LastPage=0

ClassCount=11
Class1=CKesheApp
Class2=CKesheDoc
Class3=CKesheView
Class4=CMainFrame

ResourceCount=9
Resource1=IDD_DIALOG4
Resource2=IDD_CPerson
Class5=CAboutDlg
Resource3=IDD_DIALOG3
Resource4=IDD_DIALOG2
Class6=denglu
Class7=Add
Resource5=IDD_ABOUTBOX
Class8=search
Resource6=IDR_MAINFRAME
Class9=Zhuce
Resource7=IDD_KESHE_FORM
Class10=ID
Resource8=IDD_DIALOG1
Class11=NAMEID
Resource9=IDD_DIALOG5

[CLS:CKesheApp]
Type=0
HeaderFile=Keshe.h
ImplementationFile=Keshe.cpp
Filter=N

[CLS:CKesheDoc]
Type=0
HeaderFile=KesheDoc.h
ImplementationFile=KesheDoc.cpp
Filter=N

[CLS:CKesheView]
Type=0
HeaderFile=KesheView.h
ImplementationFile=KesheView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=IDC_BUTTON_ADD


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_BUTTON_ADD
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=Keshe.cpp
ImplementationFile=Keshe.cpp
Filter=D
LastObject=CAboutDlg
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_KESHE_FORM]
Type=1
Class=CKesheView
ControlCount=9
Control1=IDC_PRINT,button,1342242816
Control2=IDC_BUTTON_ADD,button,1342177280
Control3=IDC_BUTTON_CHANGE,button,1342242816
Control4=IDC_BUTTON1_Search,button,1342242816
Control5=IDC_BUTTON_DEL,button,1342242816
Control6=IDC_SAVE,button,1342242816
Control7=IDC_BUTTON_QUIT,button,1342242816
Control8=IDC_STATIC,static,1342180110
Control9=IDC_LIST1,SysListView32,1350631425

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_BUTTON_ADD
Command17=ID_MENUITEM32775
Command18=ID_BUTTON_DEL
Command19=ID_APP_ABOUT
CommandCount=19

[DLG:IDD_CPerson]
Type=1
Class=Add
ControlCount=18
Control1=IDC_ID,edit,1350631552
Control2=IDC_Name,edit,1350631552
Control3=IDC_MALE,button,1342308361
Control4=IDC_FAMALE,button,1342177289
Control5=IDC_YEAR,edit,1350631552
Control6=IDC_MONTH,edit,1350631552
Control7=IDC_PLACE,combobox,1344340226
Control8=IDC_SALARY,edit,1350631552
Control9=IDOK,button,1342242817
Control10=IDCANCEL,button,1342242816
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352

[CLS:denglu]
Type=0
HeaderFile=denglu.h
ImplementationFile=denglu.cpp
BaseClass=CDialog
Filter=D
LastObject=denglu
VirtualFilter=dWC

[CLS:Add]
Type=0
HeaderFile=Add.h
ImplementationFile=Add.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_PLACE
VirtualFilter=dWC

[CLS:search]
Type=0
HeaderFile=search.h
ImplementationFile=search.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[CLS:Zhuce]
Type=0
HeaderFile=Zhuce.h
ImplementationFile=Zhuce.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[CLS:ID]
Type=0
HeaderFile=ID.h
ImplementationFile=ID.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=ID

[DLG:IDD_DIALOG1]
Type=1
Class=denglu
ControlCount=8
Control1=IDC_Name,edit,1350631552
Control2=IDC_Password,edit,1350631584
Control3=IDOK,button,1342242817
Control4=IDCANCLE,button,1342242816
Control5=IDC_STATIC,static,1342308865
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_NEW,button,1342242816

[DLG:IDD_DIALOG3]
Type=1
Class=Zhuce
ControlCount=8
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_EDIT2,edit,1350631584
Control3=IDC_EDIT3,edit,1350631584
Control4=IDOK,button,1342242817
Control5=IDCANCEL,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG2]
Type=1
Class=search
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_RADIO1,button,1342308361
Control5=IDC_RADIO2,button,1342177289

[DLG:IDD_DIALOG4]
Type=1
Class=ID
ControlCount=4
Control1=IDC_EDIT1,edit,1350631552
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816
Control4=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG5]
Type=1
Class=NAMEID
ControlCount=4
Control1=IDC_EDIT1,edit,1350631552
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816
Control4=IDC_STATIC,static,1342308352

[CLS:NAMEID]
Type=0
HeaderFile=NAMEID.h
ImplementationFile=NAMEID.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_APP_ABOUT
VirtualFilter=dWC

