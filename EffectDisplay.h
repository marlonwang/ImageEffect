//��Ч��ʾ�� ������ʾ��Ч��Ҫ�Ĳ�����Ϣ

#pragma once
#ifndef _EFFECT_DISPALY_H_
#define _EFFECT_DISPALY_H_


class EffectDisplay
{
public:
	static int s_nOffsetX;	//ͼ�����ڴ�CDC�е�Xƫ����
	static int s_nOffsetY;	//ͼ�����ڴ�CDC�е�Yƫ����
	static int s_nPicWidth;	//ͼ��Ŀ��
	static int s_nPicHeight;//ͼ��ĸ߶�
	static int s_nCDCWidth;	//�ڴ�CDC�Ŀ��
	static int s_nCDCHeight;//�ڴ�CDC�ĸ߶�

public:
	static void DelayTime(DWORD dwMilliseconds);	//��ʱ����
	static void ScanDownDisplay(CDC* pDC, CDC* pMemDC);	//����ɨ��
	static void VSScanDisplay(CDC* pDC, CDC* pMemDC);	//��ֱ˫��ɨ��
	static void MoveRightDisplay(CDC* pDC, CDC* pMemDC);	//�����ƶ�
	static void HSMoveDisplay(CDC* pDC, CDC* pMemDC);	//ˮƽ˫���ƶ�
	static void VBlindDisplay(CDC* pDC, CDC* pMemDC);	//��ֱ��Ҷ��
	static void HBlindDisplay(CDC* pDC, CDC* pMemDC);	//ˮƽ��Ҷ��
	static void VRasterDisplay(CDC* pDC, CDC* pMemDC);	//��ֱդ��
	static void HRasterDisplay(CDC* pDC, CDC* pMemDC);	//ˮƽդ��
	static void MosaicDisplay(CDC* pDC, CDC* pMemDC);	//������
	static void RaindropDisplay(CDC* pDC, CDC* pMemDC);	//���
};


#endif // !_EFFECT_DISPALY_H_




