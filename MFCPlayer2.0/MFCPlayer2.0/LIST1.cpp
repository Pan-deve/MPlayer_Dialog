// LIST1.cpp: 实现文件
//

#include "pch.h"
#include "MFCPlayer2.0.h"
#include "LIST1.h"
#include "afxdialogex.h"
#include"ADDpub.h"

// LIST1 对话框

IMPLEMENT_DYNAMIC(LIST1, CDialogEx)

LIST1::LIST1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

LIST1::~LIST1()
{
}

void LIST1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, one);
}


BEGIN_MESSAGE_MAP(LIST1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON11, &LIST1::OnBnClickedButton11)
END_MESSAGE_MAP()


// LIST1 消息处理程序




void LIST1::OnBnClickedButton11()
{
		ADDpub temp;
		temp.jiaone(&one);
	// TODO: 在此添加控件通知处理程序代码
}
