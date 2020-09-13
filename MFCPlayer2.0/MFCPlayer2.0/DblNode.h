#include"pch.h"
#pragma once
//======== 头结点类模板定义开始 ========//
//首先看结点组织，采用结点类，凡与结点数据和指针操作有关函数作为成员函数 
class DblNode
{
    CString address;                    //数据域 
    CString songname;
    DblNode* llink, * rlink;  //前驱（左链）、后继（右链）指针 
public:
    DblNode(CString, CString);
    DblNode();  
    CString Getaddress();
    CString Getsongname();
    friend class DblList;
    //以List为友元类，List可直接访问Node的私有成员，与结构一样方便，但更安全 
}; 
