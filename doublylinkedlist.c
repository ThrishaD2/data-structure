#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
int data;
struct Node*prev;
struct Node*next;
}Node;
Node*createNode(int data){
Node*newNode=(Node*)malloc(sizeof(Node));
if(!newNode){
    printf("Memory allocation failed\n");
    exit(1);
}
newNode->data=data;
newNode->prev=NULL;
newNode->next=NULL;
return newNode;
}
Node*createList(){
return NULL;
}
void insertAtBeginning(Node**head,int data){
Node*newNode=createNode(data);
if(*head!=NULL){
    newNode->next=*head;
    (*head)->prev=newNode;
}
*head=newNode;
}
void insertAtPosition(Node**head,int data,int position){
Node*newNode=createNode(data);
if(position==1){
    insertAtBeginning(head,data);
    return;
}
Node*temp=*head;
for(int i=1; i<position-1; i++){
    if(temp==NULL){
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }
    temp=temp->next;
}
if(temp==NULL){
    printf("position out of bounds");
    free(newNode);
    return;
}
newNode->next=temp->next;
newNode->prev=temp;
if(temp->next!=NULL){
    temp->next->prev=newNode;
}
temp->next=newNode;
}
void insertAtEnd(Node**head,int data){
Node*newNode=createNode(data);
if(*head==NULL){
    *head=newNode;
    return;
}
Node*temp=*head;
while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=newNode;
newNode->prev=temp;
}
void displayList(Node*head){
if(head==NULL){
    printf("The list is empty");
    return;
}
Node*temp=head;
printf("List contents:");
while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
}
printf("\n");
}
int main(){
   struct Node* head = createList();
   int choice,data,position;
while(1){
    printf("\n1.Insert at Beginning:");
    printf("\n2.Insert at specific position:");
    printf("\n3.Insert at end :");
    printf("\n4.display:");
    printf("\n5.Exit:");
    printf("\nEnter your choice:\n");
    scanf("%d",&choice);
    switch(choice){
case 1:
    printf("enter a value to insert at beginning");
    scanf("%d",&data);
    insertAtBeginning(&head,data);
    break;
case 2:
    printf("enter a value to insert at specific position");
    scanf("%d",&data);
    printf("enter the position");
    scanf("%d",&position);
    insertAtPosition(&head, data, position);
    break;
case 3:
    printf("enter a value to insert at end");
    scanf("%d",&data);
    insertAtEnd(&head, data);
    break;
case 4:
    printf("display the contents");
    displayList(head);
    break;
case 5:
    exit(0);
    break;
default:
    printf("/n INVALID CHOICE\n");
    }
    }
    return 0;
}

\\\\\\output\\\\\\
1.Insert at Beginning:
2.Insert at specific position:
3.Insert at end :
4.display:
5.Exit:
Enter your choice:
1
enter a value to insert at beginning10

1.Insert at Beginning:
2.Insert at specific position:
3.Insert at end :
4.display:
5.Exit:
Enter your choice:
1
enter a value to insert at beginning20

1.Insert at Beginning:
2.Insert at specific position:
3.Insert at end :
4.display:
5.Exit:
Enter your choice:
1
enter a value to insert at beginning30

1.Insert at Beginning:
2.Insert at specific position:
3.Insert at end :
4.display:
5.Exit:
Enter your choice:
2
enter a value to insert at specific position1
enter the position2

1.Insert at Beginning:
2.Insert at specific position:
3.Insert at end :
4.display:
5.Exit:
Enter your choice:
3
enter a value to insert at end29

1.Insert at Beginning:
2.Insert at specific position:
3.Insert at end :
4.display:
5.Exit:
Enter your choice:
4
display the contentsList contents:30 1 20 10 29

1.Insert at Beginning:
2.Insert at specific position:
3.Insert at end :
4.display:
5.Exit:
Enter your choice:
5

Process returned 0 (0x0)   execution time : 35.087 s
Press any key to continue.


