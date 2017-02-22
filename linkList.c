#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void stackMode();

node_t *head;
node_t *tail;

int main(int argc, char *args[]) {

    int userValue;
    int result;
    
    head = NULL;
    tail = NULL;

    printf("Welcome to linkList.c\n\n");

    while (1) {

        printf("Please select what type of list you would like to create.\n\n");
        printf("1: Stack - Last-In, First-Out Structure\n");
        printf("2: Queue - First-In, First-Out Structure\n");
        printf("3: Ordered - Lowest Integer Value to Highest\n");
        printf("4: Ordered - Highest Integer Value to Lowest\n");

        result = scanf("%d", &userValue);
        if (result == 0) {
            getchar();
            printf("\nPlease enter a number from the option menu.\n\n");
            continue;
        }

        switch (userValue) {
            case 1:
                printf("\n");
                printf("Entering Stack Mode\n");
                stackMode();
                break;
            case 2:
                printf("\n");
                //printf("Entering Queue Mode\n");
                printf("Queue Mode Disabled\n");
                //queueMode();
                break;
            case 3:
                printf("\n");
                printf("Ascending Ordered Mode not yet set up\n\n");
                break;
            case 4:
                printf("\n");
                printf("Descending Ordered Mode not yet set up\n\n");
                break;
            default:
                printf("\n");
                printf("Invalid option. Please enter a number from above.\n\n");
                printf("\n");
        } 
    }

} // main

/*------------------------- stackMode --------------------------
|
|  Purpose: Flow control for manipulating a linked list in Stack Mode
|
|  Parameters: None
|
|  Returns: None
*-------------------------------------------------------------------*/
void stackMode() {

    int userValue;  // value received from the user on stdin
    int result;     // return value from scanf

    while (1) {

        printf("Please select an operation:\n\n");
        printf("1: Push value on to stack\n");
        printf("2: Pop value off of stack\n");
        printf("0: Print stack\n");

        result = scanf("%d", &userValue);
        if (result == 0) {
            printf("stackMode: error reading user input.\n");
            continue;
        }

        switch (userValue) {
            case 0:
                printf("\n");
                char *mode = "Stack";
                printf("Printing Stack\n");
                printStack(head);
                printf("\n");
                break;
            case 1:
                printf("\n");
                printf("What value would you like to push on to the stack?\n");
                result = scanf("%d", &userValue);
                if (result == 0) {
                    printf("Invalid value.\n");
                    continue;
                }
                int pushResult;
                pushResult = pushStack(&head, userValue);
                if (pushResult == 0) {
                    printf("Error pushing value to stack... "
                           "Exiting program\n");
                    exit(1);
                }
                printf("Value %d pushed on to stack.\n\n", userValue);
                break;
            case 2:
                printf("\n");
                printf("Popping value from the stack\n");
                int popValue;
                int popResult;
                popResult = popStack(&head, &popValue);
                if (popResult == 0) {
                    printf("No values on stack to pop.\n\n");
                } else {
                    printf("Value %d popped from the stack.\n\n", popValue);
                }
                break;
            default:
                printf("\n");
                printf("Invalid option. Please enter a number from above.\n");
                printf("\n");
        }
    }
}
/*
void insertSorted(int value) {

    node_t *newNode = malloc(sizeof(node_t));
    if (newNode == NULL) {
        exit(1);
    }

    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    node_t *temp = head;

    if (temp->value > value) {
        head = newNode;
        newNode->next = temp;
        return;
    }

    while (temp->next != NULL) {
        if (temp->next->value > value) {
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }

    temp->next = newNode;
}

void queueMode() {

    int userValue;  // value received from the user on stdin
    int result;     // return value from scanf

    while (1) {

        printf("Please select an operation:\n\n");
        printf("1: Enqueue value on to queue\n");
        printf("2: Dequeue value from queue\n");
        printf("0: Print stack\n");

        result = scanf("%d", &userValue);
        if (result == 0) {
            printf("queueMode: error reading user input.\n");
            continue;
        }

        switch (userValue) {
            case 0:
                printf("\n");
                char *mode = "Queue";
                printList(mode);
                printf("\n");
                break;
            case 1:
                printf("\n");
                printf("What value would you like to enqueue?\n");
                result = scanf("%d", &userValue);
                if (result == 0) {
                    printf("Invalid value.\n");
                    continue;
                }
                enqueue(userValue);
                printf("Value %d enqueued.\n\n", userValue);
                break;
            case 2:
                printf("\n");
                printf("Dequeuing value\n");
                int dequeueValue;
                int dequeueResult;
                dequeueResult = dequeue(&dequeueValue);
                if (dequeueResult == 0) {
                    printf("No values on queue.\n\n");
                } else {
                    printf("Value %d dequeued.\n\n", dequeueValue);
                }
                break;
            default:
                printf("\n");
                printf("Invalid option. Please enter a number from above.\n");
                printf("\n");
        }
    }
}

void enqueue(int value) {
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->last = NULL;

    if (node == NULL) {
        fprintf(stderr, "enqueue: error allocating memory\n");
        fprintf(stderr, "Exiting linkList.c\n");
        exit(1);
    }

    if (head == NULL) {
        head = node;
        tail = node;
    } else {
        node->next = head;
        head->last = node;
        head = node;
    }
}

int dequeue(int *value) {
    if (head == NULL) {
        return 0;
    }
    
    *value = tail->value;
    node_t *temp = tail;
    
    if (head == tail) {
        head = NULL;
    } else {
        tail = temp->last;
        tail->next = NULL;
    }
    free(temp);
    return 1;
}

void printList(char *mode) {

    printf("Printing %s\n", mode);
    
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
*/
