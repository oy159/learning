//
// Created by 86187 on 2022/10/16.
//
#include "../Inc/node.h"

Node *InitNode() {
    Node *p = (Node *) malloc(sizeof(Node));
    p->next = NULL;
    return p;
}

Node *CreateNode(const int *x, int len) {
    Node *p;
    p = InitNode();
    Node *t, *n;
    t = p;
    p->data = *x;
    int *c;
    for (int j = 1; j < len; ++j) {
        n = (Node *) malloc(sizeof(Node));
        n->data = *(x + j);
        n->next = NULL;
        t->next = n;
        t = t->next;
    }
    return p;
}

Node* CreateCirNode(const int *x,int len){
    Node *p;
    p = InitNode();
    Node *t, *n;
    t = p;
    p->data = *x;
    int *c;
    for (int j = 1; j < len; ++j) {
        n = (Node *) malloc(sizeof(Node));
        n->data = *(x + j);
        n->next = p;
        t->next = n;
        t = t->next;
    }
    return p;
}


//设计算法删除单链表中大于mink且小于maxk的所有元素，并释放被删结点的存储空间
Node *Deletexy(Node *p, int mink, int maxk) {
    Node *n = (Node *) malloc(sizeof(Node));
    n->next = p;
    if (p->data >= mink && p->data <= maxk){
        n->next=p->next;
        p=p->next;
    }
    for (int i = 0; p->next; ++i) {
        if (p->next->data >= mink && p->next->data <= maxk) {
            p->next = p->next->next;
        } else {
            p = p->next;
        }
    }
    return n->next;
}

void DisplayAllNode(Node *p)
{
    while (p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
}

//判断循环单链表是否递增有序
int NodeCirIncreasing(Node *p){
    Node *n,*m;
    int flag=1;
    n=p;
    while(1){
        if(p->data<=p->next->data){
            m=p;
            p=p->next;
            break;
        }
        p=p->next;
    }
    while(p->next!=m){
        if(p->data<=p->next->data){
            p=p->next;
        }else{
            flag=0;
            break;
        }
    }
    return flag;
}

/*将单链表扩展2倍，假设线性表为(a1, a2, ..., an)，扩展后为(a1, a1, a2, a2, ..., an, an)*/
Node *NodeSameExtension(Node *p){
    Node *n;
    n=p;
    while(p!=NULL){
        Node *m=(Node *) malloc(sizeof(Node));
        m->data=p->data;
        m->next=p->next;
        p->next=m;
        p=p->next->next;
    }
    return n;
}


Node *Inittop(void) {
    Node *top = (Node *) malloc(sizeof(Node));
    top->next = NULL;
    return top;
}


Node *Push(Node *top, int x) {
    Node *s = (Node *) malloc(sizeof(Node));
    if (top == NULL) {
        s->data = x;
        s->next = NULL;
        top = s;
    } else {
        s->data = x;
        s->next = top;
        top = s;
    }
    return top;
}


int Pop(Node *top, int *x) {
    Node *t;
    if (top->next != NULL) {
        t = top->next;
        *x = top->data;
        top->next = t->next;
        free(t);
    } else {
        printf("栈空无法弹出");
        return 0;
    }
    return 1;
}

LinkQueue *InitLinkQueue(void){
    LinkQueue  *p=(LinkQueue*)malloc(sizeof(LinkQueue));
    Node *n=(Node *) malloc(sizeof(Node));
    p->front=n;
    p->rear=n;
    p->front->next=NULL;
    p->rear->next=NULL;
    return p;
}

void EnLinkQueue(LinkQueue *q,int x){
    Node *p=(Node *)malloc(sizeof(Node));
    p->data=x;
    p->next=NULL;
    q->rear->next=p;
    q->rear=p;
    if(q->front->next==NULL){
        q->front->next=p;
    }
}

void DeLinkQueue(LinkQueue *q,int *x){
    if(q->front==q->rear){
        printf("队列清空");
    }else{
        *x=q->front->next->data;
        q->front->next=q->front->next->next;
        if(q->front->next==NULL)q->rear=q->front;
    }
}

void DisplayAllLinkQueue(LinkQueue q){
    while(q.front->next!=NULL){
        printf("%d\t",q.front->next->data);
        q.front=q.front->next;
    }
    printf("\n");
}

int EmptyLinkQueue(LinkQueue *q){
    if(q->front==q->rear){
        return 1;
    }
    return 0;
}

