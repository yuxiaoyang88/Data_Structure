#include <iostream>
#include "带有头指针的单链表.hpp"
using namespace std;

template<class ElemType>
void LinkList_Reverse(LNode<ElemType>& linkList);

int main(int argc, char** argv) {
    //初始化
    LNode<int> linkList;
    const int  length       = 11;
    int        data[length] = {2, 3, 5, 9, 1, 8, 2, 3, 2, 7, 6};
    linkList.create(data, length);
    //打印
    linkList.print();
    //逆置单链表，遍历的过程中改变指针指向
    LinkList_Reverse(linkList);
    //打印
    linkList.print();
    return 1;
}

//逆置单链表，遍历的过程中改变指针指向
template<class ElemType>
void LinkList_Reverse(LNode<ElemType>& linkList) {
    //问题1，后面有解答
    LNode<ElemType>* firstPoint = NULL;
    // point是从第二个元素开始的
    LNode<ElemType>* point = linkList.next->next;
    //将第一个元素的next指针置为NULL，因为它将是新单链表的最后一个元素
    //这一步不写，新单链表最后结点不为空，如果打印会出现无限循环。
    linkList.next->next = NULL;
    // tmpPoint是用来帮助point完成point->next = firstPoint;
    //问题2，后面有解答
    LNode<ElemType>* tmpPoint = NULL;
    while (point) {
        firstPoint = linkList.next;
        //要干两件事
        //老单链表头指针指向point
        // point指向老单链表第一个元素
        linkList.next = point;
        // tmpPoint有两种用法
        /*tmpPoint = point;
        point = point->next;
        tmpPoint->next = firstPoint;*/
        tmpPoint    = point->next;
        point->next = firstPoint;
        point       = tmpPoint;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------------------------------------//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//问题1
//我使用了第二种写法
//第二种写法跟第一种写法思路上完全一样，是一种方法
//第一种少写一些，计算量小，写法不容易理解
//第二种写法容易理解，容易拿分
//这是第一种写法
//请完全注销掉第二种写法之后再打开第一种写法
// LNode* firstPoint = NULL;
// LNode* point = linkList->next;
// LNode* nextPoint = point->next;
////将第一结点next指为NULL
// point->next = NULL;
// while (nextPoint) {
//	//firstPoint是用来存放LinkList中头结点之外的第一个元素
//	//因为nextPoint是从老单链表加入新单链表的第一个元素
//	//如果那么新单链表的第一个元素firstPoint就为point
//	firstPoint = point;
//	point = nextPoint;
//	nextPoint = nextPoint->next;
//	point->next = firstPoint;
//}
//	linkList->next = point;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------------------------------------//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//问题2
//如果point->next = firstPoint;先执行，point =
// point->next;可以看到point->next改变了，point->next赋给XX就错了。 反之point =
// point->next;先执行，point->next =
// firstPoint;可以看到point本身变了，再执行point->next=XX就错了。
//所以需要借助第三个指针tmpPoint帮助完成这两句话。
//要么把point赋值给tmpPoint，要么把point->next赋值给tmpPoint。
//把point赋值给tmpPoint
// tmpPoint = point;
// point = point->next;
// tmpPoint->next = firstPoint;
//把point->next赋值给tmpPoint
// tmpPoint = point->next;
// point->next = firstPoint;
// point = tmpPoint;
//都行，写对就可以，没思考过还是要想一下

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------------------------------------//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////