
// lab1Doc.cpp: реализация класса Clab1Doc 
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

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "CMyTreeView.h"
#include "CMenuDlg.h"

// Clab1Doc

IMPLEMENT_DYNCREATE(Clab1Doc, CDocument)

BEGIN_MESSAGE_MAP(Clab1Doc, CDocument)
	ON_COMMAND(ID_OBJECTS_AXISX, &Clab1Doc::OnObjectsAxisX)
	ON_COMMAND(ID_OBJECTS_GRAPH, &Clab1Doc::OnObjectsGraph)
	ON_COMMAND(ID_OBJECTS_HATCHING, &Clab1Doc::OnObjectsHatching)
	ON_UPDATE_COMMAND_UI(ID_OBJECTS_AXISX, &Clab1Doc::OnUpdateObjectsAxisX)
	ON_UPDATE_COMMAND_UI(ID_OBJECTS_GRAPH, &Clab1Doc::OnUpdateObjectsGraph)
	ON_UPDATE_COMMAND_UI(ID_OBJECTS_HATCHING, &Clab1Doc::OnUpdateObjectsHatching)
	ON_COMMAND(ID_OBJECTS_MENU, &Clab1Doc::OnObjectsMenu)
END_MESSAGE_MAP()


// Создание или уничтожение Clab1Doc

Clab1Doc::Clab1Doc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора

}

Clab1Doc::~Clab1Doc()
{
}

BOOL Clab1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	graph = hatching = xAxis = false;

	pTree->FillTree();

	return TRUE;
}




// Сериализация Clab1Doc

void Clab1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void Clab1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void Clab1Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void Clab1Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика Clab1Doc

#ifdef _DEBUG
void Clab1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Clab1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды Clab1Doc


void Clab1Doc::OnObjectsAxisX()
{
	// TODO: добавьте свой код обработчика команд
	xAxis = !xAxis;
	pView->Invalidate();

	pTree->FillTree();
}


void Clab1Doc::OnObjectsGraph()
{
	// TODO: добавьте свой код обработчика команд
	graph = !graph;
	pView->Invalidate();

	pTree->FillTree();
}


void Clab1Doc::OnObjectsHatching()
{
	// TODO: добавьте свой код обработчика команд
	hatching = !hatching;
	pView->Invalidate();

	pTree->FillTree();
}


void Clab1Doc::OnUpdateObjectsAxisX(CCmdUI* pCmdUI)
{
	// TODO: добавьте свой код обработчика ИП обновления команд
	pCmdUI->SetCheck(xAxis);
}


void Clab1Doc::OnUpdateObjectsGraph(CCmdUI* pCmdUI)
{
	// TODO: добавьте свой код обработчика ИП обновления команд
	pCmdUI->SetCheck(graph);
}


void Clab1Doc::OnUpdateObjectsHatching(CCmdUI* pCmdUI)
{
	// TODO: добавьте свой код обработчика ИП обновления команд
	pCmdUI->SetCheck(hatching);
}


void Clab1Doc::OnObjectsMenu()
{
	// TODO: добавьте свой код обработчика команд
	CMenuDlg dlg;

	dlg.m_bAxisX = xAxis;
	dlg.m_bGraph = graph;
	dlg.m_bHatching = hatching;

	if (dlg.DoModal() == IDOK) {
		xAxis = dlg.m_bAxisX;
		graph = dlg.m_bGraph;
		hatching = dlg.m_bHatching;

		pView->Invalidate();
		pTree->FillTree();
	}

}
