#include<stdio.h>
#include<stdlib.h>

#define size 10

void input();
void copy_marks(int arr[]);
void sort(int arr[]);
void printList();
void creating_list(int roll,int marks);
void add_student();
void delete_student();
void search();



struct student{
    int roll;
    int marks;
    struct student *next;
}bsse14[size];

struct student *head=NULL;
struct student *temp=NULL;
int length=0;

int main(int argc,char *argv[])
{
    int mark[size],choice;
    input();
    copy_marks(mark);

    for(int i=0;i<size;i++){
       for(int j=0;j<size;j++){
            if(mark[i]==bsse14[j].marks){
                creating_list(bsse14[j].roll,bsse14[j].marks);         
            }
       }
    }

    while(1){
        printf("1.Print list\n2.Add Student\n3.Remove Student\n4.Quit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        if(choice==1) printList();
        else if(choice==2){
            add_student();
            printList();
        }else if(choice==3){
            delete_student();
            printList();
        }else if(choice==4){
            break;
        }

    }
    
    return 0;
}

void printList() {
   struct student *ptr = head;
   //start from the beginning
   printf("\tMarks\t\tRoll\n");
   while(ptr != NULL) {
      printf("\t%d \t\t%d\n",ptr->marks,ptr->roll);
      ptr = ptr->next;
      length++;
   }
	
}

void input(){
    FILE *fp;
    fp=fopen("input.txt","r");
    for(int i=0;i<size;i++){
        fscanf(fp,"%d",&bsse14[i].roll); //fscanf(fp,"%d %d",&bsse14[i].roll,&bsse14[i].marks);
        fscanf(fp,"%d",&bsse14[i].marks);
    }
    fclose(fp);
}

void copy_marks(int arr[]){
    for(int i=0;i<size;i++){
        arr[i]=bsse14[i].marks;
    }
    sort(arr);
}

void sort(int arr[]){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]<arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void creating_list(int roll,int marks) {
   //create a link
   struct student *link = (struct student*) malloc(sizeof(struct student));

   link->roll = roll;
   link->marks=marks;

   link->next=0;

   if(head==NULL) {
    head=link;
    temp=link;
   }
   else {
    temp->next=link;
    temp=link;
   }

}

void add_student(){
    
    struct student *link = (struct student*) malloc(sizeof(struct student));
    struct student *prevstudent;
    temp=head;
    printf("\nEnter new roll:");
    scanf("%d",&link->roll);
    printf("Enter marks:");
    scanf("%d",&link->marks);

    if(link->marks <= head->marks){
        while(temp!=NULL && temp->marks >= link->marks){
            prevstudent=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            prevstudent->next=link;
            link->next=NULL;
        }else{
            link->next=temp;
            prevstudent->next=link;
        }
    }else{
        link->next=head;
        head=link;
    }

}

void delete_student(){
    struct student *prevstudent;
    temp=head;
    int roll;
    printf("\nEnter roll to delete:");
    scanf("%d",&roll);

    while(temp->roll!=roll){
        prevstudent=temp;
        temp=temp->next;
            
    }
    if(temp==head) head=temp->next;
    else{
        prevstudent->next=temp->next;
    }
    free(temp);
    
}