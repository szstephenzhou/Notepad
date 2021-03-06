
// NotepadDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Notepad.h"
#include "NotepadDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNotepadDlg 对话框



CNotepadDlg::CNotepadDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNotepadDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNotepadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CNotepadDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_APP_EXIT, &CNotepadDlg::OnAppExit)
	ON_WM_DROPFILES()
END_MESSAGE_MAP()


// CNotepadDlg 消息处理程序

BOOL CNotepadDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CNotepadDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CNotepadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CNotepadDlg::OnOK()
{
	// TODO:  在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void CNotepadDlg::OnCancel()
{
	// TODO:  在此添加专用代码和/或调用基类

	//CDialogEx::OnCancel();
}


void CNotepadDlg::OnAppExit()
{
	EndDialog(IDCANCEL);
}


void CNotepadDlg::OnDropFiles(HDROP hDropInfo)//拖拽消息
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	TCHAR sFile[256];
	int DropCount = DragQueryFile(hDropInfo, -1, NULL, 0);

	//int i = 0;
	//while (i<DropCount)
	//{
	//	DragQueryFile(hDropInfo, i, sFile, _countof(sFile));
	//	++i;

	//}

	DragQueryFile(hDropInfo, 0, sFile, _countof(sFile));

	CFile file;
	if (!file.Open(sFile,CFile::modeRead))
	{
		AfxMessageBox(_T("打开失败"));
	}

	CDialogEx::OnDropFiles(hDropInfo);
}
