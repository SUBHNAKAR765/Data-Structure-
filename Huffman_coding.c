// Write a program in c to implement Huffman  coding 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    int freq;
    struct Node *left, *right;
};
struct Node* createNode(char data, int freq) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));//
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}
struct Node* insertHeap(struct Node* heap[], int* heapSize, struct Node* node) {
    heap[++(*heapSize)] = node;
    int i = *heapSize;
    while (i > 1 && heap[i]->freq < heap[i / 2]->freq) {
        struct Node* temp = heap[i];
        heap[i] = heap[i / 2];
        heap[i / 2] = temp;
        i = i / 2;
    }
    return heap[1];
}
struct Node* deleteHeap(struct Node* heap[], int* heapSize) {
    struct Node* min = heap[1];
    heap[1] = heap[(*heapSize)--];
    int i = 1;
    while (i * 2 <= *heapSize) {
        int child = i * 2;
        if (child < *heapSize && heap[child + 1]->freq < heap[child]->freq) {
            child++;
        }
        if (heap[i]->freq > heap[child]->freq) {
            struct Node* temp = heap[i];
            heap[i] = heap[child];
            heap[child] = temp;
            i = child;
        } else {
            break;
        }
    }
    return min;
}
void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    struct Node* heap[100];
    int heapSize = 0;

    for (int i = 0; i < size; i++) {
        heap[0] = insertHeap(heap, &heapSize, createNode(data[i], freq[i]));
    }
    
    while (heapSize > 1) {
        struct Node* left = deleteHeap(heap, &heapSize);
        struct Node* right = deleteHeap(heap, &heapSize);
        struct Node* newNode = createNode('-', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        heap[0] = insertHeap(heap, &heapSize, newNode);
    }

    int arr[100], top = 0;
    printCodes(heap[1], arr, top);

    return 0;
}
