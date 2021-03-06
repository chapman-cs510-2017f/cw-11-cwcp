#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

SVALUE SVALUE_ERR = -9999;
STACK new_stack() {
    STACK new = NULL;
    return new;
}

void push_stack(STACK *s, SVALUE val) {
    STACK new = (STACK) malloc(sizeof(struct stack));
    if (new == NULL) {
        fprintf(stderr, "ERROR: Unable to push onto stack\n");
        return;
    }
    //set the data value to val
    new->data = val;
    //set the new pointer to *s
    new->head = *s;
    //now the current pointer is the new stack pointer
    *s = new;
}

SVALUE pop_stack(STACK *s) {
    SVALUE val;
    STACK temp;
    //if there's no other values, then stop, you're being ridiculous
    if (*s == NULL) {
      fprintf(stderr, "ERROR: Attempt to pop value from empty stack\n");
      val = SVALUE_ERR;
    }
    //otherwise...
    else {
      //store the value of the latest pointer
      val = (*s)->data;
      //store the pointer
      temp = (*s);
      //set the pointer to the previous point
      *s = (*s)->head;
      //get rid of temp, we don't need this anymore.
      free(temp);
    }
    //return the formerly top  value
    return val;
}

// Printer for svalue
void print_svalue(SVALUE a){
    printf("%d", a);
}

// Printer for stack
void print_stack(STACK s){
    STACK temp;
    temp = s;
    while (temp != NULL){
    SVALUE a;
    a = pop_stack(&temp);
    print_svalue(a);
    }
}