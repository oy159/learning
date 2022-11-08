#include "../Inc/seqlist.h"

void initSeqlist(seqList *list, const int *x, int len) {
    int i;
    for (i = 0; i < len; ++i) {
        list->data[i] = *(x + i);
    }
    list->length = len;
}


void insertSeqlist(seqList *list, int x, int i) {
    int temp = list->data[i];
    list->data[i] = x;
    for (int j = list->length - 1; j > i; ++j) {
        list->data[j + 1] = list->data[j];
    }
    list->data[i + 1] = temp;
    list->length++;
}


void DisplayAllSeq(seqList list) {
    for (int i = 0; i < list.length; ++i) {
        printf("%d\t", list.data[i]);
    }
}


seqList DeleteSeqxy(seqList *list, int x, int y) {
    seqList p;
    p.length = 0;
    for (int i = 0; i < list->length; ++i) {
        if (list->data[i] >= x && list->data[i] <= y) {
            continue;
        } else {
            p.data[p.length++] = list->data[i];
        }
    }
    return p;
}


void InitQueue(Queue *queue){
    queue->front=queue->rear=-1;
}


int EmptyCirQueue(Queue queue){
    if(queue.front==queue.rear)
        return 1;
    return 0;
}


int FullCirQueue(Queue queue){
    if ((queue.rear +1 )% QUEUEMAXLENGTH == queue.front)
        return 1;
    return 0;
}

//入队
void EnCirQueue(Queue *queue, int x){
    if ((queue->rear +1 )% QUEUEMAXLENGTH == queue->front)
        printf("已溢出\t");
    else{
        queue->rear=(queue->rear+1)%QUEUEMAXLENGTH;
        queue->data[queue->rear]=x;
    }
}

//出队
void DeCirQueue(Queue *queue, int *x){
    if(queue->rear==queue->front){
        printf("队列空");
    } else{
        queue->front=(queue->front+1)%QUEUEMAXLENGTH;
        *x=queue->data[queue->front];
    }
}

void DisplayAllCirQueue(Queue queue){
    while(queue.rear!=queue.front){
        queue.front=(queue.front+1)%QUEUEMAXLENGTH;
        printf("%d\t",queue.data[queue.front]);
    }
    printf("\n");
}

void InitSeqStack(Stack* s){
    s->top=-1;
}

void SeqPush(Stack* s,int x){
    if (s->top==STACKMAXLENGTH-1){
        printf("已溢出\n");
    }else{
        s->top++;
        s->data[s->top]=x;
    }
}

void SeqPop(Stack* s,int *x){
    if (s->top==-1){
        printf("栈空\n");
    }else{
        *x=s->data[s->top];
        s->top--;
    }
}

void DisplayAllSeqStack(Stack s){
    while (s.top!=-1){
        printf("%d\t",s.data[s.top--]);
    }
    printf("\n");
}
