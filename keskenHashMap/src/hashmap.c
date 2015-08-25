#include <stdlib.h>
#include <stdint.h>
#include "hashmap.h"
#include "arraylist.h"
#include "hashmapnode.h"

ArrayList* HashMap_getBucket(HashMap* self, void* key, int create, uint32_t hash_out);
int HashMap_getNode(HashMap* self, uint32_t hash, ArrayList* bucket, void* key);
HashMapNode* HashMapNode_new(int hash, void* key, void* data);

struct HashMap {
    ArrayList* buckets;
    HashMap_compare compare;
    HashMap_hash hash;
};

HashMap* HashMap_new(HashMap_compare compare, HashMap_hash hash) {
    HashMap* self = calloc(1, sizeof (HashMap));
    self->compare = compare;
    self->hash = hash;
    self->buckets = ArrayList_new_withInitialCapacity(100);
    for (int i = 0; i < 100; i++) {
        ArrayList_add(self->buckets, ArrayList_new());
    }
    return self;
}

void HashMap_put(HashMap* self, void* key, void* data) {
    uint32_t hash = 0;
    ArrayList* bucket = HashMap_getBucket(self, key, 1, &hash);
    HashMapNode* node = HashMapNode_new(hash, key, data);
    ArrayList_add(bucket, node);
    return 0;
}

ArrayList* HashMap_getBucket(HashMap* self, void* key, int create, uint32_t hash_out) {
    uint32_t hash = self->hash(key);
    int bucket_n = hash % 100;
    *hash_out = hash;
    ArrayList* bucket = ArrayList_get(self->buckets, bucket_n);

    if (!bucket && create) {
        bucket = ArrayList_new();
    }
    return bucket;
}

int HashMap_getNode(HashMap* self, uint32_t hash, ArrayList* bucket, void* key){
    for (int i = 0; i < ArrayList_size(bucket); i++){
        HashMapNode* node = ArrayList_get(bucket, i);
        if (node->hash == hash && self->compare(node->key, key) == 0){
            return i;
        }
    }
    return -1;
}

HashMapNode* HashMapNode_new(int hash, void* key, void* data){
    HashMapNode* node = calloc(1, sizeof(HashMapNode));
    node->key = key;
    node->hash = hash;
    node->data = data;
    return node;
}

void* HashMap_get(HashMap* self, void* key) {
    uint32_t hash = 0;
    ArrayList* bucket = HashMap_getBucket(self, key, 0, &hash);
    if (!bucket) {
        return NULL;
    }
    int i = HashMap_getNode(self, hash, bucket, key);
    if (i == -1) {
        return NULL;
    }
    HashMapNode* node = ArrayList_get(bucket, i);
    return node->data;
}

void HashMap_remove(HashMap* self, void* key) {
    uint32_t hash = 0;
    ArrayList* bucket = HashMap_getBucket(self, key, 0, &hash);
    if (!bucket){
        return NULL;
    }
    int i = HashMap_getNode(self, hash, bucket, key);
    if (i == -1){
        return NULL;
    }
    HashMapNode* node = ArrayList_get(bucket, i);
    void* data = node->data;
    ArrayList_remove(bucket, i);
    free(node);
}
