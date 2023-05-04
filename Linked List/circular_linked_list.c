#include<stdio.h>
#include<stdlib.h>

void printList();
void len();
void creating_list(int data);
void insertbeg();
void insertend();
void insert_after_a_given_pos();
void deletebeg();
void deleteend();
void delete_specific_pos();


struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;
struct node *tail=NULL;
struct node *temp=NULL;

int length;

int main(int argc,char *argv[])
{

    for(int i=1;i<=9;i++) creating_list(i);
    len();
    //printf("%d\n",tail->next->data); //check circular linked list
    int choice;
    while(1){
        printf("1.Print list\n2.Add node at beg\n3.Add node at end\n4.Add node at position\n5.Delete node at beg\n6.Delete node at end\n7.Delete node at position\n8.Quit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        if(choice==1) printList();
        else if(choice==2){
            insertbeg();
            len();
            printList();
        }else if(choice==3){
            insertend();
            len();
            printList();
        }else if(choice==4){
            insert_after_a_given_pos();
            len();
            printList();
        }else if(choice==5){
            deletebeg();
            len();
            printList();
        }else if(choice==6){
            deleteend();
            len();
            printList();
        }else if(choice==7){
            delete_specific_pos();
            len();
            printList();
        }else if(choice==8){
            return 0;
        }

    }


    return 0;
}

void printList() {
    struct node *ptr = tail->next;//start from the beginning
    while(ptr->next != tail->next) {
       printf("%d ",ptr->data);
       ptr = ptr->next;
    }
	printf("%d ",ptr->data);
    printf("\n");
}
void len(){
    length=0;
    struct node *ptr = tail->next;//start from the beginning
    while(ptr->next != tail->next) {
       ptr = ptr->next;
       length++;
    }
    length++;
}
void creating_list(int data) {
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));

   link->data = data;

   //link->next=0;

   if(tail==NULL) {
    //head =link;
    tail=link;
   }
   else {
    link->next=tail->next;
    tail=link;
   }
   tail->next=link;
   

}

void insertbeg(){
    struct node *link=(struct node*)malloc(sizeof(struct node));

    printf("Enter data at the beg:");
    scanf("%d",&link->data);

    //link->next=0;
    if(tail==0){
        tail=link;
        tail->next=link;
        //head=link;
    }else{
        link->next=tail->next;
        tail->next=link;
        //head=link;
    }
    
}
void insertend(){
    struct node *link = (struct node*) malloc(sizeof(struct node));

    printf("\nEnter new data at the end:");
    scanf("%d",&link->data);
    if(tail==0){
        tail=link;
        tail->next=link;
    }else{
        link->next=tail->next;
        tail->next=link;
        tail=link;
    }
    
}
void insert_after_a_given_pos(){
    int pos,i=1;
    printf("\nEnter position to insert:");
    scanf("%d",&pos);

    if(pos<0||pos>length) printf("Invalid position");
    else if(pos==1) insertbeg();
    else if(pos==length) insertend();
    else{
            struct node *link = (struct node*) malloc(sizeof(struct node));
            temp=tail->next;
            while(i<pos-1) {
                temp=temp->next;
                i++;
            }
            printf("\nEnter new data after a given pos:");
            scanf("%d",&link->data);

            link->next=temp->next;
            temp->next=link;

    }

}
void deletebeg(){
    temp=tail->next;
    if(tail==0){
        printf("Empty linked list\n");
        return;
    }
    if(temp==temp->next){
        tail=0;
        free(temp);
        return;
    }   
    tail->next=temp->next;
    free(temp);
}
void deleteend(){
    struct node *prev;
    temp=tail->next;
    if(tail==0){
        printf("Empty linked list\n");
        return;
    }
    if(temp==temp->next){
        tail=0;
        free(temp);
        return;
    }
    while(temp->next!=tail->next){
        prev=temp;
        temp=temp->next;
    }
    prev->next=tail->next;
    tail=prev;
    free(temp);
     
}
void delete_specific_pos(){
    int pos,i=1;
    printf("\nEnter position to delete:");
    scanf("%d",&pos);

    if(pos<1 || pos>length) printf("Invalid position\n");
    else if(pos==1) deletebeg();
    else if(pos==length) deleteend();
    else{
        struct node *nextnode;
        temp=tail->next;

        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        nextnode=temp->next;
        temp->next=nextnode->next;
        free(nextnode);


    }

}