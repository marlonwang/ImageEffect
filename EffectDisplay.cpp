#pragma once

/*******************************************************
#define SAFE_DELETE(p) do{delete p; p=NULL;}while(false)
********************************************************/


#include "stdafx.h"
#include "EffectDisplay.h"

/***********************************************
* ����EffectDisplay.h �������� static ����
************************************************/

int EffectDisplay::s_nOffsetX;
int EffectDisplay::s_nOffsetY;
int EffectDisplay::s_nPicWidth;
int EffectDisplay::s_nPicHeight;
int EffectDisplay::s_nCDCWidth;
int EffectDisplay::s_nCDCHeight;


/***********************************************
*	���ã���ʱ����
*	������
*		dwMilliseconds ��ʱʱ�䣬��λ����
*	�޷���ֵ
************************************************/
void EffectDisplay::DelayTime(DWORD dwMilliseconds)
{
	LARGE_INTEGER litmp;
	LONGLONG lTimeBegin;
	LONGLONG lTimeEnd;
	double dMinus;
	double dFreq;
	double dTim;
	QueryPerformanceFrequency(&litmp);	//��û����ڲ���ʱ����ʱ��Ƶ��
	dFreq = (double)litmp.QuadPart;		//��ü�������ʱ��Ƶ��
	QueryPerformanceCounter(&litmp);
	lTimeBegin = litmp.QuadPart;		//���ʱ����ʼֵ 
	do
	{
		QueryPerformanceCounter(&litmp);
		lTimeEnd = litmp.QuadPart;		//�����ֵֹ
		dMinus = (double)(lTimeEnd - lTimeBegin);
		dTim = dMinus / dFreq;			//��ö�Ӧ��ʱ��ֵ ��λ��
	} while (dTim < dwMilliseconds*0.001);
}

/******************************************************
*	���ã�����ɨ����Ч
*******************************************************/
void EffectDisplay::ScanDownDisplay(CDC* pDC, CDC* pMemDC)
{
	//ɨ��߶�
	int nHeight = min(s_nPicHeight, s_nCDCHeight);

	//ɨ����
	int nWidth = min(s_nPicWidth, s_nCDCWidth);

	for (int i = 0; i < nHeight; i += 1)
	{
		pDC->BitBlt(s_nOffsetX, i + s_nOffsetY, nWidth, 1,
			pMemDC, s_nOffsetX, i + s_nOffsetY, SRCCOPY);
		DelayTime(1);
	}
}

/***************************************************
*	���ã���ֱ˫��ɨ����Ч
****************************************************/
void EffectDisplay::VSScanDisplay(CDC* pDC, CDC* pMemDC)
{
	//ɨ��߶�
	int nHeight = min(s_nPicHeight, s_nCDCHeight);
	//ɨ����
	int nWidth = min(s_nPicWidth, s_nCDCWidth);

	for (int i = 0; i <= nHeight / 2; i += 1)
	{
		//���沿��
		pDC->BitBlt(s_nOffsetX, i + s_nOffsetY, nWidth, 1,
			pMemDC, s_nOffsetX, i + s_nOffsetY, SRCCOPY);
		//���沿��
		pDC->BitBlt(s_nOffsetX, nHeight - i - 1 + s_nOffsetY, nWidth, 1,
			pMemDC, s_nOffsetX, nHeight - i - 1 + s_nOffsetY, SRCCOPY);
		DelayTime(2);
	}
}

/**********************************************************
*	���ã������ƶ���Ч
***********************************************************/
void EffectDisplay::MoveRightDisplay(CDC* pDC, CDC* pMemDC)
{
	//ɨ��߶�
	int nHeight = min(s_nPicHeight, s_nCDCHeight);

	for (int i = 0; i <= s_nCDCWidth - s_nOffsetX; i += 2)
	{
		pDC->BitBlt(0, s_nOffsetY, i, nHeight, pMemDC,
			s_nCDCWidth - s_nOffsetX - i, s_nOffsetY, SRCCOPY);
		DelayTime(1);
	}
	//����ͼ��λ��
	pDC->BitBlt(0, s_nOffsetY, s_nCDCWidth - s_nOffsetX, nHeight,
		pMemDC, 0, s_nOffsetY, SRCCOPY);
}

/*************************************************************
*	���ã�ˮƽ˫���ƶ���Ч
**************************************************************/
void EffectDisplay::HSMoveDisplay(CDC* pDC, CDC* pMemDC)
{
	//ɨ��߶�
	int nHeight = min(s_nPicHeight, s_nCDCHeight);
	//ɨ����
	int nWidth = min(s_nPicWidth, s_nCDCWidth);

	for (int i = 0; i < s_nCDCWidth / 2; i += 2)
	{
		//���沿��
		pDC->BitBlt(0, s_nOffsetY, i, nHeight, pMemDC,
			nWidth / 2 - i + s_nOffsetX, s_nOffsetY, SRCCOPY);
		//���沿��
		pDC->BitBlt(s_nCDCWidth - i, s_nOffsetY, i, nHeight, pMemDC,
			nWidth / 2 + s_nOffsetX, s_nOffsetY, SRCCOPY);
		DelayTime(1);
	}
	//����ͼ��λ��
	pDC->BitBlt(0, s_nOffsetY, s_nCDCWidth - s_nOffsetX, nHeight,
		pMemDC, 0, s_nOffsetY, SRCCOPY);
}

/***********************************************************
*	���ã���ֱ��Ҷ��
************************************************************/
void EffectDisplay::VBlindDisplay(CDC* pDC, CDC* pMemDC)
{
	//ɨ��߶�
	int nHeight = min(s_nPicHeight, s_nCDCHeight);
	//ɨ����
	int nWidth = min(s_nPicWidth, s_nCDCWidth);

	//��Ҷ�����
	int nScanLine = 8;
	for (int i = 0; i < nScanLine; i++)
	{
		for (int j = 0; j < nWidth; j += nScanLine)
		{
			pDC->BitBlt(j + i + s_nOffsetX, s_nOffsetY, 1, nHeight,
				pMemDC, j + i + s_nOffsetX, s_nOffsetY, SRCCOPY);
		}
		DelayTime(50);
	}
}

/***************************************************
*	���ã�ˮƽ��Ҷ����Ч
****************************************************/
void EffectDisplay::HBlindDisplay(CDC* pDC, CDC* pMemDC)
{
	//ɨ��߶�
	int nHeight = min(s_nPicHeight, s_nCDCHeight);
	//ɨ����
	int nWidth = min(s_nPicWidth, s_nCDCWidth);

	//��Ҷ�����
	int nScanLine = 8;
	for (int i = 0; i < nScanLine; i += 1)
	{
		for (int j = 0; j < nHeight; j += nScanLine)
		{
			pDC->BitBlt(s_nOffsetX, j + i + s_nOffsetY, nWidth, 1,
				pMemDC, s_nOffsetX, j + i + s_nOffsetY, SRCCOPY);
		}
		DelayTime(50);
	}
}

/**********************************************************
*	���ã���ֱդ����Ч
***********************************************************/
void EffectDisplay::VRasterDisplay(CDC* pDC, CDC* pMemDC)
{
	//ɨ��߶�
	int nHeight = min(s_nPicHeight, s_nCDCHeight);
	//ɨ����
	int nWidth = min(s_nPicWidth, s_nCDCWidth);

	//դ�����
	int nScanLine = 16;

	for (int i = 0; i <= nHeight + s_nOffsetY; i++)
	{
		for (int j = 0; j <= nWidth; j += 2 * nScanLine)
		{
			pDC->BitBlt(j + s_nOffsetX, 0, nScanLine, i, pMemDC,
				j + s_nOffsetX, nHeight + s_nOffsetY - i, SRCCOPY);

			int k = j + nScanLine;

			pDC->BitBlt(k + s_nOffsetX, nHeight + s_nOffsetY - i, nScanLine,
				i + s_nOffsetY, pMemDC, k + s_nOffsetX, 0, SRCCOPY);
		}
		DelayTime(1);
	}
}

/********************************************************
*	ˮƽդ����Ч
*********************************************************/
void EffectDisplay::HRasterDisplay(CDC* pDC, CDC* pMemDC)
{
	//ɨ��߶�
	int nHeight = min(s_nPicHeight, s_nCDCHeight);
	//ɨ����
	int nWidth = min(s_nPicWidth, s_nCDCWidth);

	int nScanLine = 16;

	for (int i = 0; i <= nWidth + s_nOffsetX; i++)
	{
		for (int j = 0; j <= nHeight; j += 2 * nScanLine)
		{
			pDC->BitBlt(0, j + s_nOffsetY, i, nScanLine, pMemDC,
				nWidth + s_nOffsetX - i, j + s_nOffsetY, SRCCOPY);

			int k = j + nScanLine;

			pDC->BitBlt(nWidth + s_nOffsetX - i, k + s_nOffsetY,
				i + s_nOffsetX, nScanLine, pMemDC, 0,
				k + s_nOffsetY, SRCCOPY);
		}
		DelayTime(1);
	}
}

/***********************************************************
*	���ã���������Ч
************************************************************/
void EffectDisplay::MosaicDisplay(CDC* pDC, CDC* pMemDC)
{
    #define SAFE_DELETE(p) { if(p) { delete (p); (p)=NULL; } }

	int nTileSize = 24;	//������С�����С
	int nRw = 0;
	int nRh = 0;

	if (s_nPicWidth % nTileSize != 0)
		nRw = 1;
	if (s_nPicHeight % nTileSize != 0)
		nRh = 1;

	//����С����ĸ���
	int nTileCount = (s_nPicWidth / nTileSize + nRw)*
		(s_nPicHeight / nTileSize + nRh);

	CPtrArray points;	//��������С�������������
	long lx = 0;
	long ly = 0;

	for (int k = 0; k < nTileCount; k++)
	{
		CPoint* point = new CPoint;
		point->x = lx;
		point->y = ly;
		lx = lx + nTileSize;
		if (lx >= s_nPicWidth)
		{
			lx = 0;
			ly = ly + nTileSize;
		}
		points.Add(point);
	}

	//����ͼ���Сȷ��ʱ����
	int nDelayTime = 2;
	if (s_nPicHeight * s_nPicWidth > 600 * 500)
		nDelayTime = 1;

	LARGE_INTEGER seed;
	QueryPerformanceFrequency(&seed);
	QueryPerformanceCounter(&seed);

	//��ʼ��һ����΢��Ϊ��λ��ʱ������
	srand((int)seed.QuadPart);

	for (int i = nTileCount - 1; i >= 0; i--)
	{
		int n = rand() % (i + 1);
		CPoint* point = (CPoint*)points[n];

		lx = point->x;
		ly = point->y;

		pDC->BitBlt(lx + s_nOffsetX, ly + s_nOffsetY, nTileSize, nTileSize,
			pMemDC, lx + s_nOffsetX, ly + s_nOffsetY, SRCCOPY);

		SAFE_DELETE(point);
		points.RemoveAt(n);

		DelayTime(nDelayTime);
	}
}

/****************************************************
*	����:�����Ч
*****************************************************/
void EffectDisplay::RaindropDisplay(CDC* pDC, CDC* pMemDC)
{
	//ɨ��߶�
	int nHeight = min(s_nPicHeight, s_nCDCHeight);
	//ɨ����
	int nWidth = min(s_nPicWidth, s_nCDCWidth);

	for (int i = 0; i <= nHeight + s_nOffsetY; i++)
	{
		for (int j = 0; j <= nHeight + s_nOffsetY - i; j++)
		{
			pDC->BitBlt(s_nOffsetX, j, nWidth, 1, pMemDC, s_nOffsetX,
				nHeight + s_nOffsetY - i, SRCCOPY);
		}
		DelayTime(1);
	}
}