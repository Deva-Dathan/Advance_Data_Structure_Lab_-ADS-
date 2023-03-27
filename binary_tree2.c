#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int data) {
    struct node *node = (struct node *) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct node *root = newNode(40);
    root->left = newNode(35);
    root->right = newNode(60);
    root->left->left = newNode(20);
    root->left->right = newNode(38);
    root->right->left = newNode(50);
    root->right->right = newNode(80);

    printf("Inorder traversal: ");
    inorder(root);

    printf("\nPreorder traversal: ");
    preorder(root);

    printf("\nPostorder traversal: ");
    postorder(root);
}
