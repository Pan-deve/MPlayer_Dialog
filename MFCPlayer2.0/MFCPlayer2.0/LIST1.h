#pragma once


// LIST1 对话框

class LIST1 : public CDialogEx
{
	DECLARE_DYNAMIC(LIST1)

public:
	LIST1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~LIST1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox one;
	afx_msg void OnBnClickedButton11();
};
