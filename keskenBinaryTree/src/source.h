typedef struct Node Node;
struct Node {
    int value;
    Node* leftChild;
    Node* rightChild;
};
void insert(Node* node, int value);
void printTree(Node* node);
void printDFS(Node* node);
