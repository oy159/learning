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

void InsertSortNode(Node *p) {
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


void BubbleSortNode(Node *p){
    int len=LenNode(p);
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len-i-1; ++j) {
            p=BubbleMax(p,j);
            DisplayAllNode(p);
            printf("\n");
        }
    }
}

Node *SimpleSelect(Node *p,int i){
    Node *m = (Node *) malloc(sizeof(Node));
    int len=LenNode(p);
    Node *q;
    Node *temp;
    m->next = p;
    q=p;
    for (int j = 0; j < i; ++j) {
        q=q->next;
    }
    for (int j = 0; j < i+1; ++j) {
        p=p->next;
    }
    for (int j = i; j < len-1; ++j) {
        if(p->data<q->data){
            temp=GetOutNode(m->next,j+2);
            m->next=InsertNode(m->next,temp,i+1);
            temp=GetOutNode(m->next,i+2);
            m->next=InsertNode(m->next,temp,j+2);
            q=m->next;
            for (int k = 0; k < i; ++k) {
                q=q->next;
            }
            p=m->next;
            for (int h = 0; h < j+2; ++h) {
                p=p->next;
            }
            DisplayAllNode(m->next);
            printf("\n");
        }else
            p=p->next;
    }
    return m->next;
}


void SimpleSelectSortNode(Node *p){
    int len=LenNode(p);
    for (int i = 0; i < len; ++i) {
        p=SimpleSelect(p,i);
    }
}

Node *TraverNode(Node *p,int x){
    for (int i = 0; i < x; ++i) {
        p=p->next;
    }
    return p;
}

void InsertSortSeq(seqList *p){
    int len=1;
    int temp;
    for (int i = len; i < p->length; ++i) {
        for (int j = 0; j < i; ++j) {
            if(p->data[i]<p->data[j]){
                temp=p->data[i];
                DeleteSeq(p,i);
                insertSeqlist(p,temp,j);
            }
            DisplayAllSeq(*p);
            printf("\n");
        }
    }
}

void BubbleSortSeq(seqList *p){
    for (int i = 0; i < p->length; ++i) {
        for (int j = 0; j < p->length-i-1; ++j) {
            if (p->data[j]>p->data[j+1]){
                SwipSeqlist(p,j,j+1);
            }
            DisplayAllSeq(*p);
            printf("\n");
        }
    }
}


