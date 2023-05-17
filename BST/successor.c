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

int successor(struct tree* root, int data) {
    if (root == NULL)
        return -1; 

    struct tree* targetNode = search(root, data);

    if (targetNode == NULL)
        return -1; 

    if (targetNode->right != NULL)
        return find_min(targetNode->right);

    struct tree* successor = NULL;
    struct tree* ancestor = root;

    while (ancestor != targetNode) {
        if (data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }

    if (successor == NULL)
        return -1; 

    return successor->data;
}

void inorder(struct tree *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main(int argc, char *argv[]) {
    int arr[] = {15, 6, 3, 2, 4, 7, 13, 9, 18, 17, 20};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        root = build(root, arr[i]);
    }

    printf("Inorder traversal of the tree: ");
    inorder(root);

    int data;
    printf("\nEnter a node to find its successor: ");
    scanf("%d", &data);

    int output = successor(root, data);
    if (output != -1)
        printf("Successor of %d: %d\n", data, output);
    else
        printf("No successor found for %d\n", data);

    return 0;
}