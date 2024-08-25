#include <stdio.h>
#include <stdlib.h>

// Self-referential structure for doubly linked list node
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to display the list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to insert a node at the end
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to insert a node at any position
void insertAtPosition(Node** head, int data, int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning(head, data);
        return;
    }

    Node* newNode = createNode(data);
    Node* temp = *head;
    int i = 1;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Function to delete a node at the beginning
void deleteAtBeginning(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Function to delete a node at the end
void deleteAtEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}

// Function to delete a node at any position
void deleteAtPosition(Node** head, int pos) {
    if (pos < 1 || *head == NULL) {
        printf("Invalid position or list is empty\n");
        return;
    }

    if (pos == 1) {
        deleteAtBeginning(head);
        return;
    }

    Node* temp = *head;
    int i = 1;
    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

// Function to count the total number of nodes
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to search for an element in the linked list
void searchElement(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found in the list\n", key);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found in the list\n", key);
}

// Main function to provide menu-driven operations
int main() {
    Node* head = NULL;
    int choice;
    while (1) {
        printf("Doubly Linked List Operations\n");
        printf("1. Create List (Add Node)\n");
        printf("2. Display List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Position\n");
        printf("6. Delete at Beginning\n");
        printf("7. Delete at End\n");
        printf("8. Delete at Position\n");
        printf("9. Count Nodes\n");
        printf("10. Search Element\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Use Insert operations to add nodes.\n");
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                {
                    int data;
                    printf("Enter data to insert at beginning: ");
                    scanf("%d", &data);
                    insertAtBeginning(&head, data);
                }
                break;
            case 4:
                {
                    int data;
                    printf("Enter data to insert at end: ");
                    scanf("%d", &data);
                    insertAtEnd(&head, data);
                }
                break;
            case 5:
                {
                    int pos, data;
                    printf("Enter position to insert: ");
                    scanf("%d", &pos);
                    printf("Enter data to insert: ");
                    scanf("%d", &data);
                    insertAtPosition(&head, data, pos);
                }
                break;
            case 6:
                deleteAtBeginning(&head);
                break;
            case 7:
                deleteAtEnd(&head);
                break;
            case 8:
                {
                    int pos;
                    printf("Enter position to delete: ");
                    scanf("%d", &pos);
                    deleteAtPosition(&head, pos);
                }
                break;
            case 9:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
            case 10:
                {
                    int key;
                    printf("Enter element to search: ");
                    scanf("%d", &key);
                    searchElement(head, key);
                }
                break;
            case 11:
                // Free all remaining nodes before exiting
                while (head != NULL) {
                    deleteAtBeginning(&head);
                }
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

