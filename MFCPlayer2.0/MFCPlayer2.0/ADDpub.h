#pragma once
#include <afxdialogex.h>
#include"DblList.h"
#include"DblNode.h"
class ADDpub :public CDialogEx
{
public:
	ADDpub() {};
	virtual ~ADDpub() {};
	void FileInit(HWND hwnd);		//���ļ���ʼ���ļ��Ի���
	int OpenFileDlg(void);			//���ļ��Ի���
    CString m_PathOfMusicDoc[MAX_PATH * 80];		//��Ӹ����ļ�ʱ��·��
	int numberOfFiles;				//�ļ�������
	CListBox m_ListOfName;
	OPENFILENAME ofn;//���ļ��Ի�����ļ��ṹ

	char szOpenFileName[80 * MAX_PATH];//�����ļ���

	char szFileName[80 * MAX_PATH];//���������ȫ·��

	char szPath[80 * MAX_PATH];//����·��

	void jiaone(CListBox*);
	friend class LIST1;

	DblList L1;      //��ͬ�赥�ϵ��б�

};

