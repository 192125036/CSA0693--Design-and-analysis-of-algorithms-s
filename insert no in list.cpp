#include <stdio.h>
#include <stdlib.h>

// Node structure for a singly linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to insert a number at the beginning of the list
struct Node* insertAtBeginning(struct Node *head, int num) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = head;
    return newNode;
}

// Function to display the linked list
void displayList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;

    int num;
    printf("Enter a number to insert at the beginning of the list: ");
    scanf("%d", &num);

    head = insertAtBeginning(head, num);

    printf("List after insertion:\n");
    displayList(head);

    return 0;
}
