#ifndef _STACK_H
#define _STACK_H

/* stack.h
 *
 * stack data structure using a linked list
 *
 * Type node_t has the following components:
 *      int value, struct node *next
 *
 * Operators:
 *      pushStack, popStack, printStack
 */

/* node structure: value type can be changed to hold any desired type */
typedef struct node {
    int value;                // the value of the node
    struct node *next;        // the next node in the linked list
} node_t;

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
extern int pushStack(node_t **head, int value);

/*------------------------- popStack --------------------------
|
|  Purpose: Removes the top value from the stack
|
|  Parameters:
|      head  (IN) -- first node in the stack
|      value (OUT) -- Value removed from the stack
|
|  Returns: int -- 0 if there was no node on the stack
|                  1 if the call was successful
*-------------------------------------------------------------------*/
extern int popStack(node_t **head, int *value);

/*------------------------- printStack --------------------------
|
|  Purpose: Prints to stdout a visual representation of the stack
|
|  Parameters:
|      head  (IN) -- first node in the stack.
|
|  Returns: None
*-------------------------------------------------------------------*/
extern void printStack(node_t *head);

#endif // _STACK_H
