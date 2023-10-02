﻿
// lab1View.h: интерфейс класса Clab1View
//

#pragma once
#include "lab1Doc.h"
#include "CColorDlg.h"


class Clab1View : public CView
{
protected: // создать только из сериализации
	Clab1View() noexcept;
	DECLARE_DYNCREATE(Clab1View);

// Атрибуты
public:
	Clab1Doc* GetDocument() const;
	CPoint oldpoint;

	CColorDlg colorDlg;
	COLORREF m_axisColor = RGB(0, 255, 0), m_graphColor = RGB(255, 0, 0), m_hatchingColor = RGB(255, 0, 0);

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC); // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~Clab1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	void OnLButtonDown(UINT nFlags, CPoint point);
	void OnMouseMove(UINT nFlags, CPoint point);
	void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnObjectsColor();
};

#ifndef _DEBUG  // версия отладки в lab1View.cpp
inline Clab1Doc* Clab1View::GetDocument() const
   { return reinterpret_cast<Clab1Doc*>(m_pDocument); }
#endif

