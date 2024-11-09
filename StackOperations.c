#include <stdio.h>
#include <stdlib.h>  // For exit()
#define SIZE 10

void push(int value);
void pop();
void display();

int stack[SIZE], top = -1;

void main() {
    int value, choice;
    
    // Clear screen using system("cls") for Windows
    system("cls");

    while (1) {
        printf("\n\n***** MENU *****\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);  // Exit the program
            default:
                printf("\nWrong selection! Try again.\n");
        }
    }
}

void push(int value) {
    if (top == SIZE - 1) {
        printf("\nStack is full! Insertion is not possible.\n");
    } else {
        top++;  // Increment top before inserting
        stack[top] = value;
        printf("\nInsertion successful!\n");
    }
}

void pop() {
    if (top == -1) {
        printf("\nStack is empty! Deletion is not possible.\n");
    } else {
        printf("\nDeleted: %d\n", stack[top]);
        top--;  // Decrease top after popping
    }
}

void display() {
    if (top == -1) {
        printf("\nStack is empty!\n");
    } else {
        printf("\nStack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
