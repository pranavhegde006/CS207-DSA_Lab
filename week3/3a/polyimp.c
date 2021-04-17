#include "poly.h"
void insert_at_end(List *list, int data) 
{
	Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;

    if(list->head == NULL){
        list->head = newNode;
    }
    else{
        Node *temp = (Node*)malloc(sizeof(Node));
        temp = list->head;
        while(temp->link != NULL){
            temp = temp->link;
        }
        temp->link = newNode;
    }
    
    list->number_of_nodes++;
}

long long int evaluate(List *list, int x){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp = list->head;
    long long int polySum = 0;    
   	long long int power = 1;
    int raisedTo = 0;
    
    while(temp != NULL){
        int count = 0;
		while(count < raisedTo){
			power *= x;
            count++;
		}
        polySum += temp->data * power;      
        raisedTo++;
        power = 1;
        temp = temp->link;
    }
    return polySum;
}


//this lab program is submitted by Pranav R Hegde of section F(online)
//PES1UG19CS343    &&    PES1201901911