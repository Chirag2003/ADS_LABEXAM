#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 15

typedef struct
{
    int *arr;
    int front, rear;
    int size;
} CircularQueue;
typedef struct
{
    int *arr;
    int front, rear;
    int size;
} Queue;

typedef struct
{
    int *arr;
    int top;
} Stack;

Stack *createStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->arr = (int *)malloc(MAX_SIZE * sizeof(int));
    s->top = -1;
    return s;
}

CircularQueue *createQueue()
{
    CircularQueue *Q = (CircularQueue *)malloc(sizeof(CircularQueue));
    Q->arr = (int *)malloc(MAX_SIZE * sizeof(int));
    Q->front = -1;
    Q->rear = -1;
    Q->size = 0;
    return  Q;
}
Queue *createqueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->arr = (int *)malloc(MAX_SIZE * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    return q;
}
int isFull(CircularQueue *q)
{
    return (q->front == 0 && q->rear == MAX_SIZE - 1) || q->front == q->rear + 1;
}

int isEmpty(CircularQueue *q)
{
    return q->front == -1;
}

int isFull1(Queue *q)
{
    return q->size == MAX_SIZE;
}

int isEmpty1(Queue *q)
{
    return q->front == -1;
}

void enqueue(CircularQueue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->arr[q->rear] = data;
    q->size++;
}

int dequeue(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->arr[q->front];
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    q->size--;
    return data;
}

void printQueue(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    int i;
    for (i = q->front; i != q->rear; i = (i + 1) % MAX_SIZE)
    {
        printf("%d ", q->arr[i]);
    }
    printf("%d", q->arr[i]);
}

void enqueue1(Queue *q, int data)
{
    if (isFull1(q))
    {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->arr[q->rear] = data;
    q->size++;
}

int dequeue1(Queue *q)
{
    if (isEmpty1(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->arr[q->front];
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    q->size--;
    return data;
}

void push(Stack *s, int data)
{
    if (s->top == MAX_SIZE - 1)
    {
        printf("Stack is full\n");
        return;
    }
    s->arr[++s->top] = data;
}

int pop(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->top--];
}

void reverseStack(Stack *s)
{
    Queue *q = createqueue();
    while (s->top != -1)
    {
        enqueue1(q, pop(s));
    }
    while (!isEmpty1(q))
    {
        push(s, dequeue1(q));
    }
}

void printStack(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are: ");
    int i;
    for (i = 0; i <= s->top; i++)
    {
        printf("%d ", s->arr[i]);
    }
}

int main()
{
    int choice, Choice;
    int data, n, i, num;
    int Exit = 1;
    int exit = 1;

    CircularQueue *Q = createQueue();
    // Queue *q=createqueue();
    Stack *s = createStack();
    while (Exit)
    {
        printf("\n1.Queue Operations\n2.Reversing stack usong queue\n3.Exit\n");
        scanf("%d", &Choice);

        switch (Choice)
        {

        case 1:
            while (exit)
            {
                printf("\n\n**Queue Operations**\n1.Enqueue\n2.Dequeue\n3.Print queue\n4.Exit\n");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    printf("Enter the element");
                    scanf("%d", &data);
                    enqueue(Q, data);
                    printQueue(Q);
                    break;
                case 2:
                    printf("\nDequeue element: %d\n", dequeue(Q));
                    printQueue(Q);

                    break;
                case 3:
                    printQueue(Q);
                    break;
                case 4:
                    exit--;
                    break;
                default:
                    break;
                }
            }

            break;
        case 2:
            printf("\n\nHow many elemets you want to push in stack\n\n");
            scanf("%d", &n);
            for (i = 1; i <= n; i++)
            {
                printf("Enter the element :\n");
                scanf("%d", &num);
                push(s, num);
            }
            printStack(s);
            printf("\nReverse stack\n\n");
            reverseStack(s);
            printStack(s);

            break;
        case 3:
            Exit--;
            break;
        }
    }

    return 0;
}