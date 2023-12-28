#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
struct Queue {
    int front, rear;
    int array[MAX_SIZE];
};
void initializeQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}
int isEmpty(struct Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}
int isFull(struct Queue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}
void enqueue(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);           
        return;
    } else if (isEmpty(queue)) {
        queue->front = 0;  
    }
    queue->rear++;
    queue->array[queue->rear] = value;
    printf("%d enqueued to the queue.\n", value);
}
void dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    } else if (queue->front == queue->rear) {
        printf("%d dequeued from the queue.\n", queue->array[queue->front]);
        initializeQueue(queue);
    } else {
        printf("%d dequeued from the queue.\n", queue->array[queue->front]);
        queue->front++;
    }
}
void displayQueue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Elements in the queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}
int main() {
    struct Queue myQueue;
    initializeQueue(&myQueue);
    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);
    displayQueue(&myQueue);
    dequeue(&myQueue);
    displayQueue(&myQueue);
    enqueue(&myQueue, 40);
    displayQueue(&myQueue);
    return 0;
}