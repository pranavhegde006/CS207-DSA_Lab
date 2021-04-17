#include "5a.h"

static Node* create_Node(int data, Node* link){
    //allocates memory to node and fills it with the provided value
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = link;
    return newNode;
}


void list_initialize(List* ptr_list) {
    //initialises the list by setting number of nodes to zero and head to null
    ptr_list->head = NULL;
    ptr_list->number_of_Nodes = 0;
}


void list_insert_front(List* ptr_list, int data) {
    //inserts the element at front
    Node* temp = (Node*)malloc(sizeof(Node));
    temp = ptr_list->head;
    Node* headNode = create_Node(data, temp);
    ptr_list->number_of_Nodes++;
    ptr_list->head = headNode;
}


const int Node_get_data(Node *Node_ptr) {
    //returns the element of the particular node
    return Node_ptr->data;
}


void list_delete_front(List* ptr_list) {
    //deletes the front element on the list
    Node* delNode = (Node*)malloc(sizeof(Node));
    delNode = ptr_list->head;
    ptr_list->head = delNode->link;
    ptr_list->number_of_Nodes--;
    free(delNode);
}


void list_destroy(List* ptr_list) {
    //frees the list memory
    Node* iteratorNode = (Node*)malloc(sizeof(Node));
    Node* freeNode = (Node*)malloc(sizeof(Node));
    iteratorNode = ptr_list->head;
    freeNode = NULL;
    for(int i = 0; i < ptr_list->number_of_Nodes; i++){
        freeNode = iteratorNode;
        iteratorNode = iteratorNode->link;
        free(freeNode);
    }
    free(ptr_list);
}

void Stack_initialize(Stack *ptr_Stack) {
    //allcoates memory to the stack pointer
    ptr_Stack -> ptr_list = malloc(sizeof(struct List));
    list_initialize(ptr_Stack->ptr_list);
}

void Stack_push(Stack *ptr_Stack, int key) {
    //pushes the element to the topmost position in the stack
    list_insert_front(ptr_Stack->ptr_list, key);
}

void Stack_pop(Stack *ptr_Stack) {
    //deletes the topmost element in the stack
    list_delete_front(ptr_Stack->ptr_list);
}

int Stack_is_empty(Stack *ptr_Stack) {
    //returns if stack is empty
    if(ptr_Stack->ptr_list->number_of_Nodes == 0){
        return 1;
    }
    return 0;
}

const int Stack_peek(Stack *ptr_Stack) {
    //returns the element  on the top of the stack
    return ptr_Stack->ptr_list->head->data;
}

void Stack_destroy(Stack *ptr_Stack){
    //frees the stack pointer
    list_destroy(ptr_Stack->ptr_list);
    free(ptr_Stack);
}

int match_parenthesis(const char* string){
//TODO - implement the code to match paranthesis in a string which is passed as a parameter.
    Stack stackObject;
    Stack_initialize(&stackObject);

    while((*string) != '\0'){
        switch (*string){
        
        case '(':
            Stack_push(&stackObject, 1);
            break;

        case '{':
            Stack_push(&stackObject, 2);
            break;

        case '[':
            Stack_push(&stackObject, 3);
            break;

        case ')':
            if(Stack_is_empty(&stackObject)) return 0;
            if(Stack_peek(&stackObject) == 1) Stack_pop(&stackObject);
            else return 0;
            break;

        case '}':
            if(Stack_is_empty(&stackObject)) return 0;
            if(Stack_peek(&stackObject) == 2) Stack_pop(&stackObject);
            else return 0;
            break;

        case ']':
            if(Stack_is_empty(&stackObject)) return 0;
            if(Stack_peek(&stackObject) == 3) Stack_pop(&stackObject);
            else return 0;
            break;
        }
        string++;
    }
    if(Stack_is_empty(&stackObject)) return 1;
    return 0;

    Stack_destroy(&stackObject);
}	


//This program has been submitted by Pranav R Hegde
//PES1UG19CS343 PES1201901911 F section 
