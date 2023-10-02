// CColorDlg.cpp: файл реализации
//

#include "pch.h"
#include "lab1.h"
#include "afxdialogex.h"
#include "CColorDlg.h"
#include "lab1View.h"


// Диалоговое окно CColorDlg

IMPLEMENT_DYNAMIC(CColorDlg, CDialog)

CColorDlg::CColorDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_COLOR, pParent)
{

}

CColorDlg::~CColorDlg()
{
}

void CColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, xAxisColorCtrl);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON3, graphColorCtrl);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON2, hatchingColorCtrl);
}


BEGIN_MESSAGE_MAP(CColorDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CColorDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Обработчики сообщений CColorDlg


void CColorDlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
	pView->m_axisColor = xAxisColorCtrl.GetColor();
	pView->m_graphColor = graphColorCtrl.GetColor();
	pView->m_hatchingColor = hatchingColorCtrl.GetColor();

	pView->Invalidate();
}
