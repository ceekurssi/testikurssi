#include <stdio.h>
#include <stdlib.h>
#include "source.h"

/* See source.h header for  */

int main() {
    
    Node* tree = NULL;
    tree = insert(tree, 3);
    tree = insert(tree, 2);
    tree = insert(tree, 8);
    tree = insert(tree, 1);
    tree = insert(tree, 5);
    inorder(tree);
    printf("\n");
    preorder(tree);
    printf("\n");
    postorder(tree);
    printf("\n");
    
    return 0;
}
