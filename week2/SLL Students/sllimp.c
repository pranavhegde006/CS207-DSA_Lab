#include<stdio.h>
#include<stdlib.h>
#include "sll.h"

void insert_at_end(List *list, int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    Node* newNode = (Node*)malloc(sizeof(Node));
    temp = list->head;
    newNode->data = data;
    newNode->link = NULL;
    
    if(temp == NULL){
        list->head = newNode;
    }
    else{
        while(temp->link != NULL){
            temp = temp->link;
        }

        temp->link = newNode;
    }
    list->number_of_nodes++;
}


void list_delete_front(List* list) {
    if(list->head != NULL){
        Node* temp = (Node*)malloc(sizeof(Node));
        temp = list->head;
        list->head = temp->link;
        free(temp);
        list->number_of_nodes--;
    }
}

void list_insert_at(List *list, int data, int position) {

    if(position < 0 || position > list->number_of_nodes) return;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if(list->head == NULL){
        newNode->link = NULL;
        list->head = newNode;
    }
    
    else if(position == 0){
        newNode->link = list->head;
        list->head = newNode;
    }

    else{
        Node* iterNode = (Node*)malloc(sizeof(Node));
        iterNode = list->head;
        for(int i = 1; i < position; i++){
            iterNode = iterNode->link;
        }
        newNode->link = iterNode->link;
        iterNode->link = newNode;
    }
    
    list->number_of_nodes++;
}

void list_reverse(List* list) {
    Node* previous = (Node*)malloc(sizeof(Node));
    Node* current = (Node*)malloc(sizeof(Node));
    Node* next = (Node*)malloc(sizeof(Node));

    previous = NULL;
    current = list->head;
    next = NULL;

    while(current != NULL){
        next = current->link;
        current->link = previous;
        previous = current;
        current = next;
    }
    list->head = previous;
}
