#include "pch.h"
#include "ADDpub.h"
#include"DblList.h"
#include"DblNode.h"
int ADDpub::OpenFileDlg(void)
{
	return GetOpenFileName(&ofn);
}
void ADDpub::FileInit(HWND hwnd)
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

void ADDpub::jiaone(CListBox*one)
{
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
		while (*p)
		{
			lstrcat(szFileName, szPath);/*给文件名加上路径*/

			lstrcat(szFileName, p);/*加上文件名*/
			lstrcat(szFileName, "!");
			AfxExtractSubString(m_PathOfMusicDoc[numberOfFiles], szFileName, numberOfFiles, '!');
			one->AddString(p);


			numberOfFiles++;
			p += lstrlen(p) + 1;/*移到下一个文件*/
		}

		//L1;
	}


}