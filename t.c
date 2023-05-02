#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

int height(struct Node* node) {
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    printf("Right Rotation\n");
    return x;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    printf("Left Rotation\n");
    return y;
}

int getBalance(struct Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct Node* insertNode(struct Node* node, int data) {
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
    return rightRotate(node);
}

if (balance < -1 && data < node->right->data) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
}

return node;
}

void inorder(struct Node* node) {
if (node == NULL)
return;
inorder(node->left);
printf("%d ", node->data);
inorder(node->right);
}

int main() 
{
    struct Node* root = NULL;
    int i,choice, data, nofelement;
    while(1)
    {
        printf("\n1. Insert An Element:\t");
        printf("2. Print Inorder Traversal:\t");
        printf("3. Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
    switch (choice) 
    {
        case 1:
            if(choice == 1)
            {
            printf("Enter How Many Elements To Be Inserted:");
            scanf("%d",&nofelement);
            for(i=1;i<=nofelement;i++)
            {
            printf("Enter the %d Element: ",i);
            scanf("%d", &data);
            root = insertNode(root, data);
            }
            }
            break;
        case 2:
            printf("Inorder traversal of the AVL tree: ");
            inorder(root);
            printf("\n");
            break;
        case 3:exit(0);
        default:printf("Invalid Choice!\n");
    }
} 
}