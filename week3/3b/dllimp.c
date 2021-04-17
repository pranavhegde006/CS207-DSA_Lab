#include"dll.h"

int count_nodes(List* dll){
    Node* iteratorNode = (Node*)malloc(sizeof(Node));
    iteratorNode = dll->head;

    int countNodes = 0;
    while(iteratorNode != NULL){
        countNodes++;
        iteratorNode = iteratorNode->next;
    } 
    return countNodes;
}

void insert_front(List* dll, int data){
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;

    if(dll->head == NULL){
        newNode->next = NULL;
        dll->head = newNode;
    }

    else{
        newNode->next = dll->head;
        dll->head->prev = newNode;
        dll->head = newNode;
    }
    dll->number_of_nodes++;
}


void dllist_delete_beginning(List* list){
    if(list->head == NULL) return;
    else{
        Node* iteratorNode = (Node*)malloc(sizeof(Node));
        iteratorNode = list->head;
        list->head = iteratorNode->next;
        list->head->prev = NULL;
        free(iteratorNode);
        list->number_of_nodes--;
    }
}


void position_delete(List* dll, int pos){
    if(dll->head != NULL && pos < dll->number_of_nodes && pos >= 0){
        Node* iteratorNode = (Node*)malloc(sizeof(Node));
        iteratorNode = dll->head;
        
        int countNodes = 0;
            while(iteratorNode->next != NULL && countNodes != pos){
                iteratorNode = iteratorNode->next;
                    countNodes++;
            }
            iteratorNode->prev->next = iteratorNode->next;
            iteratorNode->next->prev = iteratorNode->prev;
        dll->number_of_nodes--;
        free(iteratorNode);
    }
}



int search_list(List* dll,int key){
    
    if(dll->head == NULL){
        return -1;
    }

    Node* iteratorNode = (Node*)malloc(sizeof(Node));
    iteratorNode = dll->head;
    int countNodes = 0;
    while(iteratorNode != NULL){
        if(iteratorNode->data == key){
            return countNodes;
        }
        iteratorNode = iteratorNode->next;
        countNodes++;
    }
    return -1;
}


void reverse_list(List* dll){
    
    Node* iteratorNode = (Node*)malloc(sizeof(Node));
    iteratorNode = NULL;
    Node* swapNode = (Node*)malloc(sizeof(Node));
    swapNode = dll->head;

    while(swapNode != NULL){
        iteratorNode = swapNode->prev;
        swapNode->prev = swapNode->next;
        swapNode->next = iteratorNode;
        swapNode = swapNode->prev;
    }

    if(iteratorNode != NULL){
        dll->head = iteratorNode->prev;
    }
}


//this lab program is submitted by Pranav R Hegde of section F(online)
//PES1UG19CS343    &&    PES1201901911