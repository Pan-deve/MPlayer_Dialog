#include"pch.h"
#include"DblNode.h"
class DblList;   //ǰ����������  

using namespace std;


DblNode::DblNode()
{
    llink=rlink=NULL;
} 

CString DblNode::Getaddress()
{
    return address;
}

CString DblNode::Getsongname()
{
    return songname;
}

DblNode::DblNode(CString add, CString name)
{
    address = add; songname = name;  llink = NULL;  rlink = NULL;
}

//======== ͷ�����ģ�嶨����� ========//
