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

void BubbleSortSeq(seqList *p);


void InsertSortSeq(seqList *p);

#endif //LEARNING_SORT_H
