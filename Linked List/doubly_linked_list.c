#include<stdio.h>
#include<stdlib.h>


void printList();
void reverse_print();
void creating_list(int data);
void insertbeg();
void insertend();
void insert_after_a_given_pos();
void deletebeg();
void deleteend();
void delete_specific_pos();
void len();


struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head=NULL;
struct node *temp=NULL;
struct node *tail=NULL;
int length=0;

int main(int argc,char *argv[])
{

    for(int i=0;i<10;i++) creating_list(i);
    len();
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
void len(){
    struct node *ptr=head; 
   while(ptr != NULL) {
      ptr=ptr->next;
        length++;
   }
}
void printList() {
   struct node *ptr=head; //for reverse-> ptr=temp;
   if(ptr==0){
    printf("List is empty\n");
    return ;
   }
   while(ptr != NULL) {
      printf("%d ",ptr->data);
      ptr=ptr->next;
   }
   printf("\n");
	
}

void reverse_print(){
    struct node *ptr=temp; //for reverse-> ptr=temp;
    while(ptr != NULL) {
      printf("%d ",ptr->data);
      ptr = ptr->prev;
   }
}

void creating_list(int data) {
   struct node *link = (struct node*) malloc(sizeof(struct node));

   link->data = data;
   link->prev=0;
   link->next=0;

   if(head==NULL) {
    head=link;
    temp=link;
    //tail=link;
   }
   else {
    link->prev=temp;
    temp->next=link;
    temp=link;
    tail=link;
   }

}

void insertbeg(){
    struct node *link = (struct node*) malloc(sizeof(struct node));

    printf("\nEnter new data at the top:");
    scanf("%d",&link->data);

    head->prev=link;
    link->next=head;
    head=link;
}

void insertend(){
    struct node *link = (struct node*) malloc(sizeof(struct node));

    printf("\nEnter new data at the end:");
    scanf("%d",&link->data);

    link->next=0;

    tail->next=link;
    link->prev=tail;
    //temp=link;
    tail=link;
}

void insert_after_a_given_pos(){
    int pos,i=1;
    printf("\nEnter position to insert:");
    scanf("%d",&pos);

    if(pos>length) printf("Invalid position");
    else{
            struct node *link = (struct node*) malloc(sizeof(struct node));
            temp=head;
            while(i<pos) {
                temp=temp->next;
                i++; 
            }
            printf("\nEnter new data after a given pos:");
            scanf("%d",&link->data);

            link->prev-temp;
            link->next=temp->next;
            temp->next=link;
            link->next->prev=link;


    }

}

void deletebeg(){
    //if(head==NULL) return;
    temp=head;
    head=head->next;
    head->prev=0;
    free(temp);

}

void deleteend(){
    if(tail==NULL) return;
    temp=tail;
    tail->prev->next=0;
    tail=tail->prev;
    free(temp);
    /*
    temp=tail;
    tail=tail->prev;
    tail->next=0;
    free(temp);  
    */
}

void delete_specific_pos(){
    temp=head;
    int pos,i=1;
    printf("\nEnter position to delete:");
    scanf("%d",&pos);

    while(i<pos){
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;

    free(temp);
}
