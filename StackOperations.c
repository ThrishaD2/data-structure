#include<stdio.h>
#include<conio.h>
#define SIZE 10
void push(int);
void pop();
void display();
int stack[SIZE],top=-1;
void main()
{
int value,choice;
clscr();
while(1){
printf("\n\n*****MENU*****\n");
printf("1.push\n2.pop\n3.display\n4.exit");
printf("%d",&choice);
switch(choice){
case 1:
printf("enter the value to be inserted");
scanf("%d",&value);
push(value);
break;
case 2:
poop();
break;
case 3:
display();
break;
case 4:
exit(0);
default:printf("\n wrong selection!! try again!!");
}
}
}
void push(int value){
if(top==SIZE-1)
printf("\n stack is full!!Insertion is not possible!!");
else{
top++
stack[top]=value;
printf("\nInsertion success!!");
}
}
void pop(){
if(top==-1)
printf("\nStack is empty!! Deletion is not possible!!");
else{
printf("\n Deleted :%d",stack[top]);
top--;
}
}
void display(){
if(top==-1)
printf("\n Stack is empty!!!");
else{
int i:
printf("\n Stack elements are :\n");
for(i=top:i>=0;i--)
printf("%d\n",stack[i]);
}
}
