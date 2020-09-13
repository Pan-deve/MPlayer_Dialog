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
    int Length();                            //计算链表长度  
    //DblNode<T> *Find(T data);                //搜索数据与定值相同的结点  
    void MakeEmpty();                        //清空链表  
    //其它操作 
    CString GetADDRESS(int);                        //获取从链表头开始计算的第n个数据
    CString GetNAME(int);
    void combine(DblList&, DblList&);    //不删减的合并
    void combine_cut(DblList&, DblList&);//删减重复的元素后合并
    void order();                                    //将双向列表从小到大有序化
    void change(DblNode*,DblNode*);            //交换列表中两个元素的位置
    void OutFile();       //将数据依次输出为一个text文本中
};