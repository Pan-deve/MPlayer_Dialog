/*
根据习题7.7的要求，完善已给出双向链表实现的线性表类模板，

    定义了一个类模板，可以适用于不同的列表元素类型。因此，用类模板定义，更具通用性。
已给课本P240 例7.7，双向链表类模板。双向链表的结点采用类，与结点有关的基本操作都作为
结点类的成员函数。对双向链表整体的操作则作为链表类的成员函数，包括:
清空链表、查找数据、计算链表长度、打印链表数据、移除指定结点
向后生成链表等等。
注：
    范例中删除指定结点的操作没有完全封装在类内，可自行修改为在类内将删除操作完全封装。

编程要求：
-    1 习题7.7 将两个有序的双向链表合并为一个有序的双向链表。可重载为是否去除数据域相同
   的结点的两个操作函数。 
-    2 测试：完成添加的成员函数模板的测试。
*/
#include"pch.h"

#include"DblList.h"
using namespace std;


class DblList;   //前向引用声明  



//======== 链表类模板定义开始 ========//
//再定义链表类，选择常用操作：包括建立有序链表、搜索遍历、插入、删除、取数据等 


DblList::DblList()
{
    //建立表头结点  
    head=new DblNode();  
    head->rlink=head->llink=head;  
    current=NULL; 
} 

DblList::~DblList()
{
    MakeEmpty();                             //清空链表  
    delete head; 
} 

void DblList::MakeEmpty()
{
    DblNode *tempP;  
    
    while(head->rlink!=head)
    {
    	
        tempP=head->rlink;   
        head->rlink=tempP->rlink;          //把头结点后的第一个节点从链中脱离   
        tempP->rlink->llink=head;          //处理左指针   
        delete tempP;                      //删除(释放)脱离下来的结点  
    }  
    current=NULL;                          //current指针恢复 
} 

void DblList::InsertRear(const CString & add,const CString & name)
{
    //新节点在链尾  
    current=new DblNode;  
    current->songname=name;  
    current->address=add;  
    current->rlink=head;                   //注意次序  
    current->llink=head->llink;  
    head->llink->rlink=current;  
    head->llink=current;                   //最后做 
} 

DblNode* DblList::Remove(DblNode* p)
{
    current=head->rlink;  
    while(current!=head&&current!=p) current=current->rlink;  
    if(current==head) current=NULL;  
    else                                   //摘下结点 
    {
    	p->llink->rlink=p->rlink;   
    	p->rlink->llink=p->llink;   
    	p->rlink=p->llink=NULL;  
    }  
    delete current;          
    return current; 
    //返回了指定待删除的结点，而并未在类成员函数中完成删除操作。 
} 
 
/*template<typename T> DblNode<T>* DblList<T>::Find(T data)
{
    current=head->rlink;  
    while(current!=head&&current->info!=data) current=current->rlink;  
    if(current==head) current=NULL;  
    return current; 
} 

template<typename T> void DblList<T>::Print()
{
    current=head->rlink;  
    while(current!=head)
    {
        cout<<current->info<<'\t';   
        current=current->rlink;  
    }  
    cout<<endl; 
} */

int DblList::Length()
{
    int count=0;  
    current=head->rlink; 
    while(current!=head)
    {
         count++;   
         current=current->rlink;  
    }  
    return count; 
}

CString DblList::GetADDRESS(int n)
{
    DblNode* pin = head;
    int i = 0;
    //if (n<1 || n>Length())cout << "数据错误" << endl, exit(0);
    while (i < n)
    {
        pin = pin->rlink;
        i++;
    }
    return pin->address;
}

CString DblList::GetNAME(int n)
{
    DblNode* pin = head;
    int i = 0;
    //if (n<1 || n>Length())cout << "数据错误" << endl, exit(0);
    while (i < n)
    {
        pin = pin->rlink;
        i++;
    }
    return pin->songname;
}
void DblList::combine(DblList& list1,DblList& list2)
{
    int i = 1, L1=list1.Length(),L2=list2.Length(),a=1;
    MakeEmpty();
    while (a <= L1)
    {
        InsertRear(list1.GetADDRESS(a),list1.GetNAME(a));
        a++;
    }
    a = 1;
    while (a <= L2)
    {
        InsertRear(list2.GetADDRESS(a),list2.GetNAME(a));
        a++;
    }
    order();
}
void DblList::combine_cut(DblList& list1, DblList& list2)
{
    combine(list1, list2);
    int i = 1;
    DblNode* current = head->rlink, * next = current->rlink;
    while (i <= Length())
    {
        if (current->address == next->address&&current->songname == next->songname)
        {
            Remove(current);
            current = next;
            next = next->rlink;
            i++;
        }
        else
        {
            current = next;
            next = next->rlink;
            i++;
        }
    }
}
void DblList::OutFile()
{
    int len;
    len = Length();
}
void DblList::order()
{
    int time = 1,i=1;
    DblNode* current = head->rlink, * next = current->rlink;
    while (time)
    {
        time = 0;
        i = 1;
        current = head->rlink, next = current->rlink;
        while (i<Length())
        {
            if (current->songname > next->songname)
            {
                change(current, next);
                current = next;
                next = current->rlink;
                time++;
            }
            else
            {
                current = next;
                next = current->rlink;
            }
            i++;
        }
    }
}

void DblList::change(DblNode* node1,DblNode* node2)
{
    CString tempaddre,tempname1;
    tempaddre = node1->address;
    tempname1 = node1->songname;
    node1->address = node2->address;
    node1->songname = node2->songname;
    node2->address = tempaddre;
    node2->songname = tempname1;
}
	    	 