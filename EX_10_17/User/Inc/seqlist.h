//
// Created by 86187 on 2022/10/12.
// Describe : 顺序表
//

#ifndef LEARNING_SEQLIST_H
#define LEARNING_SEQLIST_H
#define MAXLENGTH 100
#define QUEUEMAXLENGTH 5
#define STACKMAXLENGTH 4

#include "stdio.h"
typedef struct {
    int data[MAXLENGTH];
    int length;
} seqList;

typedef struct {
    int data[QUEUEMAXLENGTH];
    int front,rear;
}Queue;

typedef struct {
    int data[STACKMAXLENGTH];
    int top;
}Stack;



/// 初始化
/// \param list
/// \param x 初始化顺序表
/// \param len 传入数组
void initSeqlist(seqList *list, const int *x, int len);


/// 插入
/// \param list 表
/// \param x 值
/// \param i 下标
void insertSeqlist(seqList *list, int x, int i);



void SwipSeqlist(seqList *list, int i, int j);

void DeleteSeq(seqList *list, int i);


/// display list
/// \param list 表
void DisplayAllSeq(seqList list);


/// 删除[x,y]范围的值
/// \param list 传入表地址
/// \param x 下限
/// \param y 上限
/// \return 表
seqList DeleteSeqxy(seqList *list, int x, int y);

/*循环队列结构*/
void InitQueue(Queue *queue);
int EmptyCirQueue(Queue queue);
int FullCirQueue(Queue queue);
void EnCirQueue(Queue *queue, int x);
void DeCirQueue(Queue *queue, int *x);
void DisplayAllCirQueue(Queue queue);


/*顺序栈*/
void InitSeqStack(Stack* s);
void SeqPush(Stack* s,int x);
void SeqPop(Stack* s,int *x);
void DisplayAllSeqStack(Stack s);


#endif //LEARNING_SEQLIST_H
