#ifndef HASHMAP_H
#define	HASHMAP_H

typedef int (*HashMap_compare)(void* a, void* b);
typedef uint32_t (*HashMap_hash)(void* key);
typedef struct HashMap HashMap;

HashMap* HashMap_new(HashMap_compare compare, HashMap_hash hash);
void HashMap_put(HashMap* self, void* key, void* value);
void* HashMap_get(HashMap* self, void* key);
void HashMap_remove(HashMap* self, void* key);

#endif	/* HASHMAP_H */

