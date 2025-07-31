#pragma once
#include "pch.h"
#include "Utils.h"

namespace DirectInkPresenter
{
	namespace UI
	{
		namespace Graphics
		{
			using namespace D2D1;
			// ��ȡ���ڵ�ǰDPI����
			FLOAT GetDpiScailingForHwnd(HWND hWnd);
			// ��ȡ���ڵ�ǰDPI
			void GetDpiForHwnd(HWND hWnd, float& fDpiX, float& fDpiY);
			// ��ʹ�����豸�޹ص�����(DIP)��ʾ�ĳ���ת��Ϊʹ���������ر�ʾ�ĳ��ȡ�
			LONG ConvertDipsToPixels(float dips, float dpi = -1.f);
			// ��ʹ���������ر�ʾ�ĳ���ת��Ϊʹ�����豸�޹ص�����(DIP)��ʾ�ĳ��ȡ�
			float ConvertPixelsToDips(UINT pixels, float dpi = -1.f);
			// ���õ�ǰ�����ĵ�DPI
			void SetContextDpi(float dpi);
			void SetContextDpi(HWND hWnd);

			void CreateTargetForHwnd(HWND hWnd, ID2D1HwndRenderTarget** d2dHwndRenderTarget);
			void Initialize();

			inline ID2D1Factory* GetD2DFactory();
			inline IDWriteFactory* GetDwriteFactory();
			inline IWICImagingFactory* GetWicFactory();
		};
	}
}