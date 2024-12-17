// DELETION OF A NODE IN BST INORDER TRAVERSAL

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};
struct Node* getSuccessor(struct Node* curr) {
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

struct Node* delNode(struct Node* root, int x) {

    if (root == NULL)
        return root;

    if (root->key > x)
        root->left = delNode(root->left, x);
    else if (root->key < x)
        root->right = delNode(root->right, x);
    else {

        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* succ = getSuccessor(root);
        root->key = succ->key;
        root->right = delNode(root->right, succ->key);
    }
    return root;
}

struct Node* createNode(int key) {
    struct Node* newNode = 
       (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(25);
    int x = 5;

    root = delNode(root, x);
    inorder(root);
    return 0;
}
