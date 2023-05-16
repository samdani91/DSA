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
void inorder(struct tree *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main(int argc,char *argv[])
{

    int arr[]={5,1,3,4,2,7};

    for(int i=0;i<6;i++){
        root=build(root,arr[i]);
    }

    inorder(root);
    return 0;
}