
// GDIPlusEffectView.h : CGDIPlusEffectView ��Ľӿ�
//

#pragma once


class CGDIPlusEffectView : public CView
{
protected: // �������л�����
	CGDIPlusEffectView();
	DECLARE_DYNCREATE(CGDIPlusEffectView)

// ����
public:
	CGDIPlusEffectDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CGDIPlusEffectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // GDIPlusEffectView.cpp �еĵ��԰汾
inline CGDIPlusEffectDoc* CGDIPlusEffectView::GetDocument() const
   { return reinterpret_cast<CGDIPlusEffectDoc*>(m_pDocument); }
#endif

