#include <stdlib.h>
#include "source.h"

Node* reverse(Node* root){
    /*BEGIN SOLUTION*/
    Node* prev = NULL;
    while(root != NULL){
        Node* temp = getNext(root);
        setNext(root, prev);
        prev = root;
        root = temp;
    }
    return prev;
    /*END SOLUTION*/
    /*STUB: return root; */
}

Node* cut(Node* root, int i){
    /*BEGIN SOLUTION*/
    if (i == 0){
        return root;
    }
    for(int j = i-1; j > 0; j--){
        root = getNext(root);
    }
    Node* tail = getNext(root);
    setNext(root, NULL);
    return tail;
    /*END SOLUTION*/
    /*STUB: return root; */
}

