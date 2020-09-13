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
	//�ļ��ṹ����
	ZeroMemory(&ofn, sizeof(ofn));

	//�ļ��ṹ�Ĵ�С
	ofn.lStructSize = sizeof(ofn);

	//�ļ�·��
	ofn.lpstrFile = szOpenFileName;

	ofn.lpstrFile[0] = TEXT('\0');

	ofn.nMaxFile = sizeof(szOpenFileName);

	//������
	ofn.lpstrFilter = TEXT("����֧���ļ�(*.wav,*.mp3,*.wma)\0*.wav;*.mp3;*.wma\0wave�ļ�(*.wav)\0*.wav\0mp3�ļ�(*.mp3)\0*.mp3\0wma�ļ�(*.wma)\0*.wma\0");

	ofn.nFilterIndex = 1;

	ofn.lpstrFileTitle = NULL;

	ofn.nMaxFileTitle = 0;

	ofn.lpstrInitialDir = NULL;

	ofn.hwndOwner = hwnd;

	ofn.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_ALLOWMULTISELECT;

}

void ADDpub::jiaone(CListBox*one)
{
	TCHAR* p;//���ڱ��������ļ�

	int len = 0;
	HWND hwnd = AfxGetMainWnd()->m_hWnd;
	FileInit(hwnd);//�ļ���ʼ��

	if (OpenFileDlg())
	{
		/*�ѵ�һ���ļ������Ƶ�szPath
			���ֻѡ��һ���ļ�,�͸��Ƶ����һ��'\'
			���ѡ�˶���ļ�,�͸��Ƶ���һ��NULL�ַ�*/
		lstrcpyn(szPath, szOpenFileName, ofn.nFileOffset);
		/*��ֻѡ��һ���ļ�ʱ,�����NULL�Ǳ����
		���ǲ������ѡ��һ���Ͷ���ļ����*/
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
			lstrcat(szFileName, szPath);/*���ļ�������·��*/

			lstrcat(szFileName, p);/*�����ļ���*/
			lstrcat(szFileName, "!");
			AfxExtractSubString(m_PathOfMusicDoc[numberOfFiles], szFileName, numberOfFiles, '!');
			one->AddString(p);


			numberOfFiles++;
			p += lstrlen(p) + 1;/*�Ƶ���һ���ļ�*/
		}

		//L1;
	}


}