//特效显示类 保存显示特效需要的参数信息

#pragma once
#ifndef _EFFECT_DISPALY_H_
#define _EFFECT_DISPALY_H_


class EffectDisplay
{
public:
	static int s_nOffsetX;	//图像在内存CDC中的X偏移量
	static int s_nOffsetY;	//图像在内存CDC中的Y偏移量
	static int s_nPicWidth;	//图像的宽度
	static int s_nPicHeight;//图像的高度
	static int s_nCDCWidth;	//内存CDC的宽度
	static int s_nCDCHeight;//内存CDC的高度

public:
	static void DelayTime(DWORD dwMilliseconds);	//延时函数
	static void ScanDownDisplay(CDC* pDC, CDC* pMemDC);	//向下扫描
	static void VSScanDisplay(CDC* pDC, CDC* pMemDC);	//垂直双重扫描
	static void MoveRightDisplay(CDC* pDC, CDC* pMemDC);	//向右移动
	static void HSMoveDisplay(CDC* pDC, CDC* pMemDC);	//水平双重移动
	static void VBlindDisplay(CDC* pDC, CDC* pMemDC);	//垂直百叶窗
	static void HBlindDisplay(CDC* pDC, CDC* pMemDC);	//水平百叶窗
	static void VRasterDisplay(CDC* pDC, CDC* pMemDC);	//垂直栅条
	static void HRasterDisplay(CDC* pDC, CDC* pMemDC);	//水平栅条
	static void MosaicDisplay(CDC* pDC, CDC* pMemDC);	//马赛克
	static void RaindropDisplay(CDC* pDC, CDC* pMemDC);	//雨滴
};


#endif // !_EFFECT_DISPALY_H_




