#include <stdio.h>
#include <stdlib.h>
#include "source.h"

/* Binary tree */

int main() {
    
    Node* tree = malloc(sizeof(Node));

    insert(tree, 3);
    insert(tree, 2);
    insert(tree, 8);
    insert(tree, 1);
    insert(tree, 5);
    printTree(tree);
    
    return 0;
}
