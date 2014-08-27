
// GDIPlusEffectView.cpp : CGDIPlusEffectView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "GDIPlusEffect.h"
#endif

#include "GDIPlusEffectDoc.h"
#include "GDIPlusEffectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "Resource.h"

// ��ʾ��Ч��ͷ�ļ�
#include "EffectDisplay.h"

IMPLEMENT_DYNCREATE(CGDIPlusEffectView, CView)

BEGIN_MESSAGE_MAP(CGDIPlusEffectView, CView)
END_MESSAGE_MAP()

// CGDIPlusEffectView ����/����

CGDIPlusEffectView::CGDIPlusEffectView()
{
	// TODO:  �ڴ˴���ӹ������

}

CGDIPlusEffectView::~CGDIPlusEffectView()
{
}

BOOL CGDIPlusEffectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CGDIPlusEffectView ����

void CGDIPlusEffectView::OnDraw(CDC* pDC)
{
	CGDIPlusEffectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rect;
	GetClientRect(rect);
    
	//�ڴ�CDC�ĳ�ʼ����ͼ��Ļ��ƹ���
	CDC memDC;
	CBitmap MemBitmap;

	//�豸�������ʼ��
	memDC.CreateCompatibleDC(NULL);
	//NULL ����һ���뵱ǰ��ʾ�����ݵ��ڴ��豸������

	//��������Ļ��ʾ���ݵ��ڴ���ʾ�豸 ��С���洰��
	MemBitmap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());

	//ѡȡ�հ�λͼ
	memDC.SelectObject(MemBitmap);

	//���ñ���ɫ��λͼ����ɾ��������õ��ǰ�ɫ��Ϊ����
	memDC.FillSolidRect(0, 0, rect.Width(), rect.Height(), RGB(255, 255, 255));

	Graphics graph(memDC.GetSafeHdc());
	Image image(L".\\res\\young.jpg");

	graph.DrawImage(&image, 0, 0);	//��ͼ����Ƶ��ڴ���
	
	EffectDisplay::s_nOffsetX = 0;
	EffectDisplay::s_nOffsetY = 0;
	EffectDisplay::s_nPicWidth = image.GetWidth();
	EffectDisplay::s_nPicHeight = image.GetHeight();
	EffectDisplay::s_nCDCWidth = rect.Width();
	EffectDisplay::s_nCDCHeight = rect.Height();

	//EffectDisplay::ScanDownDisplay(pDC, &memDC);	//����ɨ��

	//EffectDisplay::VSScanDisplay(pDC, &memDC);	//˫��ֱɨ��

	//EffectDisplay::MoveRightDisplay(pDC, &memDC);	//�����ƶ�

	//EffectDisplay::HSMoveDisplay(pDC, &memDC);	//ˮƽ˫���ƶ�

	//EffectDisplay::HBlindDisplay(pDC, &memDC);	//ˮƽ��Ҷ��

	//EffectDisplay::VBlindDisplay(pDC, &memDC);	//��ֱ��Ҷ��
	
	//EffectDisplay::VRasterDisplay(pDC, &memDC);	//��ֱդ��

	//EffectDisplay::HRasterDisplay(pDC, &memDC);	//ˮƽդ��

	//EffectDisplay::MosaicDisplay(pDC, &memDC);	//������

	EffectDisplay::RaindropDisplay(pDC, &memDC);	//���

	//��ͼ��ɺ������
	MemBitmap.DeleteObject();
	memDC.DeleteDC();

    //OnPaint()�л���ͼҪReleaseDC(pDC);
}


// CGDIPlusEffectView ���

#ifdef _DEBUG
void CGDIPlusEffectView::AssertValid() const
{
	CView::AssertValid();
}

void CGDIPlusEffectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGDIPlusEffectDoc* CGDIPlusEffectView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGDIPlusEffectDoc)));
	return (CGDIPlusEffectDoc*)m_pDocument;
}
#endif //_DEBUG


// CGDIPlusEffectView ��Ϣ�������

