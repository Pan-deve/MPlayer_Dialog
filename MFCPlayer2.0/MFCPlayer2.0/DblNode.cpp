#include"pch.h"
#include"DblNode.h"
class DblList;   //前向引用声明  

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

//======== 头结点类模板定义完成 ========//
