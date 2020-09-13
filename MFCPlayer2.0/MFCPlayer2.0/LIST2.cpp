// LIST2.cpp: 实现文件
//

#include "pch.h"
#include "MFCPlayer2.0.h"
#include "LIST2.h"
#include "afxdialogex.h"


// LIST2 对话框

IMPLEMENT_DYNAMIC(LIST2, CDialogEx)

LIST2::LIST2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

LIST2::~LIST2()
{
}

void LIST2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LIST2, CDialogEx)
END_MESSAGE_MAP()


// LIST2 消息处理程序
