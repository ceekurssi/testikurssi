#ifndef ARRAYLIST_H
#define	ARRAYLIST_H

typedef struct ArrayList ArrayList;

ArrayList* ArrayList_new();
ArrayList* ArrayList_new_withInitialCapacity(size_t initialMax);
void ArrayList_add(ArrayList* self, void* element);
void* ArrayList_get(ArrayList* self, int i);
void ArrayList_remove(ArrayList* self, int i);
int ArrayList_size(ArrayList* self);

#endif	/* ARRAYLIST_H */
