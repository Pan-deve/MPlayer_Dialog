/*
����ϰ��7.7��Ҫ�������Ѹ���˫������ʵ�ֵ����Ա���ģ�壬

    ������һ����ģ�壬���������ڲ�ͬ���б�Ԫ�����͡���ˣ�����ģ�嶨�壬����ͨ���ԡ�
�Ѹ��α�P240 ��7.7��˫��������ģ�塣˫������Ľ������࣬�����йصĻ�����������Ϊ
�����ĳ�Ա��������˫����������Ĳ�������Ϊ������ĳ�Ա����������:
��������������ݡ����������ȡ���ӡ�������ݡ��Ƴ�ָ�����
�����������ȵȡ�
ע��
    ������ɾ��ָ�����Ĳ���û����ȫ��װ�����ڣ��������޸�Ϊ�����ڽ�ɾ��������ȫ��װ��

���Ҫ��
-    1 ϰ��7.7 �����������˫������ϲ�Ϊһ�������˫������������Ϊ�Ƿ�ȥ����������ͬ
   �Ľ����������������� 
-    2 ���ԣ������ӵĳ�Ա����ģ��Ĳ��ԡ�
*/
#include"pch.h"

#include"DblList.h"
using namespace std;


class DblList;   //ǰ����������  



//======== ������ģ�嶨�忪ʼ ========//
//�ٶ��������࣬ѡ���ò����������������������������������롢ɾ����ȡ���ݵ� 


DblList::DblList()
{
    //������ͷ���  
    head=new DblNode();  
    head->rlink=head->llink=head;  
    current=NULL; 
} 

DblList::~DblList()
{
    MakeEmpty();                             //�������  
    delete head; 
} 

void DblList::MakeEmpty()
{
    DblNode *tempP;  
    
    while(head->rlink!=head)
    {
    	
        tempP=head->rlink;   
        head->rlink=tempP->rlink;          //��ͷ����ĵ�һ���ڵ����������   
        tempP->rlink->llink=head;          //������ָ��   
        delete tempP;                      //ɾ��(�ͷ�)���������Ľ��  
    }  
    current=NULL;                          //currentָ��ָ� 
} 

void DblList::InsertRear(const CString & add,const CString & name)
{
    //�½ڵ�����β  
    current=new DblNode;  
    current->songname=name;  
    current->address=add;  
    current->rlink=head;                   //ע�����  
    current->llink=head->llink;  
    head->llink->rlink=current;  
    head->llink=current;                   //����� 
} 

DblNode* DblList::Remove(DblNode* p)
{
    current=head->rlink;  
    while(current!=head&&current!=p) current=current->rlink;  
    if(current==head) current=NULL;  
    else                                   //ժ�½�� 
    {
    	p->llink->rlink=p->rlink;   
    	p->rlink->llink=p->llink;   
    	p->rlink=p->llink=NULL;  
    }  
    delete current;          
    return current; 
    //������ָ����ɾ���Ľ�㣬����δ�����Ա���������ɾ�������� 
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
    //if (n<1 || n>Length())cout << "���ݴ���" << endl, exit(0);
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
    //if (n<1 || n>Length())cout << "���ݴ���" << endl, exit(0);
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
	    	 