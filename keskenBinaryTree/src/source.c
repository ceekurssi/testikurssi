#include <stdio.h>
#include <stdlib.h>
#include "source.h"

void printTree(Node* node){
    if (node != NULL){
        printf("\n%d ", node->value);
    }
    if (node->leftChild != NULL){
        printf("L%d ", node->leftChild->value);
    }
    if (node->rightChild != NULL){
        printf("R%d ", node->rightChild->value);
    }
    if (node->leftChild != NULL){
        printTree(node->leftChild);
    }
    if (node->rightChild != NULL){
        printTree(node->rightChild);
    }
}

void insert(Node* node, int value){
    if (node->value == NULL){
        node->value = value;
    } else if (value < node->value){
        if (node->leftChild != NULL){
            insert(node->leftChild, value);
        } else {
            node->leftChild = malloc(sizeof(Node));
            node->leftChild->value = value;
        }
    } else {
        if (node->rightChild != NULL){
            insert(node->rightChild, value);
        } else {
            node->rightChild = malloc(sizeof(Node));
            node->rightChild->value = value;
        }
    }
}
