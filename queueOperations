#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define size 5
int front=-1, rear=-1;
int arr[size];
bool isfull(){
if(rear==size-1){
return true;
}
return false;
}
bool isempty(){
if(rear==-1&&front==-1){
return true;
}
return false;
}
void enqueue(int x){
if (isfull()){
printf("queue is full\n");
}
else if(isempty()){
rear=front=0;
arr[rear]=x;
}
else{
rear+=1
arr[rear]=x;
}
}
void dequeue(){
if (isempty()){
printf("queue is empty\n");
}
else if(rear==front){
rear=front=-1;
}
else{
front+=1;
}
}
void display(){
if(isempty()){
printf("queue is empty\n");
}
else{
for(int i=front;i<=rear;i++){
pritnf("%d\n",arr[i]);
}
}
}
void main(){
for(int i=0;i<size;i++){
scanf("%d",&arr[i]);
enqueue(arr[i]);
}
display();
enqueue(90);
dequeue();
dequeue();
display();
dequeue();
dequeue();
display();
dequeue();
display();
}
