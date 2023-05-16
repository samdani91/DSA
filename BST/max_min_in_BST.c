#include<stdio.h>
#include<stdlib.h>

struct tree{
    int data;
    struct tree *left,*right;
};

struct tree *root = NULL;

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
int find_min(struct tree *root){
    if(root->left==NULL) return root->data;
    find_min(root->left);

}
int find_max(struct tree *root){
    if(root->right==NULL) return root->data;
    find_max(root->right);

}
int main(int argc,char *argv[])
{

    int arr[]={5,1,3,4,2,7};

    for(int i=0;i<6;i++){
        root=build(root,arr[i]);
    }

    printf("Minimum in the BST:%d\n",find_min(root));
    printf("Maximum in the BST:%d\n",find_max(root));
    
    return 0;
}