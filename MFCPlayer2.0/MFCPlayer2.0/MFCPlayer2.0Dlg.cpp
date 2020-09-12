
// MFCPlayer2.0Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCPlayer2.0.h"
#include "MFCPlayer2.0Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCPlayer20Dlg 对话框



CMFCPlayer20Dlg::CMFCPlayer20Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPLAYER20_DIALOG, pParent)
	, edit_Playroom(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	numberOfFiles = 0;
}

void CMFCPlayer20Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ListOfName, edit_Playroom);
	DDX_Control(pDX, IDC_ListOfName, m_ListOfName);
}

BEGIN_MESSAGE_MAP(CMFCPlayer20Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_AddMusic, &CMFCPlayer20Dlg::OnBnClickedAddmusic)
	ON_BN_CLICKED(IDC_PLAY, &CMFCPlayer20Dlg::OnBnClickedPlay)
END_MESSAGE_MAP()


// CMFCPlayer20Dlg 消息处理程序

BOOL CMFCPlayer20Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCPlayer20Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCPlayer20Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCPlayer20Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCPlayer20Dlg::OnBnClickedAddmusic()
{
/*	// TODO: 在此添加控件通知处理程序代码
	CFileDialog DocSelectDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_ALLOWMULTISELECT, "MP3音频文件(*.mp3)|*.mp3", NULL);
	DocSelectDlg.m_ofn.nMaxFile = 100 * MAX_PATH;     // 100   Files   
	DocSelectDlg.m_ofn.lpstrFile = new   TCHAR[DocSelectDlg.m_ofn.nMaxFile];
	ZeroMemory(DocSelectDlg.m_ofn.lpstrFile, sizeof(TCHAR) * DocSelectDlg.m_ofn.nMaxFile);
	CString buf[1000];
	//	int num = 0;
	int i = 0;
	HWND hwnd= AfxGetMainWnd()->m_hWnd;
	if (DocSelectDlg.DoModal() == IDCANCEL)return;
	else
	{
		POSITION pos = DocSelectDlg.GetStartPosition();
		while (pos != NULL)
		{
			buf[numberOfFiles] = DocSelectDlg.GetNextPathName(pos);
			numberOfFiles++;
		}
		//		pos = DocSelectDlg.GetStartPosition();

		
		m_PathOfMusicDoc = new CString[numberOfFiles];
		m_NameOfMusicDoc = new CString[numberOfFiles];
		pos = DocSelectDlg.GetStartPosition();
		while (pos != NULL)
		{
			m_NameOfMusicDoc[i] = DocSelectDlg.GetFileName();
			m_PathOfMusicDoc[i] = DocSelectDlg.GetNextPathName(pos);
		}
	}
	Load(hwnd, m_PathOfMusicDoc[1]);*/
	
	TCHAR* p;//用于遍历音乐文件

	int len = 0;
	HWND hwnd = AfxGetMainWnd()->m_hWnd;
	FileInit(hwnd);//文件初始化

	if (OpenFileDlg())
	{
		/*把第一个文件名复制到szPath
			如果只选了一个文件,就复制到最后一个'\'
			如果选了多个文件,就复制到第一个NULL字符*/

		lstrcpyn(szPath, szOpenFileName, ofn.nFileOffset);
		/*当只选了一个文件时,下面的NULL是必须的
		这是不区别待选了一个和多个文件情况*/
		

		szPath[ofn.nFileOffset] = '\0';

		len = lstrlen(szPath);

		if (szPath[len - 1] != '\\')
		{
			lstrcat(szPath, TEXT("\\"));
		}

		p = szOpenFileName + ofn.nFileOffset;
	
		ZeroMemory(szFileName, sizeof(szFileName));

//		HWND hwndList = GetDlgItem(IDC_ListOfName);
		
		while (*p)
		{
			lstrcat(szFileName, szPath);/*给文件名加上路径*/

			lstrcat(szFileName, p);/*加上文件名*/
			lstrcat(szFileName, "!");
			AfxExtractSubString(m_PathOfMusicDoc[numberOfFiles], szFileName, numberOfFiles,'!');

//			ListBox_InsertString(hwndList, -1, p);
			m_ListOfName.AddString(p);
//			lstrcat(szFileName, TEXT("\n"));/*换行

			numberOfFiles++;
			p += lstrlen(p) + 1;/*移到下一个文件*/
		}
//		m_PathOfMusicDoc = new CString[numberOfFiles];
	
		
	}


}

void CMFCPlayer20Dlg::FileInit(HWND hwnd)
{
	//文件结构清零
	ZeroMemory(&ofn, sizeof(ofn));

	//文件结构的大小
	ofn.lStructSize = sizeof(ofn);

	//文件路径
	ofn.lpstrFile = szOpenFileName;

	ofn.lpstrFile[0] = TEXT('\0');

	ofn.nMaxFile = sizeof(szOpenFileName);

	//过滤器
	ofn.lpstrFilter = TEXT("所有支持文件(*.wav,*.mp3,*.wma)\0*.wav;*.mp3;*.wma\0wave文件(*.wav)\0*.wav\0mp3文件(*.mp3)\0*.mp3\0wma文件(*.wma)\0*.wma\0");

	ofn.nFilterIndex = 1;

	ofn.lpstrFileTitle = NULL;

	ofn.nMaxFileTitle = 0;

	ofn.lpstrInitialDir = NULL;

	ofn.hwndOwner = hwnd;

	ofn.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_ALLOWMULTISELECT;

}

int CMFCPlayer20Dlg::OpenFileDlg(void)
{
	return GetOpenFileName(&ofn);
}

void CMFCPlayer20Dlg::Load(HWND hWnd, CString strFilepath)
{
	m_hWnd = hWnd;
	mciSendCommand(DeviceId, MCI_CLOSE, 0, 0); //在加载文件前先清空上一次播放的设备
	mciopenparms.lpstrElementName = strFilepath; //将音乐文件路径传给设备
	DWORD dwReturn;
	if (dwReturn = mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_WAIT, (DWORD)(LPVOID)&mciopenparms))
	{
		//如果打开玩家失败,将出错信息储存在buffer,并显示出错警告
		char buffer[256];
		mciGetErrorString(dwReturn, buffer, 256); //获取错误码对应的错误信息
//		MessageBox(hWnd, buffer, "出错警告！", MB_ICONHAND | MB_ICONERROR | MB_ICONSTOP); //弹出错误信息提示对话框
	}
	DeviceId = mciopenparms.wDeviceID;
}

void CMFCPlayer20Dlg::play()
{
//	Load(m_hWnd, m_PathOfMusicDoc[1]);
	MCI_PLAY_PARMS mciplayparms;
	mciplayparms.dwCallback = (DWORD)m_hWnd;
	mciplayparms.dwFrom = 0; //每次播放都是从0开始播放
	mciSendCommand(DeviceId, MCI_PLAY, MCI_FROM | MCI_NOTIFY, (DWORD)(LPVOID)&mciplayparms);
}


void CMFCPlayer20Dlg::OnBnClickedPlay()
{
	// TODO: 在此添加控件通知处理程序代码
	play();
	SetDlgItemText(IDC_STOP, "暂停");
}
