
// MFCPlayer2.0Dlg.h: 头文件
//

#pragma once
#include <MMSystem.h>
#include <Digitalv.h>

#pragma comment(lib, "Winmm.lib")
/************************************************************************
		  处理音乐文件时所需的全局变量
*************************************************************************
static OPENFILENAME ofn;//打开文件对话框的文件结构

static char szOpenFileName[80 * MAX_PATH];//保存文件名

static char szFileName[80 * MAX_PATH];//保存歌曲的全路径

static char szPath[80 * MAX_PATH];//储存路径

static char OpenMusicFile[MAX_PATH];//保存路径(用于操作音乐)*/
// CMFCPlayer20Dlg 对话框
class CMFCPlayer20Dlg : public CDialogEx
{
// 构造
public:
	CMFCPlayer20Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPLAYER20_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAddmusic();
	void FileInit(HWND hwnd);		//打开文件初始化文件对话框
	int OpenFileDlg(void);			//打开文件对话框
	void Load(HWND hWnd, CString strFilepath);//加载路径函数
	void play();//播放函数
private:
	//新增成员变量
	CString m_PathOfMusicDoc[MAX_PATH * 80];		//添加歌曲文件时的路径
	CString m_NameOfMusicDoc;		//歌曲文件名
	int numberOfFiles;				//文件的数量
	
	CString edit_Playroom;
	CListBox m_ListOfName;

	OPENFILENAME ofn;//打开文件对话框的文件结构

	char szOpenFileName[80 * MAX_PATH];//保存文件名

	char szFileName[80 * MAX_PATH];//保存歌曲的全路径

	char szPath[80 * MAX_PATH];//储存路径

	char OpenMusicFile[MAX_PATH];//保存路径(用于操作音乐)

	HWND m_hWnd;
	DWORD DeviceId;
	MCI_OPEN_PARMS mciopenparms;
public:
	afx_msg void OnBnClickedPlay();
};
