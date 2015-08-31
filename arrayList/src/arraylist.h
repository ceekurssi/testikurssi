#ifndef ARRAYLIST_H
#define	ARRAYLIST_H

/**
 * Here we declare struct ArrayList but don't expose its contents in the header file.
 */
typedef struct ArrayList ArrayList;

/*
 * Public method declarations.
 */
ArrayList* ArrayList_new();
ArrayList* ArrayList_new_withInitialCapacity(size_t initialMax);
void ArrayList_add(ArrayList*, void* element);
void* ArrayList_get(ArrayList*, int index);
void ArrayList_remove(ArrayList*, int index);
int ArrayList_size(ArrayList*);
void ArrayList_destroy(ArrayList*);

#endif	/* ARRAYLIST_H */
