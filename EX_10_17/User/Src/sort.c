//
// Created by 86187 on 2022/10/17.
//
#include "sort.h"

Node *InsertNode(Node *p, Node *temp, int i) {
    Node *m = (Node *) malloc(sizeof(Node));
    m->next = p;
    for (int j = 0; j < i - 2; ++j) {
        p = p->next;
    }
    if (i == 1) {
        temp->next = p;
        m->next = temp;
    } else {
        temp->next = p->next;
        p->next = temp;
    }
    return m->next;
}

Node *GetOutNode(Node *p, int i) {
    Node *m = (Node *) malloc(sizeof(Node));
    Node *temp;
    m->next = p;
    for (int j = 0; j < i - 1; ++j) {
        m = m->next;
    }
    temp = m->next;
    m->next = m->next->next;
    return temp;
}

int FindMax(Node *p, int x, int len) {
    int i;
    for (i = 0; i < len; ++i) {
        if (x < p->data) {
            return i + 1;
        } else {
            p = p->next;
        }
    }
    return i + 1;
}

void InsertSort(Node *p) {
    Node *q;
    Node *temp;
    int x, len = 1;
    q = p;
    DisplayAllNode(p);
    printf("\n");
    while (q->next != NULL) {
        x = FindMax(p, q->next->data, len);
        temp = GetOutNode(q, 2);
        p = InsertNode(p, temp, x);
        len++;
        DisplayAllNode(p);
        printf("\n");
        if (x == len) {
            q = q->next;
        }
    }
}

int LenNode(Node *p){
    int len =0;
    while (p!=NULL){
        len++;
        p=p->next;
    }
    return len;
};

Node *BubbleMax(Node *p,int j){
    Node *m = (Node *) malloc(sizeof(Node));
    Node *q;
    m->next = p;
    for (int i = 0; i < j; ++i) {
        p=p->next;
    }
    if (p->data>p->next->data){
        if (j==0){
            m->next=p->next;
            p->next=p->next->next;
            m->next->next=p;
            return m->next;
        }else{
            q=GetOutNode(m->next,j+1);
            m->next=InsertNode(m->next,q,j+2);
            return m->next;
        }
    }else{
        return m->next;
    }
}


void BubbleSort(Node *p){
    int len=LenNode(p);
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len-i-1; ++j) {
            p=BubbleMax(p,j);
            DisplayAllNode(p);
            printf("\n");
        }
    }
}