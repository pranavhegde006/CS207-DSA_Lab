#include<stdio.h>
#include "bst.h"

//PRANAV R HEGDE
//PES1201901911
//PES1UG19CS343
//F SECTION

void tree_initialize(Tree *tree){
    //TODO 
    tree->root = NULL;
}

void tree_insert(Tree *tree, int data){
    // TODO : Insert element to create a BST
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data; 
    newNode->left = NULL;
    newNode->right = NULL;

    if(tree->root == NULL){
        tree->root = newNode;
        return;
    } 

    Node *firstIter, *secondIter;
    firstIter = tree->root;
    secondIter = NULL;

    while(firstIter != NULL){
        secondIter = firstIter;
        if(data < firstIter->data) firstIter = firstIter->left;
        else firstIter = firstIter->right;
    }    

    if(data < secondIter->data) secondIter->left = newNode;
    else secondIter->right = newNode;
    return;
}

Node* recursiveDeleteTree(Node* delNode, int element);

Node* recursiveDeleteTree(Node* delNode, int element) { 
    Node* firstIter = delNode; 
    Node* secondIter = NULL; 
   
    while (firstIter->data != element && firstIter != NULL) { 
        secondIter = firstIter; 
        if (element < firstIter->data) firstIter = firstIter->left; 
        else firstIter = firstIter->right; 
    } 
  
    if (firstIter == NULL) return delNode; 
  
    if (firstIter->left == NULL || firstIter->right == NULL) { 
        Node* newfirstIter; 
        if (firstIter->left == NULL) newfirstIter = firstIter->right; 
        else newfirstIter = firstIter->left; 
  
        if (secondIter == NULL) return newfirstIter; 
        if (firstIter == secondIter->left) secondIter->left = newfirstIter; 
        else secondIter->right = newfirstIter; 
        free(firstIter); 
    } 
  
    else{ 
        Node *current, *delNode;
 
        current = NULL;
        delNode = firstIter->right; 

        while (delNode->left != NULL) { 
            current = delNode; 
            delNode = delNode->left; 
        }

        if(current == NULL) firstIter->right = delNode->right; 
        else if (current != NULL) current->left = delNode->right; 
  
        firstIter->data = delNode->data; 
        free(delNode); 
    } 
    return delNode; 
} 

void tree_delete(Tree *tree, int element){
    // TODO : Delete elements from BST
    tree->root = recursiveDeleteTree(tree->root, element);
}

void tree_inorder(Node *r){
    //TODO :  use printf to print inorder 
    if(r != NULL){
        tree_inorder(r->left);
        printf("%d ", r->data);
        tree_inorder(r->right);
    }   
}

void tree_preorder(Node *r){
    //TODO :  use printf to print preorder
    if(r != NULL){
        printf("%d ", r->data);
        tree_preorder(r->left);
        tree_preorder(r->right);
    } 
}

void tree_postorder(Node *r){
    //TODO :  use printf to print postorder
    if(r != NULL){
        tree_postorder(r->left);
        tree_postorder(r->right);
        printf("%d ", r->data);
    } 
}

void postorder(Tree *t){
    //TODO
    tree_postorder(t->root);
    printf("\n");
}

void preorder(Tree *t){
    //TODO
    tree_preorder(t->root);
    printf("\n");
}

void inorder(Tree *t){
    //TODO   
    tree_inorder(t->root);
    printf("\n");
}

void destroy(Node *r){
    //TODO
    if(r == NULL) return;
    destroy(r->left);
    destroy(r->right); 
    free(r); 
}

void tree_destroy(Tree *t){ 
    //TODO
    destroy(t->root);
}
