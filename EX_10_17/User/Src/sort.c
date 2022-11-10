//
// Created by 86187 on 2022/10/17.
//
#include "sort.h"
Node *InsertNode(Node *p,Node *temp,int i){
    Node *m = (Node *) malloc(sizeof(Node));
    m->next=p;
    for (int j = 0; j < i-2; ++j) {
        p=p->next;
    }
    if(i==1){
        temp->next=p;
        m->next=temp;
    }else{
        temp->next=p->next;
        p->next=temp;
    }
    return m->next;
}

Node *GetOutNode(Node *p,int i){
    Node *m = (Node *) malloc(sizeof(Node));
    Node *temp;
    m->next=p;
    for (int j = 0; j < i-1; ++j) {
        m=m->next;
    }
    temp=m->next;
    m->next=m->next->next;
    return temp;
}

int FindMax(Node *p,int x,int len){
    int i;
    for (i = 0; i < len; ++i) {
        if(x<p->data){
            return i+1;
        }else{
            p=p->next;
        }
    }
    return i+1;
}

void InsertSort(Node *p){
    Node *q;
    Node *temp;
    int x,len=1;
    q=p;
    DisplayAllNode(p);
    printf("\n");
    for (int i = 0; q->next != NULL; ++i) {
        x=FindMax(p,q->next->data,len);
        temp=GetOutNode(q,2);
        p=InsertNode(p,temp,x);
        len++;
        DisplayAllNode(p);
        printf("\n");
        if(x==len){
            q=q->next;
        }
    }
}