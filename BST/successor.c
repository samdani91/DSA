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

int successor(struct tree* root,int data){
    if(root->right!=NULL){
        return find_min(root->right);
    }else{
        
    }
}
struct tree *search(struct tree *root,int key){
    if(root==NULL) return NULL;

    if(key==root->data) return root;

    else if(key< root->data) {
        return search(root->left,key);
    }
    else{
       return search(root->right,key);
    }

    
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

    int arr[]={15,6,3,2,4,7,13,9,18,17,20};

    for(int i=0;i<11;i++){
        root=build(root,arr[i]);
    }
    inorder(root);

    int data;
    printf("\nEnter node to see successor:");
    scanf("%d",&data);

    int output=successor(search(root,data),data);
    printf("Successor of %d : %d\n",data,output);
    return 0;
}