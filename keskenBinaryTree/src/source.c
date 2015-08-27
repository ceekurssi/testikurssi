/*BEGIN SOLUTION*/
#include <stdio.h>
#include <stdlib.h>
#include "source.h"

Node* insert(Node* node, int value) {
    if (!node) {
        node = malloc(sizeof(Node));
        node->value = value;
        node->leftChild = NULL;
        node->rightChild = NULL;
        return node;
    }
    if (value < node->value) {
        node->leftChild = insert(node->leftChild, value);
    } else {
        node->rightChild = insert(node->rightChild, value);
    }
    return node;
}

Node* delet(Node* node, int value){
    
}

/*END SOLUTION*/

void inorder(Node* node){
    if (node != NULL){
        inorder(node->leftChild);
        printf(" %d", node->value);
        inorder(node->rightChild);
    }
    return;
}

void postorder(Node* node){
    if (node != NULL){
        postorder(node->leftChild);
        postorder(node->rightChild);
        printf(" %d", node->value);
    }
    return;
}

void preorder(Node* node){
    if (node != NULL){
        printf(" %d", node->value);
        preorder(node->leftChild);
        preorder(node->rightChild);
    }
}
