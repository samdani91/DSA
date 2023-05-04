#include<stdio.h>

#define size 5
int queue[size];
int front=-1,rear=-1;

void print_queue();
void enqueue(int data);
void dequeue();

int main(int argc,char *argv[])
{

    for(int i=0;i<size;i++) enqueue(i+1);
    print_queue();

    dequeue();
    print_queue();

    enqueue(1);//check drawback

    

    return 0;
}

void print_queue(){
    if(front==-1 && rear==-1) printf("Queue is empty\n");
    else{
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }

    
}

void enqueue(int data){
    if(rear==size-1) printf("Overflow\n");
    else if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=data;
        
    }else{
        rear++;
        queue[rear]=data;
    }
}

void dequeue(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
    }else if(front==rear){
        front=rear=-1;
    }else{
        front++;
    }
}

void dequeue(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
    }else if(front==rear){
        front=rear=-1;
    }else{
        front++;
    }
}