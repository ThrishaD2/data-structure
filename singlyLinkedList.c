#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};


void display();
void insert_begin();
void insert_end();
void insert_pos();
struct node* head = NULL;

void display() {
    printf("Elements are...\n");
    struct node* ptr=head;
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        ptr=head;
        while(ptr!=NULL){
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
        }
    }

void insert_begin() {
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter a value to be inserted: ");
    scanf("%d", &temp->data);  // Use &temp->data
    temp->next = NULL;
    if(head==NULL)
        head=temp;
    else{
        temp->next=head;
        head=temp;
    }

}

void insert_end() {
    struct node* temp,*ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter a value to be inserted: ");
    scanf("%d", &temp->data);  // Use &temp->data
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
void insert_pos() {
    int pos, i;
    struct node*temp,*ptr;
    printf("enter the position:\n");
    scanf("%d",&pos);
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter a value to be inserted\n ");
    scanf("%d", &temp->data);
    temp->next=NULL;
    if(pos==0){
        temp->next=head;
        head=temp;
    }
    else{
        for(i=0,ptr=head;i<pos-1;i++){
            ptr=ptr->next;
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
}

void main() {
    int choice;
    while (1) {
        printf("\n1. INSERT AT BEGINNING\n2. INSERT AT END\n3. INSERT AT ANY POSITION\n4. DISPLAY\n5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);  // Corrected scanf

        switch (choice) {
            case 1:
                insert_begin();
                break;
            case 2:
                insert_end();
                break;
            case 3:
                insert_pos();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Enter a valid option:\n");
        }
    }
}
