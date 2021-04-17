#include<stdio.h>
#include<stdlib.h>
#include "tbt.h"

void tree_initialize(Tree *tree){
    //TODO
    tree->root = NULL;
}

void tree_insert(Tree *tree, int data){
     //TODO
	
    Node *newNode;
	newNode=(Node *)malloc(sizeof(Node));
	newNode->data=data;
	newNode->left=newNode->right=NULL;
	newNode->rightThread = newNode->leftThread = 1;
	
	if(tree->root == NULL) tree->root = newNode;

	Node* iterNode;
	iterNode = tree->root;
	while(1){
		if(data < iterNode->data){
			if(!iterNode->leftThread) iterNode=iterNode->left;
			else break;
			
		}
		else {
			if(iterNode->rightThread==0) iterNode=iterNode->right;
			else break;
		}
		
	}
	if(data < iterNode->data){
		newNode->left = iterNode->left;
		iterNode->left = newNode;
		iterNode->leftThread = 0;
		newNode->right = iterNode;
	}
	else{
        if(data>iterNode->data){
            newNode->right = iterNode->right;
            iterNode->right = newNode;
            iterNode->rightThread = 0;
            newNode->left = iterNode;
	    }
    }
}

Node *inorder_predecessor(Node *ptr){
    //TODO
    if(ptr->leftThread==1) return ptr = ptr->left;
	ptr = ptr->left;
	while(ptr->rightThread==0) ptr=ptr->right;
    return ptr;
}

Node *inorder_successor(Node *ptr){
   //TODO
    if(ptr->rightThread==1) return ptr=ptr->right;
	ptr=ptr->right;
	while(ptr->leftThread==0) ptr=ptr->left;
    return ptr;
}

void print_ascending(Tree *tree){

    if (tree->root == NULL){
        printf("Empty\n");
        return;
    }

	else{
        Node* iterNode;
		iterNode=tree->root;
		while(!iterNode->leftThread) iterNode=iterNode->left;

		while(iterNode!=NULL){
			printfun(iterNode->data);
			iterNode = inorder_successor(iterNode);
		}
	}
	nextline();
    // TODO : Use printf() specified in tbtmain.c . Dont use printf statement
}

void print_descending(Tree *tree){
    if (tree->root == NULL){
        printf("Empty\n");
        return;
    }
    // TODO : Use printf() specified in tbtmain.c . Dont use printf statement  
	else{
		Node* iterNode;
        iterNode = tree->root;
		while(!iterNode->rightThread) iterNode = iterNode->right;
		
		while(iterNode !=NULL){
			printfun(iterNode ->data);
			iterNode =inorder_predecessor(iterNode );
		}
	}
	nextline();
}

void destroy(Node *r){
    //TODO
    if(r == NULL) return;
    r = r->left;
    r = r->right;
    free(r);
}

void tree_destroy(Tree *t){
    destroy(t->root);
}
