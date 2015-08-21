#ifndef NODE_H
#define	NODE_H

typedef struct Node Node; 

struct Node {
    void* elem;
    Node* previous;
    Node* next;
};

#endif	/* NODE_H */

