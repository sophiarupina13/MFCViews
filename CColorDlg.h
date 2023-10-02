#pragma once
#include "afxdialogex.h"

class Clab1View;
// Диалоговое окно CColorDlg

class CColorDlg : public CDialog
{
	DECLARE_DYNAMIC(CColorDlg)

public:
	CColorDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CColorDlg();

	Clab1View* pView;

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COLOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CMFCColorButton xAxisColorCtrl;
	CMFCColorButton graphColorCtrl;
	CMFCColorButton hatchingColorCtrl;
};
