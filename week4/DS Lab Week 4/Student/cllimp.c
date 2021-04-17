#include "cll.h"

/*  
    Pranav R Hegde
    PES1UG19CS343
    F section
    Dept. of CSE, PESU(RR campus)
    pranavhegde06@gmail.com
*/

void position_insert(List* cll, int data, int pos){

    //index out of bound error condition
    if(pos > cll->length || pos < 0){
        return;
    }

    //insertion in an empty list
    else if(cll->head == NULL){
        Node *headNode = (Node*)malloc(sizeof(Node));
        headNode->data = data;
        headNode->next = headNode;
        cll->head = headNode;
        cll->tail = headNode;
        cll->length++;
    }

    //insertion at head
    else if(pos == 0){
        Node *newHead = (Node*)malloc(sizeof(Node));
        newHead->data = data;
        newHead->next = cll->head;
        cll->head = newHead;
        cll->tail->next = newHead;
        cll->length++;
    }

    //insertion at tail
    else if(pos == cll->length){
        Node *tail = (Node*)malloc(sizeof(Node));
        Node* newTail = (Node*)malloc(sizeof(Node));
        tail = cll->tail;
        newTail->data = data;
        newTail->next = cll->head;
        tail->next = newTail;
        cll->tail = newTail;
        cll->length++;
    }

    //insertion at anywhere in between
    else{
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        Node *iteratorNode = (Node*)malloc(sizeof(Node));
        iteratorNode = cll->head;
        int count = 0;
        while(count != pos - 1){
            iteratorNode = iteratorNode->next;
            count++;
        }
        newNode->next = iteratorNode->next;
        iteratorNode->next = newNode;
        cll->length++;
    }
}


void position_delete(List* cll, int pos){
    
    //index out of bound error condition
    if(pos >= cll->length && pos < 0){
        return;
    }

    //deletion at head
    if(pos == 0){
        Node *delNode = (Node*)malloc(sizeof(Node));
        Node *newHead = (Node*)malloc(sizeof(Node));
        delNode = cll->head;
        newHead = delNode->next;
        free(delNode);
        cll->tail->next = newHead;
        cll->head = newHead;
        cll->length--;
    }

    //deletion at tail
    else if(pos == cll->length -1){
        Node *iteratorNode = (Node*)malloc(sizeof(Node));
        Node *delNode = (Node*)malloc(sizeof(Node));
        iteratorNode = cll->head;
        delNode = cll->tail;
        for(int i = 0; i < cll->length - 2; i++){
            iteratorNode = iteratorNode->next;
        }
        iteratorNode->next = cll->head;
        free(delNode);
        cll->tail = iteratorNode;
        cll->length--;

    }

    //deletion at anywhere in between
    else{
        Node *iteratorNode = (Node *)malloc(sizeof(Node));
        iteratorNode = cll->head;
        for(int index = 0; index < pos - 1;index++){
            iteratorNode = iteratorNode->next;
        }
        Node *delNode = iteratorNode->next;
        iteratorNode->next = delNode->next;
        cll->length--;
        free(delNode);
    }
}


//fucntion to solve the josephus problem and find the last node standing
int josephus(List* cll, int k){

    Node* iteratorNode = (Node*)malloc(sizeof(Node));
    Node* executedNode = (Node*)malloc(sizeof(Node));
    iteratorNode = cll->head;

    int count = 0;
    while(count != k){
        iteratorNode = iteratorNode->next;
        count++;
    }
    
    while(cll->length != 1){
        executedNode = iteratorNode->next;
        iteratorNode->next = executedNode->next;
        free(executedNode);
        iteratorNode = iteratorNode->next;
        cll->length--;
    }
    
    cll->head = iteratorNode;
    cll->tail = iteratorNode;

    return cll->head->data;
}

//  End-of-file //
