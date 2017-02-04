#include <stdlib.h>
#include <stdio.h>

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

        printf("Please select an option.\n");
        printf("0: Print list.\n");
        printf("1: Push value on to list.\n");
        printf("2: Insert value into sorted position in list.\n");

        result = scanf("%d", &userValue);
        if (result == 0) {
            printf("Error reading user input.\n");
            continue;
        }

        switch (userValue) {
            case 0:
                printf("\n");
                printList();
                printf("\n");
                break;
            case 1:
                printf("\n");
                printf("What value would you like to push on to the list?\n");
                result = scanf("%d", &userValue);
                if (result == 0) {
                    printf("Invalid value.\n");
                    continue;
                }
                pushValue(userValue);
                printf("Value %d pushed on to list.\n\n", userValue);
                break;
            case 2:
                printf("\n");
                printf("What value would you like to insert in the list?\n");
                result = scanf("%d", &userValue);
                if (result == 0) {
                    printf("Invalid value.\n");
                    continue;
                }
                insertSorted(userValue);
                printf("Value %d inserted in the list.\n\n", userValue);
                break;
            default:
                printf("\n");
                printf("Invalid option. Please enter a number from above.\n");
                printf("\n");
        } 
    }

} // main

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


void printList() {

    printf("Printing list\n");
    
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
