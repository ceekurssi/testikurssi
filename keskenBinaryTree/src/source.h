typedef struct Node Node;
struct Node {
    int value;
    Node* leftChild;
    Node* rightChild;
};
/*BEGIN SOLUTION*/
Node* insert(Node* node, int value);
Node* delet(Node* node, int value);
Node* search(Node* node);
/*END SOLUTION*/
void inorder(Node* node);
void postorder(Node* node);
void preorder(Node* node);
