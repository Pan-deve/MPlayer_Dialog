#include"pch.h"
#pragma once
//======== ͷ�����ģ�嶨�忪ʼ ========//
//���ȿ������֯�����ý���࣬���������ݺ�ָ������йغ�����Ϊ��Ա���� 
class DblNode
{
    CString address;                    //������ 
    CString songname;
    DblNode* llink, * rlink;  //ǰ��������������̣�������ָ�� 
public:
    DblNode(CString, CString);
    DblNode();  
    CString Getaddress();
    CString Getsongname();
    friend class DblList;
    //��ListΪ��Ԫ�࣬List��ֱ�ӷ���Node��˽�г�Ա����ṹһ�����㣬������ȫ 
}; 
