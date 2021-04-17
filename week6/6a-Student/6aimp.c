#include "6a.h"

static Node* create_Node(int data, Node* link) {
	// allocates memory for a node and fills in the values
	Node* temp =  (Node*)malloc(sizeof(Node));
	temp -> data = data; 
	temp -> link = link;
	return temp;
}

void List_initialize(List* ptr_List) {
	//Initialises the given list
	ptr_List->head = NULL;
	ptr_List->number_of_Nodes = 0;
}

void List_insert_front(List* ptr_List, int data) {
	//inserts the given element in front of the list
	Node* newHeadNode = (Node*)malloc(sizeof(Node));
	Node* temp = (Node*)malloc(sizeof(Node));
	temp = ptr_List->head;
	newHeadNode = create_Node(data, temp);
	ptr_List->number_of_Nodes++;
	ptr_List->head = newHeadNode;
}

const int Node_get_data(Node *Node_ptr) {
	//returns the data in a given node
	return Node_ptr->data;
}

void List_delete_front(List* ptr_List){
	//deletes the frontmost element in the list
	if(ptr_List->head != NULL){
		Node* delNode = (Node*)malloc(sizeof(Node));
		delNode = ptr_List->head;
		ptr_List->head = delNode->link;
		free(delNode);
		ptr_List->number_of_Nodes--;
	}
}

void List_destroy(List* ptr_List) {
	//destroys the given list by deallocating the memory
	Node* delAllNodes = (Node*)malloc(sizeof(Node));
	Node* iteratorNode = (Node*)malloc(sizeof(Node));
	iteratorNode = ptr_List->head;
	delAllNodes = NULL;
	for(int i = 0; i < ptr_List->number_of_Nodes; i++){
		delAllNodes = iteratorNode;
		iteratorNode = iteratorNode->link;
		free(delAllNodes);
	}
	free(ptr_List);
}

void stack_initialize(Stack *ptr_stack) {
	//initialises the given stack object
	ptr_stack->ptr_List = (List*)malloc(sizeof(List));
	List_initialize(ptr_stack->ptr_List);
}

void stack_push(Stack *ptr_stack, int key){
	//pushes the given element to stack object
	List_insert_front(ptr_stack->ptr_List, key);
}

void stack_pop(Stack *ptr_stack) {
	//pops the element from stack object
	List_delete_front(ptr_stack->ptr_List);
}

int stack_is_empty(Stack *ptr_stack) {
	//checks whether the stack object is empty
	if(ptr_stack->ptr_List->number_of_Nodes == 0) return 1;
	return 0;
}

const int stack_peek(Stack *ptr_stack){
	//returns the topmost element of a stack
	return Node_get_data(ptr_stack->ptr_List->head);
}

void stack_destroy(Stack *ptr_stack) {
	//destroys the given stack object by deallocating the memory
	List_destroy(ptr_stack->ptr_List);
}

int postfix_eval(const char* expression){
	// returns the result of the given postfix expression

	Stack stackOps;
	stack_initialize(&stackOps);
	int a = 0, b = 0;

	while(*(expression) != '\0'){
		switch (*expression){
			case '+':
				a = stack_peek(&stackOps);
				stack_pop(&stackOps);
				b = stack_peek(&stackOps);
				stack_pop(&stackOps);
				stack_push(&stackOps, a + b);
				break;
			
			case '-':
				a = stack_peek(&stackOps);
				stack_pop(&stackOps);
				b = stack_peek(&stackOps);
				stack_pop(&stackOps);
				stack_push(&stackOps, b - a);
				break;

			case '*':
				a = stack_peek(&stackOps);
				stack_pop(&stackOps);
				b = stack_peek(&stackOps);
				stack_pop(&stackOps);
				stack_push(&stackOps, a * b);
				break;

			case '/':
				a = stack_peek(&stackOps);
				stack_pop(&stackOps);
				b = stack_peek(&stackOps);
				stack_pop(&stackOps);
				stack_push(&stackOps, (int)b/a);
				break;

			default:
				stack_push(&stackOps, (int)(*expression) - (int)'0');
				break;
		}
		expression++;
	}
	
	int final = stack_peek(&stackOps);
	stack_pop(&stackOps);
	stack_destroy(&stackOps);
	return final;
}

//Pranav R Hegde 
// PES1UG19CS343
// F section
// PES1201901911
