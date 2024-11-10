#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void display();
void insert_begin();
void delete_end();
void delete_begin();
void delete_pos();

struct node *head = NULL;

// Function to display elements of the list
void display() {
    printf("Elements are ............\n");
    struct node *ptr;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    ptr = head;
    while (ptr != NULL) {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
}

// Function to insert a node at the beginning of the list
void insert_begin() {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter the value to be inserted: ");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

// Function to delete a node from the beginning of the list
void delete_begin() {
    struct node *ptr;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    } else {
        ptr = head;
        head = head->next;
        printf("The element deleted from the list: %d\n", ptr->data);
        free(ptr);
    }
}

// Function to delete a node from the end of the list
void delete_end() {
    struct node *ptr, *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    } else {
        ptr = head;
        while (ptr->next != NULL) {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        printf("The element deleted: %d\n", ptr->data);
        free(ptr);
    }
}

// Function to delete a node at a specific position in the list
void delete_pos() {
    int i, pos;
    struct node *ptr, *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter the position to be deleted: ");
    scanf("%d", &pos);

    if (pos == 0) {
        ptr = head;
        head = head->next;
        printf("The item deleted from the list: %d\n", ptr->data);
        free(ptr);
    } else {
        ptr = head;
        for (i = 0; i < pos; i++) {
            temp = ptr;
            ptr = ptr->next;
            if (ptr == NULL) {
                printf("\nPosition not found\n");
                return;
            }
        }
        temp->next = ptr->next;
        printf("The value deleted is: %d\n", ptr->data);
        free(ptr);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Insert at the beginning\n");
        printf("2. Delete at the beginning\n");
        printf("3. Delete at the end\n");
        printf("4. Delete at any position\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_begin();
                break;
            case 2:
                delete_begin();
                break;
            case 3:
                delete_end();
                break;
            case 4:
                delete_pos();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Enter the correct choice\n");
                break;
        }
    }
}

