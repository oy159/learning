//
// Created by 86187 on 2022/11/3.
//

#ifndef LEARNING_TREE_H
#define LEARNING_TREE_H
#include "stdio.h"
#include "malloc.h"


typedef struct Tree{
    char data;
    struct Tree *left;
    struct Tree *right;
}Tree;

typedef struct {
    Tree *root;
    char ref;
}TreeRoot;

typedef struct TNode {
    Tree *data;
    struct TNode *next;
} TNode;


typedef struct {
    TNode *front,*rear;
}TLinkQueue;


TreeRoot *TreeRootInit();
void CreateTree(Tree **t, char **str);
void PrePrint(Tree *t);
void MidPrint(Tree *t);
void PostPrint(Tree *t);
void LevelPrint(Tree *t);
int PointSum(Tree *t,int i);
int DepthSum(Tree *t,int i,int *max);
int SinglePointSum(Tree *t,int *x);
void DrawTree(Tree *t);

#endif //LEARNING_TREE_H
