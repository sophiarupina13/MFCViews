// lab1View.cpp: реализация класса Clab1View
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "lab1.h"
#endif

#include "lab1Doc.h"
#include "lab1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clab1View

IMPLEMENT_DYNCREATE(Clab1View, CView)

BEGIN_MESSAGE_MAP(Clab1View, CView)
    // Стандартные команды печати
    ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
    ON_WM_MOUSEWHEEL()
    ON_WM_LBUTTONDOWN()
    ON_WM_MOUSEMOVE()
    ON_WM_LBUTTONUP()
    ON_WM_RBUTTONDOWN()
    ON_COMMAND(ID_OBJECTS_COLOR, &Clab1View::OnObjectsColor)
END_MESSAGE_MAP()

// Создание или уничтожение Clab1View

Clab1View::Clab1View() noexcept
{
    // TODO: добавьте код создания

}

Clab1View::~Clab1View()
{
}

BOOL Clab1View::PreCreateWindow(CREATESTRUCT& cs)
{
    // TODO: изменить класс Window или стили посредством изменения
    //  CREATESTRUCT cs

    return CView::PreCreateWindow(cs);
}


// Рисование Clab1View

void Clab1View::OnDraw(CDC* pDC/*, int opt*/)
{
    Clab1Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    if (!pDoc)
        return;


    CRect rc;
    GetClientRect(&rc);

    int width = rc.right;
    int height = rc.bottom;

    CPen pen, pen1;
    pen.CreatePen(PS_DASH, 1, m_axisColor);
    pen1.CreatePen(PS_SOLID, 2, m_graphColor);
    CPen* oldPen = pDC->SelectObject(&pen);
    CPen* oldPen1 = pDC->SelectObject(&pen1);


    CBrush brush(HS_BDIAGONAL, m_hatchingColor);
    CBrush* oldBrush = pDC->SelectObject(&brush);
    CPoint* points = new CPoint[width + 3];

    pDC->MoveTo(0, height / 2);
    points[0].x = 0; points[0].y = height / 2;

    double mX = pDoc->onMsMvX;
    double mY = pDoc->onMsMvY;
    int theEnd = 1;

    pDC->MoveTo(0, height / 2);

    if (pDoc->graph) {

        for (int i = 1; i < width; i++) {

            double X = -pDoc->pxMoveX * 0.009 + i / mX - 0.07 * mX; // строим график
            double Y = sin(X) * mY;
            double dist = height / 2 - Y;
            pDC->SelectObject(&pen1);
            pDC->LineTo(i, dist);
            points[i].x = i; points[i].y = dist;
            theEnd++;

        }
    }
    points[theEnd].x = width; points[theEnd].y = height / 2;
    points[theEnd + 1].x = 0; points[theEnd + 1].y = height / 2;
    CRgn rg;
    if (pDoc->hatching) {

        rg.CreatePolygonRgn(points, width + 3, ALTERNATE); // красим кистью
        pDC->FillRgn(&rg, &brush);
        pDC->SelectObject(oldBrush);
    }

    pDC->MoveTo(0, height / 2);
    pDC->SelectObject(&pen);

    if (pDoc->xAxis)
        pDC->LineTo(width, height / 2);
    delete[] points;
}




// Печать Clab1View

BOOL Clab1View::OnPreparePrinting(CPrintInfo* pInfo)
{
    // подготовка по умолчанию
    return DoPreparePrinting(pInfo);
}

void Clab1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
    // TODO: добавьте дополнительную инициализацию перед печатью
}

void Clab1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
    // TODO: добавьте очистку после печати
}


// Диагностика Clab1View

#ifdef _DEBUG
void Clab1View::AssertValid() const
{
    CView::AssertValid();
}

void Clab1View::Dump(CDumpContext& dc) const
{
    CView::Dump(dc);
}

Clab1Doc* Clab1View::GetDocument() const // встроена неотлаженная версия
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clab1Doc)));
    return (Clab1Doc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений Clab1View


BOOL Clab1View::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
    //TODO: добавьте свой код обработчика сообщений или вызов стандартного

    Clab1Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    if (nFlags & MK_CONTROL)
    {
        if (zDelta > 0) // изменяем масштаб по y
            pDoc->onMsMvY += 10;
        else
            pDoc->onMsMvY += -10;
    }
    else
    {
        if (zDelta > 0) // изменяем масштаб по y
            pDoc->onMsMvX += 3;
        else
            pDoc->onMsMvX += -3;
    }

    Invalidate();

    return CView::OnMouseWheel(nFlags, zDelta, pt);
}


void Clab1View::OnLButtonDown(UINT nFlags, CPoint point)
{
    Clab1Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    CView::OnLButtonDown(nFlags, point);
}

void Clab1View::OnMouseMove(UINT nFlags, CPoint point)
{
    Clab1Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    if (GetKeyState(VK_LBUTTON) < 0) {

        pDoc->pxMoveX += (point.x - oldpoint.x);
        Invalidate();
    }
    oldpoint = point;

    CView::OnMouseMove(nFlags, point);
}


void Clab1View::OnLButtonUp(UINT nFlags, CPoint point)
{
    Clab1Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    CView::OnLButtonUp(nFlags, point);
}


void Clab1View::OnRButtonDown(UINT nFlags, CPoint point)
{
    // TODO: добавьте свой код обработчика сообщений или вызов стандартного

    ClientToScreen(&point);

    CCmdUI state;

    CMenu* pMenu = AfxGetMainWnd()->GetMenu()->GetSubMenu(3);

    state.m_pMenu = pMenu; 
    state.m_nIndexMax = pMenu->GetMenuItemCount();

    for (UINT i = 0; i < state.m_nIndexMax; i++) {

        state.m_nIndex = i;
        state.m_nID = pMenu->GetMenuItemID(i);
        state.DoUpdate(this, FALSE);

    }

    pMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);

    CView::OnRButtonDown(nFlags, point);
}


void Clab1View::OnObjectsColor()
{
    // TODO: добавьте свой код обработчика команд
    
    if (!colorDlg)
        colorDlg.Create(IDD_COLOR, this);

    colorDlg.xAxisColorCtrl.SetColor(RGB(0,255,0));
    colorDlg.graphColorCtrl.SetColor(RGB(255, 0, 0));
    colorDlg.hatchingColorCtrl.SetColor(RGB(255, 0, 0));

    colorDlg.pView = this;

    colorDlg.ShowWindow(SW_SHOW);

}
