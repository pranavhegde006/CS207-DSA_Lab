/*
    Author - Arvind Krishna
    LinkedIn - linkedin.com/in/aroo
    GitHub - github.com/ArvindAROO
    08 Sep 2020 18:43:22
*/
#include "cll.h"
void position_insert(List* cll, int data, int pos){
    if(pos > cll->length){
        //if the position is larger than the length of cll, it cant be done
        return;
    }
    if(cll->length == 0){
        //if the length is 0, the element will the first
        Node *current;
        current = (Node *)malloc(sizeof(Node));
        cll->head = current;
        current->next = current;
        current->data = data;
        cll->tail = current;
        cll->length++;
        return;
    }
    
    if(pos == 0){
        //provided that the length is not zero, adding the element at first
        Node *temp = NULL;
        temp = (Node *)malloc(sizeof(Node));
        temp->data = data;
        temp->next = cll->head;
        cll->head = temp;
        cll->tail->next = temp;
    }
    else if(pos == cll->length){
        //adding the element at last has a slightly different procedure since cll->tail must also be altered
        Node *last = cll->tail;
        Node *temp = NULL;
        temp = (Node *)malloc(sizeof(Node*));
        temp->data = data;
        temp->next = cll->head;
        last->next = temp;
        cll->tail = temp;
    }else{
        //if none of the above have been matched, it means, the element must be added somewhere in the middle
        Node *current = cll->head;
        for(int index = 0; index < pos - 1;index++){
            current = current->next;
        }
        Node *temp = NULL;
        temp = (Node *)malloc(sizeof(Node));
        temp->data = data;
        temp->next = current->next;
        current->next = temp;
    }

    cll->length++;
}

void position_delete(List* cll, int pos){
    if(pos >= cll->length){
        //the element cant be deleted if it doesnt exist
        return;
    }
    if(pos == 0){
        //if the element to be deleted is the first, then even the last element->next must be changed
        Node *first = cll->head;
        Node *temp = first->next;
        free(first);
        cll->tail->next = temp;
        cll->head = temp;
    }
    else if(pos == cll->length -1){
        //to delete the last element, the cll->tail must be altered
        Node *temp = cll->head;
        int index = 0;
        while(index < cll->length - 2){
            index++;
            temp = temp->next;
        }
        temp->next = cll->head;
        Node *last = cll->tail;
        free(last);
        cll->tail = temp;

    }
    else{
        //deleting an element somewhere in the middle
        Node *current;
        current = (Node *)malloc(sizeof(Node));
        current = cll->head;
        for(int index = 0; index < pos - 1;index++){
            current = current->next;
        }
        Node *toBeDeleted = current->next;
        current->next = toBeDeleted->next;
        free(toBeDeleted);
    }
    cll->length--;
}

int josephus(List* cll, int k){
    Node *temp = cll->head;
    int index = 0;
    while(index < k){
        //traversing to the node from which it starts
        temp = temp->next;
        index++;
    }
    index = 0;
    int iterComplete = 0;
    while(temp->next!=temp){
        //we keep removing numbers until, theres only 1 node left, ie its own next node too
        Node* Next = temp->next;
        temp->next = Next->next;
        temp = Next->next;
        cll->length--;
        free(Next);
        index+=2;
        if(index>=cll->length){
            if(temp == cll->head){
                //if the the first node is to be removed, iterComplete will be set as 1
                //to flag the change in cll->head
                iterComplete = 1;
            }
        }
        if(iterComplete == 1){
            cll->head = cll->head->next;
            iterComplete = 0;
        }
    }
    cll->head = temp;
    cll->tail = temp;
    cll->length = 1;
    return temp->data;
}