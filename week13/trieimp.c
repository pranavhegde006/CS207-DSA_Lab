#include<stdio.h>
#include "trie.h"

struct trienode *getnode(){
   struct trienode *temp =(struct trienode*)malloc(sizeof(struct trienode));
   for(int i=0;i<26;i++) temp->child[i]=NULL;
   temp->endofword=0;
   return temp;
}

int search(struct trienode * root,char *key){
    int index;
    struct trienode *curr = root;
    for(int i = 0; key[i] != '\0'; i++){
        index=key[i]-'a';
        if(curr->child[index]==NULL)
            return 0;
        curr=curr->child[index];
    }
    if(curr->endofword==1) return 1;
    return 0;
}

void display(struct trienode *curr){
    int i,j;
    for(i=0;i<26;i++){
        if(curr->child[i]!=NULL){
            word[length++]=i+97;
            if(curr->child[i]->endofword==1){
                printf("\n");
                for(j=0;j<length;j++) printf("%c",word[j]);
            }
            display(curr->child[i]);
        }
    }
    length--;
    return;
}

void insert(struct trienode * root, char *key){
    int index;
    struct trienode *curr = root;

    for(int i=0;key[i]!='\0';i++){
        index=key[i]-'a';
        if(curr->child[index]==NULL) curr->child[index]=getnode();
        curr=curr->child[index];
    }
    curr->endofword=1;
}


void delete_trie(struct trienode *root,char *key){
    int j,index,flag;
    struct trienode* curr=root;
    flag=1;

    for(int i=0;key[i]!='\0';i++){
        index=key[i]-'a';
        if(curr->child[index]==NULL) return;
        curr=curr->child[index];
    }
        curr->endofword=0;
        return;
}
