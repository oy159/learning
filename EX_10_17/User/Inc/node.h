//
// Created by 86187 on 2022/10/16.
// Describe : 链表
//

#ifndef LEARNING_NODE_H
#define LEARNING_NODE_H
#include "stdio.h"
#include "malloc.h"

typedef struct Node {
    int data;
    struct Node *next;
} Node;


typedef struct {
    Node *front,*rear;
}LinkQueue;

/*单链表*/
Node* InitNode(void);


/// 尾插法创建链表
/// \param x data
/// \param len 长度
/// \return 表
Node *CreateNode(const int *x,int len);


/// 创建循环链表
/// \param x
/// \param len
/// \return
Node* CreateCirNode(const int *x,int len);


/// 删除[mink,maxk]范围的值
/// \param p 传入链表
/// \param mink 上限
/// \param maxk 下限
/// \return 表指针
Node *Deletexy(Node *p, int mink, int maxk);


/// print
/// \param p 链表
void DisplayAllNode(Node *p);


/// 检测循环链表是否递增
/// \param p
/// \return
int NodeCirIncreasing(Node *p);


/// 扩展链表，重复每一个元素
/// \param p
/// \return
Node *NodeSameExtension(Node *p);


/*链栈结构*/
/// 初始化
/// \return top指针
Node *Inittop(void);


/// 出栈
/// \param top 栈顶指针
/// \param x 出栈值
/// \return 成功/失败
int Pop(Node *top, int *x);


/// 入栈
/// \param top 栈顶指针
/// \param x 压入栈的元素
/// \return 栈顶指针
Node *Push(Node *top, int x);

/*链队列*/

/// 初始化
/// \return 分配好的地址
LinkQueue *InitLinkQueue(void);

/// 增加队列元素（入队）
/// \param q 队列
/// \param x 元素
void EnLinkQueue(LinkQueue *q,int x);

/// 删除队列元素（出队）
/// \param q 队列
/// \param x 出队元素存放地址
void DeLinkQueue(LinkQueue *q,int *x);

/// 打印全部
/// \param q 队列
void DisplayAllLinkQueue(LinkQueue q);

///
/// \param q 队列
/// \return 成功 1 失败 0
int EmptyLinkQueue(LinkQueue *q);

#endif //LEARNING_NODE_H
