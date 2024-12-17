// INSERTION OF NODE IN BST INORDER TRAVERSAL

#include <stdio.h>
#include <stdlib.h>
//structure for a BST node
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int item) {
    struct Node* temp = 
       (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* node, int key) {
  
    if (node == NULL)
        return newNode(key);
    
    if (node->key == key)
        return node;
    
    if (node->key < key)
        node->right = insert(node->right, key);
 
    else
        node->left = insert(node->left, key);

    return node;
}


void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}


int main() {
   

    struct Node* root = newNode(50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    inorder(root);

    return 0;
}