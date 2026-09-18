#include <stdbool.h>
#include <stdlib.h>

typedef struct QueueNode {
    int value;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

typedef struct {
    Queue q1;
    Queue q2;
} MyStack;

static void enqueue(Queue* queue, int value)
{
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->value = value;
    node->next = NULL;

    if (queue->rear == NULL)
    {
        queue->front = node;
        queue->rear = node;
    }
    else
    {
        queue->rear->next = node;
        queue->rear = node;
    }
}

static int dequeue(Queue* queue)
{
    QueueNode* node = queue->front;
    int value = node->value;

    queue->front = node->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    free(node);
    return value;
}

MyStack* myStackCreate(void)
{
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q1.front = NULL;
    stack->q1.rear = NULL;
    stack->q2.front = NULL;
    stack->q2.rear = NULL;
    return stack;
}

void myStackPush(MyStack* obj, int x)
{
    enqueue(&obj->q2, x);

    while (obj->q1.front != NULL)
    {
        enqueue(&obj->q2, dequeue(&obj->q1));
    }

    Queue temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

int myStackPop(MyStack* obj)
{
    return dequeue(&obj->q1);
}

int myStackTop(MyStack* obj)
{
    return obj->q1.front->value;
}

bool myStackEmpty(MyStack* obj)
{
    return obj->q1.front == NULL;
}

void myStackFree(MyStack* obj)
{
    while (obj->q1.front != NULL)
    {
        dequeue(&obj->q1);
    }

    while (obj->q2.front != NULL)
    {
        dequeue(&obj->q2);
    }

    free(obj);
}
