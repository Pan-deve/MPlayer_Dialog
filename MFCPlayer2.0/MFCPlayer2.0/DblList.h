#include"pch.h"
#include"DblNode.h"
#pragma once
class DblList
{
    DblNode* head, * current;
public:
    DblList();
    ~DblList();

    void InsertRear(const CString&,const CString&);
    DblNode* Remove(DblNode* p);
    //void Print();  
    int Length();                            //����������  
    //DblNode<T> *Find(T data);                //���������붨ֵ��ͬ�Ľ��  
    void MakeEmpty();                        //�������  
    //�������� 
    CString GetADDRESS(int);                        //��ȡ������ͷ��ʼ����ĵ�n������
    CString GetNAME(int);
    void combine(DblList&, DblList&);    //��ɾ���ĺϲ�
    void combine_cut(DblList&, DblList&);//ɾ���ظ���Ԫ�غ�ϲ�
    void order();                                    //��˫���б��С��������
    void change(DblNode*,DblNode*);            //�����б�������Ԫ�ص�λ��
    void OutFile();       //�������������Ϊһ��text�ı���
};