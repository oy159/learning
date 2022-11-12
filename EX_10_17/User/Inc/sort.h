//
// Created by 86187 on 2022/10/17.
//

#ifndef LEARNING_SORT_H
#define LEARNING_SORT_H

#include "node.h"
#include "seqlist.h"

void InsertSortNode(Node *p);
void BubbleSortNode(Node *p);
void SimpleSelectSortNode(Node *p);


void InsertSortSeq(seqList *p);
void BubbleSortSeq(seqList *p);
void SimpleSelectSortSeq(seqList *p);
//void QuickSortSeq(seqList *p);
void Quick_Sort(seqList *p, int begin, int end);
int SeekSortTraver(seqList p,int x);
int SeekSortDivide(seqList p,int x);


#endif //LEARNING_SORT_H
