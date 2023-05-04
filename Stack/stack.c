#include<stdio.h>

#define size 5
int stack[size];
int top=-1;

void push();
void pop();
void print();

int main(int argc,char *argv[])
{

    int choice;
    
    while(1){
        printf("1.Push data\n2.Pop data\n3.Print data\n4.Quit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        if(choice==1){
            push();
        }else if(choice==2){
            pop();
        }else if(choice==3){
            print();
        }else if(choice==4){
            break;
        }
    }

    return 0;
}

void push(){
    int data;
    printf("Enter data in stack:");
    scanf("%d",&data);

    if(top==size-1) printf("Overflow\n");
    else{
        top++;
        stack[top]=data;
    }
}

void pop(){
    if(top==-1) printf("Underflow\n");
    else{
        top--;
    }
}

void print(){
    int i;
    for(i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}