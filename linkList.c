#include <stdlib.h>
#include <stdio.h>

void stackMode();
void pushValue(int value);
void insertSorted(int value);
void printList();

typedef struct node {
    int value;
    struct node *next;
} node_t;

node_t *head;

int main(int argc, char *args[]) {

    int userValue;
    int result;
    
    head = NULL;

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
                printf("Queue Mode not yet set up\n\n");
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

void stackMode() {

    int userValue;
    int result;

    while (1) {

        printf("Please select an operation:\n\n");
        printf("1: Push value on to stack\n");
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
                printList(mode);
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
                pushValue(userValue);
                printf("Value %d pushed on to stack.\n\n", userValue);
                break;
            default:
                printf("\n");
                printf("Invalid option. Please enter a number from above.\n");
                printf("\n");
        }
    }
}

void pushValue(int value) {

    node_t *newnode = malloc(sizeof(node_t));

    if (newnode == NULL) {
        exit(1);
    }

    newnode->value = value;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }
}

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
