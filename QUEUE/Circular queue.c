// Implementation of circular

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5

int circularQueue[MAX_SIZE];
int front = -1, rear = -1;

bool isFull() 
{
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == front - 1))
        return true;
    return false;
}

bool isEmpty()
{
    if (front == -1)
        return true;
    return false;
}

void enqueue(int data)
{
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else if (rear == MAX_SIZE - 1)
        rear = 0;
    else
        rear++;

    circularQueue[rear] = data;
    printf("%d enqueued to the queue.\n", data);
}

int dequeue()
{
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int data = circularQueue[front];
    circularQueue[front] = -1;

    if (front == rear)
        front = rear = -1;
    else if (front == MAX_SIZE - 1)
        front = 0;
    else
        front++;

    return data;
}

void display() 
{
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    if (front <= rear) {
        while (i <= rear)
            printf("%d ", circularQueue[i++]);
    } else {
        while (i < MAX_SIZE)
            printf("%d ", circularQueue[i++]);
        i = 0;
        while (i <= rear)
            printf("%d ", circularQueue[i++]);
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    enqueue(60);
    enqueue(70);

    display();

    return 0;
}