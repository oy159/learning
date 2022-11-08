//
// Created by 86187 on 2022/11/3.
//
#include "../Inc/tree.h"

TreeRoot *TreeRootInit() {
    TreeRoot *t = (TreeRoot *) malloc(sizeof(TreeRoot));
    t->ref=' ';
    return t;
}

void CreateTree(Tree **t, char **str) {
    if (**str == '#') {
        *t = NULL;
    } else {
        *t = (Tree *) malloc(sizeof(Tree));
        (*t)->data = **str;
        *(&(*str))=(*str+1);
        CreateTree(&(*t)->left,(&(*str)));
        *(&(*str))=(*str+1);
        CreateTree(&(*t)->right,&(*str));
    }
}

void PrePrint(Tree *t) {
    if(t==NULL){
        return;
    }else{
        printf("%c",t->data);
        PrePrint(t->left);
        PrePrint(t->right);
    }
}

void MidPrint(Tree *t){
    if(t==NULL){
        return;
    }else{
        PostPrint(t->left);
        printf("%c",t->data);
        PostPrint(t->right);
    }
}


void PostPrint(Tree *t){
    if(t==NULL){
        return;
    }else{
        PostPrint(t->left);
        PostPrint(t->right);
        printf("%c",t->data);
    }
}



TLinkQueue *InitTLinkQueue(void){
    TLinkQueue  *p=(TLinkQueue*)malloc(sizeof(TLinkQueue));
    TNode *n=(TNode *) malloc(sizeof(TNode));
    p->front=n;
    p->rear=n;
    p->front->next=NULL;
    p->rear->next=NULL;
    return p;
}

void EnLinkTQueue(TLinkQueue *q,Tree *x){
    TNode *p=(TNode *)malloc(sizeof(TNode));
    p->data=x;
    p->next=NULL;
    q->rear->next=p;
    q->rear=p;
    if(q->front->next==NULL){
        q->front->next=p;
    }
}

void DeLinkTQueue(TLinkQueue *q,Tree *x){
    if(q->front==q->rear){
        printf("队列清空");
    }else{
        *x=*q->front->next->data;
        q->front->next=q->front->next->next;
        if(q->front->next==NULL)q->rear=q->front;
    }
}


int EmptyLinkTQueue(TLinkQueue *q){
    if(q->front==q->rear){
        return 1;
    }
    return 0;
}

int LevelOrder(TLinkQueue *q){
    Tree x;
    if(!EmptyLinkTQueue(q)){
        DeLinkTQueue(q,&x);
        printf("%c",x.data);
        if(x.left!=NULL){
            EnLinkTQueue(q,x.left);
        }
        if(x.right!=NULL){
            EnLinkTQueue(q,x.right);
        }
        return 1;
    } else{
        return 0;
    }
}

void LevelPrint(Tree *t){
    TLinkQueue *q;
    q=InitTLinkQueue();
    EnLinkTQueue(q,t);
    while(LevelOrder(q));
}

int PointSum(Tree *t,int i){
    if(t==NULL){
        return i;
    }else{
        i++;
        i=PointSum(t->left,i);
        i=PointSum(t->right,i);
        return i;
    }
}

int DepthSum(Tree *t,int i,int *max){
    if(i>*max)
    {
        *max=i;
    }
    if(t==NULL){
        return i;
    }else{
        i++;
        i=DepthSum(t->left,i,&(*max));
        i=DepthSum(t->right,i,&(*max));
        return i-1;
    }
}

int SinglePointSum(Tree *t,int *x){
    if(t==NULL){
        return 0;
    }
    if(t->left!=NULL&&t->right!=NULL){
        SinglePointSum(t->left,&(*x));
        SinglePointSum(t->right,&(*x));
    }else if(t->left==NULL&&t->right==NULL){
        return 0;
    }else{
        *x=*x+1;
        SinglePointSum(t->left,&(*x));
        SinglePointSum(t->right,&(*x));
    }
    return 0;
}

//int DrawLevelOrder(TLinkQueue *q,int dep){
//    Tree x;
//    if(!EmptyLinkTQueue(q)){
//        DeLinkTQueue(q,&x);
//        printf("%c",x.data);
//        if(x.left!=NULL){
//            EnLinkTQueue(q,x.left);
//        }
//        if(x.right!=NULL){
//            EnLinkTQueue(q,x.right);
//        }
//        return 1;
//    } else{
//        return 0;
//    }
//}
//
//
//void DrawTree(Tree *t){
//    TLinkQueue *q;
//    q=InitTLinkQueue();
//    int dep;
//    DepthSum(t,0,&dep);
//    EnLinkTQueue(q,t);
//
//}
