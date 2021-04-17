#include "6b.h"

stack* stack_initialize(int size){
    //TODO
    stack *stackObj = (stack*)malloc(sizeof(stack));
    stackObj->arr = (int*)malloc(sizeof(int) * size);
    stackObj->top = -1;
    return stackObj;
}

void stack_push(stack *ptr_stack, int key) {
    //TODO
    ptr_stack->top++;
    ptr_stack->arr[ptr_stack->top] = key;
}

void stack_pop(stack *ptr_stack){
    //TODO
    ptr_stack->arr[ptr_stack->top] = 0;
    ptr_stack->top--;
}

int stack_is_empty(stack *ptr_stack){
    //TODO
    if(ptr_stack->top == -1) return 1;
    return 0;
}

int stack_peek(stack *ptr_stack) {
    //TODO
    return ptr_stack->arr[ptr_stack->top];
}

void stack_destroy(stack *ptr_stack) {
    //TODO
    free(ptr_stack);
}

void convert_infix_to_postfix(const char * source_infix, char * target_postfix)
{
    stack * stackOps;
    int strLen = strlen(source_infix);
    char oper;
    stackOps = stack_initialize(strLen);
    int len = 0;

    for (int i = 0; i < strLen; i++){
        oper = source_infix[i];

        if(oper == '(' || oper == '[' || oper == '{'){
            stack_push(stackOps, oper);
        }

        if(oper == ')'){
            while ((stack_peek(stackOps) != '(') && !stack_is_empty(stackOps)){
                target_postfix[len++] = stack_peek(stackOps);
                stack_pop(stackOps);
            }
            stack_pop(stackOps);
        }

        if(oper == '}'){
            while ((stack_peek(stackOps) != '{') && !stack_is_empty(stackOps)){
                target_postfix[len++] = stack_peek(stackOps);
                stack_pop(stackOps);
            }
            stack_pop(stackOps);
        }

        if(oper == ']'){
            while ((stack_peek(stackOps) != '[') && !stack_is_empty(stackOps)){
                target_postfix[len++] = stack_peek(stackOps);
                stack_pop(stackOps);
            }
            stack_pop(stackOps);
        }

        if(oper == '+' || oper == '-'){
            while (!stack_is_empty(stackOps) && ((stack_peek(stackOps) == '+') || (stack_peek(stackOps) == '-') || (stack_peek(stackOps) == '/') || (stack_peek(stackOps) == '*'))){
                target_postfix[len++] = stack_peek(stackOps);
                stack_pop(stackOps);
            }
            stack_push(stackOps, oper);
        }

        if(oper == '*' || oper == '/'){
            while (!stack_is_empty(stackOps) && (stack_peek(stackOps) == '*' || stack_peek(stackOps) == '/')){
                target_postfix[len++] = stack_peek(stackOps);
                stack_pop(stackOps);
            }
            stack_push(stackOps, oper);
        }

        if(oper <= (int)'z' && oper >= (int)'a'){
            target_postfix[len++] = oper;
        }

    }

    while (!stack_is_empty(stackOps)){
        target_postfix[len++] = stack_peek(stackOps);
        stack_pop(stackOps);
    }
    target_postfix[len] = '\0';
    stack_destroy(stackOps);
}
