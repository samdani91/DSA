#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct tree *build(struct tree* root,int data);
struct tree *delete_node(struct tree* root,int key);
struct tree *inorderSuccessor(struct tree* root);
void inorder(struct tree *root);

struct tree{
    int data;
    struct tree *left,*right;
};

struct tree *root = NULL;

int main(int argc,char *argv[])
{

    int arr[]={5,1,3,4,2,7};

    for(int i=0;i<6;i++){
        root=build(root,arr[i]);
    }
    inorder(root);
    
    int key;
    printf("\nEnter data to delete:");
    scanf("%d",&key);

    delete_node(root,key);

    inorder(root);
    
    return 0;
}

struct tree *build(struct tree* root,int data)
{
    if(root==NULL) {
        root = (struct tree*)malloc(sizeof(struct tree));
        root->data=data;
        root->left= NULL;
        root->right= NULL;
        return root;
    }

    if(data< root->data)
    root->left=build(root->left, data);
    else
    root->right= build(root->right, data);

    return root;

}

struct tree *delete_node(struct tree* root,int key){
    if(root->data > key){
        root->left=delete_node(root->left,key);
    }else if(root->data < key){
        root->right= delete_node(root->right,key);
    }else{
        //case 1: no child
        if(root->left==NULL && root->right==NULL) {
            return NULL;
        }

        //case 2: one child
        if(root->left==NULL){
            return root->right;
        }else if(root->right==NULL){
            return root->left;
        }

        //case 3: two child
        struct tree *IS=(struct tree*)malloc(sizeof(struct tree));
        IS=inorderSuccessor(root->right);
        root->data= IS->data;
        root->right=delete_node(root->right,IS->data);
    }
    return root;
}

struct tree *inorderSuccessor(struct tree* root){
    while(root->left!=NULL){
        root=root->left;
    }

    return root;

}

void inorder(struct tree *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
