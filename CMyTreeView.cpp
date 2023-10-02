// CMyTreeView.cpp: файл реализации
//

#include "pch.h"
#include "lab1.h"
#include "CMyTreeView.h"
#include "lab1Doc.h"
#include "lab1View.h"


// CMyTreeView

IMPLEMENT_DYNCREATE(CMyTreeView, CTreeView)

CMyTreeView::CMyTreeView()
{

}

CMyTreeView::~CMyTreeView()
{
}

BEGIN_MESSAGE_MAP(CMyTreeView, CTreeView)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// Диагностика CMyTreeView

#ifdef _DEBUG
void CMyTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// Обработчики сообщений CMyTreeView


int CMyTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{

	lpCreateStruct->style |= TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_SHOWSELALWAYS | TVS_CHECKBOXES;
	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Добавьте специализированный код создания

	return 0;
}

void CMyTreeView::FillTree()
{
	CTreeCtrl& tree = GetTreeCtrl();
	tree.DeleteAllItems();

	m_root = tree.InsertItem(L"Объекты", -1, -1, NULL, TVI_FIRST);
	m_graph = tree.InsertItem(L"График функции", -1, -1, m_root, TVI_FIRST);
	m_hatching = tree.InsertItem(L"Штриховка", -1, -1, m_root, TVI_FIRST);
	m_xAxis = tree.InsertItem(L"Ось Х", -1, -1, m_root, TVI_FIRST);

	tree.SetCheck(m_xAxis, m_pDoc->xAxis);
	tree.SetCheck(m_graph, m_pDoc->graph);
	tree.SetCheck(m_hatching, m_pDoc->hatching);

	tree.Expand(m_root, TVE_EXPAND);
}


void CMyTreeView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	CTreeView::OnLButtonDown(nFlags, point);

	CTreeCtrl& tree = GetTreeCtrl();

	CRect rc;

	tree.GetItemRect(m_root, &rc, false);
	if (rc.PtInRect(point))
		tree.SelectItem(m_root);

	tree.GetItemRect(m_graph, &rc, false);
	if (rc.PtInRect(point))
		tree.SelectItem(m_graph);

	tree.GetItemRect(m_hatching, &rc, false);
	if (rc.PtInRect(point))
		tree.SelectItem(m_hatching);

	tree.GetItemRect(m_xAxis, &rc, false);
	if (rc.PtInRect(point))
		tree.SelectItem(m_xAxis);

	if (tree.GetSelectedItem() == m_root)
	{
		bool check = tree.GetCheck(m_root);

		tree.SetCheck(m_graph, check);
		tree.SetCheck(m_hatching, check);
		tree.SetCheck(m_xAxis, check);

	}
	else
	{
		tree.SetCheck(m_root, false);
	}

	m_pDoc->graph = tree.GetCheck(m_graph);
	m_pDoc->hatching = tree.GetCheck(m_hatching);
	m_pDoc->xAxis = tree.GetCheck(m_xAxis);

	m_pDoc->pView->Invalidate();
}
