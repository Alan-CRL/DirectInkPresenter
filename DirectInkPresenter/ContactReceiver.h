#pragma once
#include "pch.h"
#include "Utils.h"

namespace DirectInkPresenter
{
	namespace Ink
	{
		struct ContactInfo
		{
			bool bPrimary = false;
			enum class Type
			{
				Touch,
				Mouse,
				Pen
			} cType = Type::Touch;
			LONG x = -1;
			LONG y = -1;
			DWORD cxContact = -1;
			DWORD cyContact = -1;
			DWORD dwTime = -1;
			DWORD dwContactID = -1;
		};

		struct IContactNotify
		{
			virtual void OnContactMove() {};
			virtual void OnContactDown() {};
			virtual void OnContactUp() {};
			virtual void OnContactEnter() {};
			virtual void OnContactLeave() {};
			virtual void OnContactUpdated() {};
		};

		class ContactReceiver
		{
		public:
			// 要读取触摸输入的窗口，接收触摸事件的接口
			ContactReceiver(HWND hWnd, IContactNotify* pContactNotify);
			virtual ~ContactReceiver();

			// 处理WM_TOUCH消息
			void ProcessInputEvents(UINT uMsg, WPARAM wParam, LPARAM lParam);
			// 获取上一个触摸点的信息，如果不存在则返回nullptr
			const ContactInfo* GetLastContactInfo(DWORD dwContactID = -1);
			// 获取当前触摸点信息，确保在IContactNotify中调用
			const ContactInfo* GetCurrentContactInfo();
			// 获取当前触摸点数量，确保在IContactNotify中调用
			DWORD GetCurrentContactAmount() const { return m_contactLastMap.size(); }
			// 获取当前触摸点ID
			DWORD GetCurrentContactID() const { return m_dwCurrentContactID; }
		private:
			// 判断输入的来源是否为触摸，在WM_*BUTTON*中调用
			static inline bool IsTouchEvent();
			// 关闭Windows 8以来的触摸反馈效果（水波）
			void SetContactFeedback(BOOL bDisable);
			// 更新触摸信息
			void UpdateContactInfo(TOUCHINPUT& touchInput);
			// 翻译触摸点信息
			void TranslateContactInfo(TOUCHINPUT& touchInput);
			// 更新鼠标点击信息
			void UpdateClickInfo(POINT pt);

			HWND										m_hWnd = nullptr;
			DWORD										m_dwCurrentContactID = -1;
			ContactInfo									m_currentContact = ContactInfo();
			IContactNotify*								m_contactNotify = nullptr;
			Utils::unordered_map<DWORD, ContactInfo>	m_contactLastMap = {};
		};
	}
}

