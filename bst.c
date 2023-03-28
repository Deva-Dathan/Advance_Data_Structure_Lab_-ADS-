#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) 
{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
}

struct node* insert(struct node* node, int data) 
{
    if (node == NULL) 
    {
        return newNode(data);
    }
    if (data < node->data) 
    {
        node->left = insert(node->left, data);
    } 
    else if (data > node->data) 
    {
        node->right = insert(node->right, data);
    }
    return node;
}

void inorder(struct node *root) 
{
    if (root != NULL) 
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct node* search(struct node* root, int key) 
{
    if (root == NULL || root->data == key) 
    {
       return root;
    }
    if (root->data < key) 
    {
       return search(root->right, key);
    }
    return search(root->left, key);
}

int main() 
{
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-Order Traversal : ");
    inorder(root);
    printf("\n\n");
    int key;
    printf("Enter the Key to Search : ");
    scanf("%d",&key);
    struct node* result = search(root, key);
    if (result != NULL) 
    {
        printf("%d Found in the Binary Search Tree\n\n", key);
    } 
    else 
    {
        printf("%d Not Found in the Binary Search Tree\n\n", key);
    }
    return 0;
}
