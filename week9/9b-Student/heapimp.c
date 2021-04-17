#include "heap.h"

heap* heap_construct(int n)
{
    heap* tmp=(heap*)malloc(sizeof(heap)+n*sizeof(int));
    tmp->capacity=n;
    tmp->size=0;
    return(tmp);
}

void heap_destruct(heap* tmp)
{
    //TODO : Destroy the heap
    free(tmp);
}

int heap_get_capacity(heap* tmp)
{
    //TODO Return the max capaxity of the heap
    return tmp->capacity;
}

int heap_get_size(heap* tmp)
{
    //TODO Return the current size of the heap
    return tmp->size;
}

int heap_insert(heap* tmp,int data)
{
    // TODO : insert data into heap, return 1 if inserted,	return 0 if size > capacity
    if(tmp->size < tmp->capacity){
        tmp->elements[tmp->size] = data;
        tmp->size++;
        return 1;
    }
    return 0;
}

int heap_get_min(heap* tmp)
{
    //TODO : return the min value without deleting it

    int least, count = 0;
    least = tmp->elements[0];

    while(count < tmp->size){
        if(tmp->elements[count] < least){
            least = tmp->elements[count];
        }
        count++;
    }

    return least;
}

void heap_remove(heap* tmp)
{
    //TODO : delete the min value in the heap
    int least;
    least = heap_get_min(tmp);

    int count = 0;
    while(count < tmp->size){
        if(tmp->elements[count] == least) break;
        count++;
    }
    
    int index = count;
    while(index < tmp->size){
        tmp->elements[index] = tmp->elements[index + 1];
        index++;
    }
    tmp->size -= 1;
}

//submitted by PRANAV R HEGDE
//PES1UG19CS343
//PES1201901911
//F section
