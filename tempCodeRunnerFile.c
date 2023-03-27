struct node* insert(struct node* node, int data) 
// {
//     if (node == NULL) 
//     {
//         return newNode(data);
//     }
//     if (data < node->data) 
//     {
//         node->left = insert(node->left, data);
//     } 
//     else if (data > node->data) 
//     {
//         node->right = insert(node->right, data);
//     }
//     return node;
// }