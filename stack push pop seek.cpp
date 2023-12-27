#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int data) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow.\n");
    } else {
        top++;
        stack[top] = data;
    }
}

void pop() {
    if (top <= -1) {
        printf("Stack Underflow.\n");
    } else {
        printf("The popped element is %d.\n", stack[top]);
        top--;
    }
}

int peek() {
    if (top >= 0) {
        return stack[top];
    } else {
        printf("Stack is empty.\n");
        return -1;
    }
}

int main() {
    int choice, data;

    while (1) {
        printf("1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to push: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            if (peek() != -1) {
                printf("The top element is %d.\n", peek());
            } else {
                printf("Stack is empty.\n");
            }
            break;
        case 4:
            return 0;
        }
    }

    return 0;
}