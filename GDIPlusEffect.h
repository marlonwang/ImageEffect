
// GDIPlusEffect.h : GDIPlusEffect Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CGDIPlusEffectApp:
// �йش����ʵ�֣������ GDIPlusEffect.cpp
//

class CGDIPlusEffectApp : public CWinApp
{
public:
	GdiplusStartupInput m_GdiplusStartupInput;
	ULONG_PTR m_GdiplusToken;

public:
	CGDIPlusEffectApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CGDIPlusEffectApp theApp;
