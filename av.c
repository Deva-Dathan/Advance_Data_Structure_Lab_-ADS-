#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
    int data;
    int height;
    struct AVLNode *left;
    struct AVLNode *right;
} AVLNode;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(AVLNode *node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int balanceFactor(AVLNode *node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

AVLNode *createNode(int data) {
    AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
    newNode->data = data;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

AVLNode *rotateLeft(AVLNode *node) {
    AVLNode *newRoot = node->right;
    AVLNode *temp = newRoot->left;

    newRoot->left = node;
    node->right = temp;

    node->height = 1 + max(height(node->left), height(node->right));
    newRoot->height = 1 + max(height(newRoot->left), height(newRoot->right));

    return newRoot;
}

AVLNode *rotateRight(AVLNode *node) {
    AVLNode *newRoot = node->left;
    AVLNode *temp = newRoot->right;

    newRoot->right = node;
    node->left = temp;

    node->height = 1 + max(height(node->left), height(node->right));
    newRoot->height = 1 + max(height(newRoot->left), height(newRoot->right));

    return newRoot;
}

AVLNode *insertNode(AVLNode *node, int data) {
    if (node == NULL) {
        return createNode(data);
    }

    if (data < node->data) {
        node->left = insertNode(node->left, data);
    } else if (data > node->data) {
        node->right = insertNode(node->right, data);
    } else {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));
    int bf = balanceFactor(node);

    if (bf > 1 && data < node->left->data) {
        return rotateRight(node);
    }
    if (bf < -1 && data > node->right->data) {
        return rotateLeft(node);
    }
    if (bf > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (bf < -1 && data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void printInorder(AVLNode *node) {
    if (node == NULL) {
        return;
    }
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main() 
{
    AVLNode *root = NULL;
    int choice, data;
    do 
    {
        printf("1. Insert an element\n");
        printf("2. Print inorder traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

    switch (choice) 
    {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            root = insertNode(root, data);
            printf("%d inserted successfully!\n", data);
            break;
        case 2:
            printf("Inorder traversal of the AVL tree: ");
            printInorder(root);
            printf("\n");
            break;
        case 3:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
    }
} 
while (1);
}