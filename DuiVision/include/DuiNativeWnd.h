#ifndef __DUINATIVEWND_H__
#define __DUINATIVEWND_H__

#pragma once

#include "WndBase.h"

/////////////////////////////////////////////////////////////////////////////////////
// CDuiNativeWnd

class CDuiNativeWnd : public CControlBase
{
	DUIOBJ_DECLARE_CLASS_NAME(CDuiNativeWnd, _T("nativewnd"))

public:
    CDuiNativeWnd(HWND hWnd, CDuiObject* pDuiObject);
    virtual ~CDuiNativeWnd();

    HWND GetNativeHWnd() const;
	CWnd* GetNativeWnd() const;
	HWND GetPaintHWnd();
	CWnd* GetPaintWnd();

    bool IsDelayCreate() const;
    void SetDelayCreate(bool bDelayCreate = true);

	bool SetNativeHWnd(HWND hWnd);
	bool SetNativeWnd(CWnd* pWnd);

    bool CreateControl();

	virtual void SetControlWndVisible(BOOL bIsVisible);
	virtual void SetControlRect(CRect rc);

	HRESULT OnAttributeDelayCreate(const CString& strValue, BOOL bLoading);

    LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, bool& bHandled);

protected:
    void ReleaseControl();

	virtual void DrawControl(CDC &dc, CRect rcUpdate);

protected:
	HWND					m_hNativeWnd;	// 原生窗口句柄
	CWnd*					m_pNativeWnd;	// 原生窗口对象指针,如果设置了,会自动释放
    bool					m_bCreated;		// 是否已创建
    bool					m_bDelayCreate;	// 是否延迟创建控件

	DUI_DECLARE_ATTRIBUTES_BEGIN()
		DUI_CUSTOM_ATTRIBUTE(_T("delaycreate"), OnAttributeDelayCreate)
	DUI_DECLARE_ATTRIBUTES_END()
};

#endif // __DUINATIVEWND_H__
