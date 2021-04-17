#include "et.h"


Node * createExpressionTree(char* a,int len){
    //TODO
    Node* headNode = (Node*)malloc(sizeof(Node));
    Node* stack[100];
    int top = -1;

    for(int i = 0; i < len; i++){
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = a[i];
        newNode->left = newNode->right = newNode->prev = NULL;
        if(a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/'){
            newNode->right = stack[top];
            top--;
            newNode->left = stack[top];
            top--;
        }
        top++;
        stack[top] = newNode;
    }

    headNode = stack[top];
    top = -1;
    return headNode;
}


void inorder(Node *root){
    //TODO 
    // Note : Do not change the printf
    if(root == NULL) return;
    inorder(root->left);
    printf("%c",root->data);
    inorder(root->right);
}


void preorder(Node *root){
    //TODO 
    // Note : Do not change the printf
    if(root == NULL) return;
    printf("%c",root->data);
    preorder(root->left);
    preorder(root->right);
}


void postorder(Node *root){
    //TODO 
    // Note : Do not change the printf
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c",root->data);
}


void freeTree(Node *root){
    if(root == NULL) return;
    freeTree(root->left);
    free(root);
    freeTree(root->right);
}


//this code snippet is submitted by PRANAV R HEGDE
//PES1UG19CS343
//PES1201901911
//F section