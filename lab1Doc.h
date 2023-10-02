
// lab1Doc.h: интерфейс класса Clab1Doc 
//


#pragma once
#include "CMyTreeView.h"
class СMyTreeView;
class Clab1View;

class Clab1Doc : public CDocument
{
protected: // создать только из сериализации
	Clab1Doc() noexcept;
	DECLARE_DYNCREATE(Clab1Doc)

// Атрибуты
public:
	double onMsMvX = 100.0, onMsMvY = 100.0;
	double pxMoveX = 0.0;
	bool graph, hatching, xAxis;

	Clab1View* pView;
	CMyTreeView* pTree;

// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~Clab1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	//afx_msg void On32771();
private:
	CString m_text;

public:
	afx_msg void OnObjectsAxisX();
	afx_msg void OnObjectsGraph();
	afx_msg void OnObjectsHatching();
	afx_msg void OnUpdateObjectsAxisX(CCmdUI* pCmdUI);
	afx_msg void OnUpdateObjectsGraph(CCmdUI* pCmdUI);
	afx_msg void OnUpdateObjectsHatching(CCmdUI* pCmdUI);
	afx_msg void OnObjectsMenu();
};
