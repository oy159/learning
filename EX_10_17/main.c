#include <stdio.h>
#include "User/Inc/node.h"
#include "User/Inc/seqlist.h"
#include "User/Inc/tree.h"
#include "sort.h"

void OddEven(int A[], int len) {
    int B[len];
    for (int i = 0, j = 0; i + j < len;) {
        if (A[i + j] % 2 == 1) {
            B[i] = A[i + j];
            i++;
        } else {
            B[len - 1 - j] = A[i + j];
            j++;
        }
    }
    for (int i = 0; i < len; ++i) {
        A[i] = B[i];
    }
}


int main() {
    /*链表删除*/
//    Node *p;
//    int x[5]={1,4,3,2,6};
//    p=CreateNode(x,5);
//    p=Deletexy(p,4,6);
//    DisplayAllNode(p);

    /*顺序表删除*/
//    seqList list;
//    int x[5] = {1, 4, 3, 2, 6};
//    initSeqlist(&list, x, 5);
//    list = DeleteSeqxy(&list, 2, 3);
//    DisplayAllSeq(list);

    /*奇偶分离*/
//    int a[10] = {1, 3, 2, 5, 7, 8, 6, 54, 8, 9};
//    OddEven(a, 10);
//    for (int i = 0; i < 10; ++i) {
//        printf("%d ", a[i]);
//    }
    /*判断循环单链表是否递增有序*/
//    Node *p;
//    int x[5]={7,2,3,4,6};
//    p=CreateCirNode(x,5);
//    printf("%d",NodeCirIncreasing(p));
//    return 0;


    /*将单链表扩展2倍，假设线性表为(a1, a2, ..., an)，扩展后为(a1, a1, a2, a2, ..., an, an)*/
//    Node *p;
//    int x[5]={7,2,3,4,6};
//    p=CreateNode(x,5);
//    p=NodeSameExtension(p);
//    DisplayAllNode(p);
//    return 0;

    /*循环队列*/
//    Queue *queue=(Queue *)malloc(sizeof(Queue));
//    int x[4];
//    InitQueue(queue);
//    EnCirQueue(queue, 1);
//    EnCirQueue(queue, 2);
//    EnCirQueue(queue, 3);
//    DisplayAllCirQueue(*queue);
//    DeCirQueue(queue, &x[0]);
//    DeCirQueue(queue, &x[1]);
//    DisplayAllCirQueue(*queue);
//    EnCirQueue(queue, 4);
//    EnCirQueue(queue, 5);
//    EnCirQueue(queue, 6);
//    DisplayAllCirQueue(*queue);
//    EnCirQueue(queue, 7);
//    return 0;

    /*顺序栈*/
//    Stack *s = (Stack *) malloc(sizeof(Stack));
//    int x[4];
//    InitSeqStack(s);
//    SeqPush(s, 1);
//    SeqPush(s, 2);
//    SeqPush(s, 3);
//    DisplayAllSeqStack(*s);
//    SeqPop(s, &x[0]);
//    SeqPop(s, &x[1]);
//    DisplayAllSeqStack(*s);
//    SeqPush(s, 4);
//    SeqPush(s, 5);
//    SeqPush(s, 6);
//    DisplayAllSeqStack(*s);
//    SeqPush(s, 7);


    /*链队列：约瑟夫问题*/
//    LinkQueue *q;
//    int n,k, j = 0;
//    int x;
//    q=InitLinkQueue();
//    scanf("%d%d",&n,&k);
//    for (int i = 0; i < n; ++i) {
//        EnLinkQueue(q,i+1);
//    }
//    while (q->front->next->next!=NULL){
//        j++;
//        if(j!=k){
//            DeLinkQueue(q,&x);
//            EnLinkQueue(q,x);
//        }else{
//            j=0;
//            DeLinkQueue(q,&x);
//            printf("%d\t",x);
//        }
//    }
//    printf("\n");
//    printf("%d",q->front->next->data);
//    return 0;
//    "ABD###CE##F##"


    /*二叉树*/
//    TreeRoot *t;
//    int max=0;
//    int x=0;
//    int n;
//    t=TreeRootInit();
//    char *s;
//    s=(char *)malloc(20*sizeof(char));
//    printf("\t\t\t\t\t\t实验三：二叉树\n");
//    printf("*********************请输入前序二叉树以 # 为断点********************\n");
//    printf("功能列表：\n");
//    printf("1.输入前序，构建二叉树\n");
//    printf("2.前序打印\n");
//    printf("3.中序打印\n");
//    printf("4.后序打印\n");
//    printf("5.层次遍历打印\n");
//    printf("6.结点总数打印\n");
//    printf("7.二叉树深度打印\n");
//    printf("8.输出度为1结点个数打印\n");
//    printf("****************************************************************\n");
//    while (1) {
//        max=0;
//        printf("功能选择：");
//        fflush(stdout);
//        scanf("%d", &n);
//        getchar();
//        fflush(stdin);
//        //printf("\n");
//        switch (n) {
//            case 1:
//                printf("请输入前序：");
//                fflush(stdout);
//                scanf("%s", s);
//                getchar();
//                fflush(stdin);
//                CreateTree(&t->root, &s);
//
//                printf("构建完毕\n");
//                printf("\n");
//                break;
//
//            case 2:
//                printf("前序序列：");
//                PrePrint(t->root);
//                printf("\n\n");
//                break;
//
//            case 3:
//                printf("中序序列：");
//                MidPrint(t->root);
//                printf("\n\n");
//                break;
//
//            case 4:
//                printf("后序序列：");
//                PostPrint(t->root);
//                printf("\n\n");
//                break;
//
//            case 5:
//                printf("层次遍历序列：");
//                LevelPrint(t->root);
//                printf("\n\n");
//                break;
//
//            case 6:
//                printf("结点总数：");
//                printf("%d\n\n", PointSum(t->root, 0));
//                break;
//
//            case 7:
//                printf("二叉树深度：");
//                DepthSum(t->root, 0, &max);
//                printf("%d\n\n", max);
//                break;
//
//            case 8:
//                printf("输出度为1结点个数：");
//                SinglePointSum(t->root, &x);
//                printf("%d\n\n", x);
//                break;
//
//            default:
//                printf("输入无效，请重新输入\n\n");
//                break;
//
//        }
//    }
//test


    /*sort*/
    Node *p;
    int x[10]={51,38,79,22,91,105,33,52,16,112};
    p=CreateNode(x,10);
    InsertSort(p);

}