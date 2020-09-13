#pragma once


// LIST2 对话框

class LIST2 : public CDialogEx
{
	DECLARE_DYNAMIC(LIST2)

public:
	LIST2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~LIST2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
