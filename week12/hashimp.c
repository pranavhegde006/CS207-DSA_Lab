#include "hash.h"
HashTable *create_table(int size){
    //TODO
    HashTable * htable = (HashTable*)malloc(sizeof(HashTable));
    htable->size = size;
    htable->table = (int *)malloc(sizeof(int) * size);
    for(int i = 0; i < htable->size; i++) htable->table[i] = -1;
    return htable;
}

void insert(HashTable *htable, int element){
    //TODO
    if(htable==NULL) return;
    int key;
    for(key = element % (htable->size); htable->table[key]!=0 && htable->table[key]!=-1; ++key){
        key = key % (htable->size);   
    }
    htable->table[key] = element;
    return;
}

int search(HashTable *htable, int element){
    //TODO
    for(int key = element%(htable->size); htable->table[key]!=-1; ++key){
        if(htable->table[key]==element) return 1;
        key=key%(htable->size);
    }
    return 0;
}

void delete (HashTable *htable, int element){
    //TODO
    int key; 
    key = element % (htable->size);
    if(htable->table[key] == element){
        // htable->size--;
        htable->table[key]=-1;
    }
    else return;
}

void destroy_table(HashTable *htable){
    //TODO
    free(htable->table);
    free(htable);
}
