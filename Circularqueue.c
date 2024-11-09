#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert(void);
int delete_element(void);
int peek(void);
void display(void);

int main() {
    int option, val;
    do {
        printf("\n1. INSERT AN ELEMENT 2. DELETE AN ELEMENT 3. PEEK 4. DISPLAY 5. EXIT\n");
        printf("\nEnter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                insert();
                break;
            case 2:
                val = delete_element();
                if (val != -1)
                    printf("\nDeleted element is %d\n", val);
                break;
            case 3:
                val = peek();
                if (val != -1)
                    printf("\nThe first value in the queue is %d\n", val);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid option, please try again.\n");
        }
    } while (option != 5);

    return 0;
}

void insert() {
    int num;
    printf("\nEnter an element to insert: ");
    scanf("%d", &num);

    if ((rear + 1) % MAX == front) {
        printf("\nQueue Overflow: The queue is full.\n");
    } else {
        if (front == -1) { // First element to insert
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        queue[rear] = num;
        printf("\nElement %d inserted.\n", num);
    }
}

int delete_element() {
    if (front == -1) {
        printf("\nQueue Underflow: The queue is empty.\n");
        return -1;
    }

    int val = queue[front];
    if (front == rear) { // Only one element
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    return val;
}

int peek() {
    if (front == -1) {
        printf("\nQueue is empty.\n");
        return -1;
    }
    return queue[front];
}

void display() {
    printf("\nQueue elements: ");
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d ", queue[rear]);
        printf("\n");
    }
}
