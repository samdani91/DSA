#include<stdio.h>
#include<stdlib.h>

struct tree* create_tree();

struct tree{
    int data;
    struct tree *left,*right;
};

struct tree *root=NULL;

int main(int argc,char *argv[])
{

    root=create_tree();


    return 0;
}

struct tree* create_tree(){
    struct tree *newnode;
    newnode=(struct tree*)malloc(sizeof(struct tree));
    int value;
    printf("Enter data:(-1 for no node):");
    scanf("%d",&value);

    if(value==-1) return 0;
    newnode->data=value;
    printf("\nEnter left child of %d :\n",value);
    newnode->left=create_tree();

    printf("\nEnter right child of %d :\n",value);
    newnode->right=create_tree();

    return newnode;

}