#include <stdio.h>
#include <stdlib.h>

void inorder(int size);
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
    inorder(size);
}

struct tree* create_tree(){
    struct tree *newtree;
    newtree=(struct tree*)malloc(sizeof(struct tree));
    int value;
    printf("Enter data:(-1 for no node):");
    scanf("%d",&value);

    if(value==-1) return 0;
    newtree->data=value;
    printf("\nEnter left child of %d :\n",value);
    newtree->left=create_tree();

    printf("\nEnter right child of %d :\n",value);
    newtree->right=create_tree();


    return newtree;

}

void inorder(int size) {
    struct tree* Stack[size],*current;
    int top=-1;
    current=root;
    while (current != NULL || top!=-1) {
        while (current != NULL) {
            Stack[++top]=current;
            current = current->left;
        }
        current = Stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}
