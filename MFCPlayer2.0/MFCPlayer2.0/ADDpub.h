#pragma once
#include <afxdialogex.h>
#include"DblList.h"
#include"DblNode.h"
class ADDpub :public CDialogEx
{
public:
	ADDpub() {};
	virtual ~ADDpub() {};
	void FileInit(HWND hwnd);		//打开文件初始化文件对话框
	int OpenFileDlg(void);			//打开文件对话框
    CString m_PathOfMusicDoc[MAX_PATH * 80];		//添加歌曲文件时的路径
	int numberOfFiles;				//文件的数量
	CListBox m_ListOfName;
	OPENFILENAME ofn;//打开文件对话框的文件结构

	char szOpenFileName[80 * MAX_PATH];//保存文件名

	char szFileName[80 * MAX_PATH];//保存歌曲的全路径

	char szPath[80 * MAX_PATH];//储存路径

	void jiaone(CListBox*);
	friend class LIST1;

	DblList L1;      //不同歌单上的列表

};

