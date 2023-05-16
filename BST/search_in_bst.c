#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

bool search(struct tree *root,int key){
    if(root==NULL) return false;

    if(key==root->data) return true;

    else if(key< root->data) {
        return search(root->left,key);
    }
    else{
       return search(root->right,key);
    }

    
}


int main(int argc,char *argv[])
{

    int arr[]={5,1,3,4,2,7};

    for(int i=0;i<6;i++){
        root=build(root,arr[i]);
    }

    int key;
    printf("Enter data to search:");
    scanf("%d",&key);

    bool result=search(root,key);

    if(result) printf("Found\n");
    else printf("Not found\n");

    return 0;
}