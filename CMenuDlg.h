#pragma once
#include "afxdialogex.h"


// Диалоговое окно CMenuDlg

class CMenuDlg : public CDialog
{
	DECLARE_DYNAMIC(CMenuDlg)

public:
	CMenuDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CMenuDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MENU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_bAxisX;
	BOOL m_bGraph;
	BOOL m_bHatching;
};
