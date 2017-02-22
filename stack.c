#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

/*------------------------- pushStack --------------------------
|
|  Purpose: Adds a value to the top of the stack.
|
|  Parameters:
|      head  (IN) -- Reference to the stack. Should reference a NULL pointer
|                    when adding a node for the first time
|      value (IN) -- Value to add to the stack
|
|  Returns: int -- 0 if allocation of node returned an error
|                  1 if value was successfully placed on the stack     
*-------------------------------------------------------------------*/
int pushStack(node_t **head, int value) {
    
	node_t *newNode = malloc(sizeof(node_t));

    if (newNode == NULL) {
		return 0;
    }

    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
    return 1;
}

/*------------------------- popStack --------------------------
|
|  Purpose: Removes the top value from the stack
|
|  Parameters:
|      head  (IN) -- first node in the stack
|      value (OUT) -- Value removed from the stack
|
|  Returns: int -- 0 if there was no node on the stack
|				   1 if value was successfully removed from the stack
*-------------------------------------------------------------------*/
int popStack(node_t **head, int *value) {

    if (*head == NULL) {
        return 0;
    }

    *value = (*head)->value;

    node_t *temp = (*head)->next;
    free(*head);
    *head = temp;

    return 1;
}

/*------------------------- printStack --------------------------
|
|  Purpose: Prints to stdout a visual representation of the stack
|
|  Parameters:
|      head  (IN) -- first node in the stack.
|
|  Returns: None
*-------------------------------------------------------------------*/
void printStack(node_t *head) {

    node_t *temp = head;

    while (temp != NULL) {
        printf("%d", temp->value);
        if (temp->next == NULL) {
            break;
        }   
        printf("->");
        temp = temp->next;
    }   
    printf("\n");
}
