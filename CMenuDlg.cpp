// CMenuDlg.cpp: файл реализации
//

#include "pch.h"
#include "lab1.h"
#include "afxdialogex.h"
#include "CMenuDlg.h"


// Диалоговое окно CMenuDlg

IMPLEMENT_DYNAMIC(CMenuDlg, CDialog)

CMenuDlg::CMenuDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
	, m_bAxisX(FALSE)
	, m_bGraph(FALSE)
	, m_bHatching(FALSE)
{

}

CMenuDlg::~CMenuDlg()
{
}

void CMenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_AXIS, m_bAxisX);
	DDX_Check(pDX, IDC_CHECK_GRAPH, m_bGraph);
	DDX_Check(pDX, IDC_CHECK_HATCHING, m_bHatching);
}


BEGIN_MESSAGE_MAP(CMenuDlg, CDialog)
END_MESSAGE_MAP()


// Обработчики сообщений CMenuDlg
