#include <stdio.h>
#include <stdlib.h>
struct Expense 
{
    int amount;
    struct Expense* next;
    struct Expense* prev;
};
struct Queue 
{
    struct Expense* front;
    struct Expense* rear;
};
void initializeQueue(struct Queue* q) 
{
    q->front = q->rear = NULL;
}
void enqueue(struct Queue* q, int amount) 
{
    struct Expense* newExpense = (struct Expense*)malloc(sizeof(struct Expense));
    newExpense->amount = amount;
    newExpense->next = NULL;
    newExpense->prev = NULL;
    if (q->rear == NULL) 
    {
        q->front = q->rear = newExpense;
    } 
    else 
    {
        q->rear->next = newExpense;
        newExpense->prev = q->rear;
        q->rear = newExpense;
    }
}
void dequeue(struct Queue* q) 
{
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Expense* temp = q->front;
    q->front = temp->next;
    if (q->front == NULL) {
        q->rear = NULL;
    } else {
        q->front->prev = NULL;
    }
    free(temp);
}

void displayQueue(struct Queue* q) 
{
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    struct Expense* current = q->front;
    while (current != NULL) {
        printf("%d ", current->amount);
        current = current->next;
    }
    printf("\n");
}

struct CircularQueue 
{
    struct Expense* front;
    struct Expense* rear;
};

void initializeCircularQueue(struct CircularQueue* cq) {
    cq->front = cq->rear = NULL;
}
void enqueueCircular(struct CircularQueue* cq, int amount) {
    struct Expense* newExpense = (struct Expense*)malloc(sizeof(struct Expense));
    newExpense->amount = amount;
    newExpense->next = cq->front;
    newExpense->prev = NULL;

    if (cq->front == NULL) {
        cq->front = cq->rear = newExpense;
    } else {
        cq->rear->next = newExpense;
        newExpense->prev = cq->rear;
        cq->rear = newExpense;
    }

    cq->front->prev = cq->rear;
}

void dequeueCircular(struct CircularQueue* cq) {
    if (cq->front == NULL) {
        printf("Circular Queue is empty.\n");
        return;
    }

    struct Expense* temp = cq->front;
    cq->front = temp->next;

    if (cq->front == NULL) {
        cq->rear = NULL;
    } else {
        cq->front->prev = cq->rear;
        cq->rear->next = cq->front;
    }

    free(temp);
}

void displayCircularQueue(struct CircularQueue* cq) {
    if (cq->front == NULL) {
        printf("Circular Queue is empty.\n");
        return;
    }

    printf("Circular Queue: ");
    struct Expense* current = cq->front;
    do {
        printf("%d ", current->amount);
        current = current->next;
    } while (current != cq->front);
    printf("\n");
}

struct Deque {
    struct Expense* front;
    struct Expense* rear;
};

void initializeDeque(struct Deque* dq) {
    dq->front = dq->rear = NULL;
}

void enqueueFront(struct Deque* dq, int amount) {
    struct Expense* newExpense = (struct Expense*)malloc(sizeof(struct Expense));
    newExpense->amount = amount;
    newExpense->next = dq->front;
    newExpense->prev = NULL;

    if (dq->front == NULL) {
        dq->front = dq->rear = newExpense;
    } else {
        dq->front->prev = newExpense;
        dq->front = newExpense;
    }
}

void enqueueRear(struct Deque* dq, int amount) {
    struct Expense* newExpense = (struct Expense*)malloc(sizeof(struct Expense));
    newExpense->amount = amount;
    newExpense->next = NULL;
    newExpense->prev = dq->rear;

    if (dq->rear == NULL) {
        dq->front = dq->rear = newExpense;
    } else {
        dq->rear->next = newExpense;
        dq->rear = newExpense;
    }
}

void dequeueFront(struct Deque* dq) {
    if (dq->front == NULL) {
        printf("Deque is empty.\n");
        return;
    }

    struct Expense* temp = dq->front;
    dq->front = temp->next;

    if (dq->front == NULL) {
        dq->rear = NULL;
    } else {
        dq->front->prev = NULL;
    }

    free(temp);
}

void dequeueRear(struct Deque* dq) {
    if (dq->rear == NULL) {
        printf("Deque is empty.\n");
        return;
    }

    struct Expense* temp = dq->rear;
    dq->rear = temp->prev;

    if (dq->rear == NULL) {
        dq->front = NULL;
    } else {
        dq->rear->next = NULL;
    }

    free(temp);
}

void displayDeque(struct Deque* dq) {
    if (dq->front == NULL) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque: ");
    struct Expense* current = dq->front;
    while (current != NULL) {
        printf("%d ", current->amount);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue regularQueue;
    initializeQueue(&regularQueue);

    struct CircularQueue circularQueue;
    initializeCircularQueue(&circularQueue);

    struct Deque deque;
    initializeDeque(&deque);

    int mainChoice, subChoice, amount;

    do {
        printf("\nMain Menu:\n");
        printf("1. Regular Queue\n");
        printf("2. Circular Queue\n");
        printf("3. Double-Ended Queue (Deque)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &mainChoice);

        switch (mainChoice) {
            case 1:
                do {
                    printf("\nRegular Queue Menu:\n");
                    printf("1. Enqueue\n");
                    printf("2. Dequeue\n");
                    printf("3. Display\n");
                    printf("0. Back to Main Menu\n");

                    printf("Enter your choice: ");
                    scanf("%d", &subChoice);

                    switch (subChoice) {
                        case 1:
                            printf("Enter amount: ");
                            scanf("%d", &amount);
                            enqueue(&regularQueue, amount);
                            break;
                        case 2:
                            dequeue(&regularQueue);
                            break;
                        case 3:
                            displayQueue(&regularQueue);
                            break;
                        case 0:
                            break;
                        default:
                            printf("Invalid choice. Please enter a valid option.\n");
                    }
                } while (subChoice != 0);
                break;

            case 2:
                do {
                    printf("\nCircular Queue Menu:\n");
                    printf("1. Enqueue\n");
                    printf("2. Dequeue\n");
                    printf("3. Display\n");
                    printf("0. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &subChoice);
                    switch (subChoice) {
                        case 1:
                            printf("Enter amount: ");
                            scanf("%d", &amount);
                            enqueueCircular(&circularQueue, amount);
                            break;
                        case 2:
                            dequeueCircular(&circularQueue);
                            break;
                        case 3:
                            displayCircularQueue(&circularQueue);
                            break;
                        case 0:
                            break;
                        default:
                            printf("Invalid choice. Please enter a valid option.\n");
                    }
                } while (subChoice != 0);
                break;
            case 3:
                do {
                    printf("\nDouble-Ended Queue (Deque) Menu:\n");
                    printf("1. Enqueue Front\n");
                    printf("2. Enqueue Rear\n");
                    printf("3. Dequeue Front\n");
                    printf("4. Dequeue Rear\n");
                    printf("5. Display\n");
                    printf("0. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &subChoice);
                    switch (subChoice) {
                        case 1:
                            printf("Enter amount: ");
                            scanf("%d", &amount);
                            enqueueFront(&deque, amount);
                            break;
                        case 2:
                            printf("Enter amount: ");
                            scanf("%d", &amount);
                            enqueueRear(&deque, amount);
                            break;
                        case 3:
                            dequeueFront(&deque);
                            break;
                        case 4:
                            dequeueRear(&deque);
                            break;
                        case 5:
                            displayDeque(&deque);
                            break;
                        case 0:
                            break;
                        default:
                            printf("Invalid choice. Please enter a valid option.\n");
                    }
                } while (subChoice != 0);
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (mainChoice != 0);
    return 0;
}
