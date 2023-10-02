
// lab1.h: основной файл заголовка для приложения lab1
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// Clab1App:
// Сведения о реализации этого класса: lab1.cpp
//

class Clab1App : public CWinApp
{
public:
	Clab1App() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Clab1App theApp;
