#ifndef HASHMAPNODE_H
#define	HASHMAPNODE_H

typedef struct HashMapNode HashMapNode;

struct HashMapNode{
    void* key;
    void* data;
    uint32_t hash;
};



#endif	/* HASHMAPNODE_H */

