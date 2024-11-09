#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5

int front = -1, rear = -1;
int arr[SIZE];

// Function to check if the queue is full
bool isfull() {
    if ((rear + 1) % SIZE == front) {  // Check for wraparound
        return true;
    }
    return false;
}

// Function to check if the queue is empty
bool isempty() {
    if (front == -1) {
        return true;
    }
    return false;
}

// Enqueue operation
void enqueue(int x) {
    if (isfull()) {
        printf("Queue is full\n");
    } else {
        if (isempty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;  // Circular increment
        }
        arr[rear] = x;
        printf("Inserted %d\n", x);
    }
}

// Dequeue operation
void dequeue() {
    if (isempty()) {
        printf("Queue is empty\n");
    } else {
        printf("Removed %d\n", arr[front]);
        if (front == rear) {  // Only one element in the queue
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;  // Circular increment
        }
    }
}

// Display the elements of the queue
void display() {
    if (isempty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        int i = front;
        while (i != rear) {
            printf("%d ", arr[i]);
            i = (i + 1) % SIZE;  // Circular increment
        }
        printf("%d\n", arr[rear]);  // Print the last element
    }
}

// Main function to test the queue operations
int main() {
    // Enqueue some elements
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);  // This should fill the queue

    // Try to enqueue when the queue is full
    enqueue(60);

    // Display the queue
    display();

    // Dequeue some elements
    dequeue();
    dequeue();

    // Display the queue again
    display();

    // Dequeue remaining elements
    dequeue();
    dequeue();
    dequeue();  // This will empty the queue

    // Display the queue after all elements are dequeued
    display();

    return 0;
}
