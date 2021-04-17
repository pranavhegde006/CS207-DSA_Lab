void position_delete(List* cll, int pos){

    if(pos >= cll->length && pos < 0 && cll->length == 0){
        return;
    }

    else if(pos == 0){
        Node* delNode = (Node*)malloc(sizeof(Node));
        Node* newHeadNode = (Node*)malloc(sizeof(Node));
        delNode = cll->head;
        newHeadNode = cll->head->next;
        cll->head = newHeadNode;
        cll->tail->next = newHeadNode;
        cll->length--;
        free(delNode);
    }

    else if(pos == cll->length - 1){
        Node* delNode = (Node*)malloc(sizeof(Node));
        delNode = cll->tail;
        Node* iteratorNode = (Node*)malloc(sizeof(Node));
        for(int i = 0; i < cll->length - 2; i++){
            iteratorNode = iteratorNode->next;
        }
        iteratorNode->next = cll->head;
        cll->tail = iteratorNode;
        free(delNode);        
        cll->length--;
    }

    else{
        Node* iteratorNode = (Node*)malloc(sizeof(Node));
        Node* delNode = (Node*)malloc(sizeof(Node));
        iteratorNode = cll->head;
        int count = 0;
        while(count != pos - 1){
            iteratorNode = iteratorNode->next;
            count++;
        }
        delNode = iteratorNode->next;
        iteratorNode->next = delNode->next;
        free(delNode);
        cll->length--;
    }

}