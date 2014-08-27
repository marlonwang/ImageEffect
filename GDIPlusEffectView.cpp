
// GDIPlusEffectView.cpp : CGDIPlusEffectView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "GDIPlusEffect.h"
#endif

#include "GDIPlusEffectDoc.h"
#include "GDIPlusEffectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "Resource.h"

// 显示特效的头文件
#include "EffectDisplay.h"

IMPLEMENT_DYNCREATE(CGDIPlusEffectView, CView)

BEGIN_MESSAGE_MAP(CGDIPlusEffectView, CView)
END_MESSAGE_MAP()

// CGDIPlusEffectView 构造/析构

CGDIPlusEffectView::CGDIPlusEffectView()
{
	// TODO:  在此处添加构造代码

}

CGDIPlusEffectView::~CGDIPlusEffectView()
{
}

BOOL CGDIPlusEffectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CGDIPlusEffectView 绘制

void CGDIPlusEffectView::OnDraw(CDC* pDC)
{
	CGDIPlusEffectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rect;
	GetClientRect(rect);
    
	//内存CDC的初始化与图像的绘制工作
	CDC memDC;
	CBitmap MemBitmap;

	//设备描述表初始化
	memDC.CreateCompatibleDC(NULL);
	//NULL 创建一个与当前显示器兼容的内存设备描述表

	//建立与屏幕显示兼容的内存显示设备 大小跟随窗口
	MemBitmap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());

	//选取空白位图
	memDC.SelectObject(MemBitmap);

	//先用背景色将位图清除干净，这里用的是白色作为背景
	memDC.FillSolidRect(0, 0, rect.Width(), rect.Height(), RGB(255, 255, 255));

	Graphics graph(memDC.GetSafeHdc());
	Image image(L".\\res\\young.jpg");

	graph.DrawImage(&image, 0, 0);	//将图像绘制到内存中
	
	EffectDisplay::s_nOffsetX = 0;
	EffectDisplay::s_nOffsetY = 0;
	EffectDisplay::s_nPicWidth = image.GetWidth();
	EffectDisplay::s_nPicHeight = image.GetHeight();
	EffectDisplay::s_nCDCWidth = rect.Width();
	EffectDisplay::s_nCDCHeight = rect.Height();

	//EffectDisplay::ScanDownDisplay(pDC, &memDC);	//向下扫描

	//EffectDisplay::VSScanDisplay(pDC, &memDC);	//双向垂直扫描

	//EffectDisplay::MoveRightDisplay(pDC, &memDC);	//向右移动

	//EffectDisplay::HSMoveDisplay(pDC, &memDC);	//水平双重移动

	//EffectDisplay::HBlindDisplay(pDC, &memDC);	//水平百叶窗

	//EffectDisplay::VBlindDisplay(pDC, &memDC);	//垂直百叶窗
	
	//EffectDisplay::VRasterDisplay(pDC, &memDC);	//垂直栅条

	//EffectDisplay::HRasterDisplay(pDC, &memDC);	//水平栅条

	//EffectDisplay::MosaicDisplay(pDC, &memDC);	//马赛克

	EffectDisplay::RaindropDisplay(pDC, &memDC);	//雨滴

	//绘图完成后的清理
	MemBitmap.DeleteObject();
	memDC.DeleteDC();

    //OnPaint()中绘完图要ReleaseDC(pDC);
}


// CGDIPlusEffectView 诊断

#ifdef _DEBUG
void CGDIPlusEffectView::AssertValid() const
{
	CView::AssertValid();
}

void CGDIPlusEffectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGDIPlusEffectDoc* CGDIPlusEffectView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGDIPlusEffectDoc)));
	return (CGDIPlusEffectDoc*)m_pDocument;
}
#endif //_DEBUG


// CGDIPlusEffectView 消息处理程序

