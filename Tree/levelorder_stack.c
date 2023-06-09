#include <stdio.h>
#include <stdlib.h>

void level_order(int size);
struct tree* create_tree();

struct tree{
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *root=NULL;

int main() {
    int size;
    printf("Enter size of the tree:");
    scanf("%d",&size);
    root=create_tree();
    level_order(size);

    return 0;
}

struct tree* create_tree(){
    struct tree *newtree;
    newtree=(struct tree*)malloc(sizeof(struct tree));
    int value;
    printf("Enter data:(-1 for no tree):");
    scanf("%d",&value);

    if(value==-1) return 0;
    newtree->data=value;
    printf("\nEnter left child of %d :\n",value);
    newtree->left=create_tree();

    printf("\nEnter right child of %d :\n",value);
    newtree->right=create_tree();


    return newtree;

}


void level_order(int size)
{
    struct tree *queue[size];
    int front=0,rear=0,level=1;
    if(root==NULL)
    return;
    queue[rear++]=root;
    
    while(front<rear)
    {
        struct tree *temp = queue[front++];
        printf("%d ", temp->data);
        level--;
        
        if(temp->left!=NULL)
        queue[rear++]=temp->left;
        if(temp->right!=NULL)
        queue[rear++]=temp->right;
        if(level==0){
        printf("\n");
        level = rear-front;
        }
    }
}