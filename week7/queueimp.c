#include "queue.h"

static node *create_node(int id, int time, node *link){
	//creates a new node and enters the given info
	node* newNode = (node*)malloc(sizeof(node));
	newNode->id = id;
	newNode->time = time;
	newNode->link = link;
	return newNode;
}

void list_initialize(List *ptr_list){
	//Initialises the list by setting the required list parameters to NULL
	ptr_list->head = NULL;
	ptr_list->tail = NULL;
	ptr_list->number_of_nodes = 0;
}

const int node_get_id(node *node_ptr){
	//returns the ID of the given node
	return node_ptr->id;
}

const int node_get_time(node *node_ptr){
	//returns the time of a given node		
	return node_ptr->time;
}

void list_insert_rear(List *ptr_list, int id, int time){
	//Inserts the given element to the rear of the list
	node* newLastNode = (node*)malloc(sizeof(node));
	newLastNode->id = id;
	newLastNode->time = time;
	newLastNode->link = NULL;

	if(ptr_list->number_of_nodes == 0){
		ptr_list->head = newLastNode;
	}

	if(ptr_list->number_of_nodes != 0){
		node* lastNode = (node*)malloc(sizeof(node));
		lastNode = ptr_list->tail;
		lastNode->link = newLastNode;
	}
	
	ptr_list->tail = newLastNode;
	ptr_list->number_of_nodes++;
}

void list_delete_front(List *ptr_list){
	//Deletes the head element of the given list
	if(ptr_list->head != NULL){
		node* deleteNode = (node*)malloc(sizeof(node));
		deleteNode = ptr_list->head;
		ptr_list->head = deleteNode->link;
		free(deleteNode);
		ptr_list->number_of_nodes--;
	}
}

void list_destroy(List *ptr_list){
	//Deletes the given list and frees the memory allocated
	node* freeNode = (node*)malloc(sizeof(node));
	node* iteratorNode = (node*)malloc(sizeof(node));
	iteratorNode = ptr_list->head;
	freeNode = NULL;
	for(int i = 0; i < ptr_list->number_of_nodes; i++){
		freeNode = iteratorNode;	
		iteratorNode = iteratorNode->link;
		free(freeNode);
	}
	free(ptr_list);
}

void queue_initialize(Queue *queue_list){
	//Initialises the given queue
	queue_list->ptr_list = (List*)malloc(sizeof(List));
	list_initialize(queue_list->ptr_list);
}

void queue_enqueue(Queue *ptr, int id, int time){
	//adds the given element to the queue	
	list_insert_rear(ptr->ptr_list, id, time);	
}

void queue_dequeue(Queue *ptr){
	//pops the element from the given queue	
	if(!queue_is_empty(ptr)) list_delete_front(ptr->ptr_list);
}

int queue_is_empty(Queue *ptr){
	//checks if the given queue is empty		
	if(ptr->ptr_list->number_of_nodes == 0) return 1;
	return 0;
}

void queue_peek(Queue *ptr){
	//peeks at the topmost element of the queue	
	if(ptr->ptr_list->number_of_nodes == 0){
		printf("Empty queue\n");
	}
	else printf("%d %d\n", ptr->ptr_list->head->id, ptr->ptr_list->head->time);
}

void queue_destroy(Queue *ptr){
	//Destroys the given queue by freeing the memory allocated	
	list_destroy(ptr->ptr_list);
}

const int queue_find_person(Queue *ptr_queue, int t){
	//solves the customer at the bank problem using queue data structure	
	
	if(queue_is_empty(ptr_queue)) printf("Empty Queue\n"); 

	else{
		node* iteratorNode = (node*)malloc(sizeof(node));
		node* recedingNode = (node*)malloc(sizeof(node));
		iteratorNode = ptr_queue->ptr_list->head;
		recedingNode = NULL;
		int timeElapsed = 0;
		int id = 0;

		while(timeElapsed <= t && iteratorNode != NULL){
			recedingNode = iteratorNode;
			timeElapsed += node_get_time(iteratorNode);
			id = node_get_id(iteratorNode);
				
			iteratorNode = iteratorNode->link;
			if(timeElapsed <= t){
				queue_dequeue(ptr_queue);
			}
		}

		if(queue_is_empty(ptr_queue)){
			printf("Empty Queue\n");
			return 404;
		} 

		printf("%d\n", recedingNode->id);
		return recedingNode->id;
	}
}


//pranav R Hegde
//pES1UG19CS343
//pES1201901911
//F Section
//Week 7 Lab program