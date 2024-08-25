#include <stdio.h>
#include <stdlib.h>

// Self-referencing structure for a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the list
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
    }
}

// Function to insert a node at a specific position in the list
void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* temp = *head;
        int i = 1;
        while (i < position - 1 && temp != NULL) {
            temp = temp->next;
            i++;
        }
        if (temp == NULL) {
            printf("Position out of range\n");
            free(newNode);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

// Function to delete a node from the beginning of the list
void deleteFromBeginning(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Function to delete a node from the end of the list
void deleteFromEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        Node* temp = *head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

// Function to delete a node from a specific position in the list
void deleteFromPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else if (position == 1) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    } else {
        Node* temp = *head;
        int i = 1;
        while (i < position - 1 && temp != NULL) {
            temp = temp->next;
            i++;
        }
        if (temp == NULL || temp->next == NULL) {
            printf("Position out of range\n");
        } else {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            free(nodeToDelete);
        }
    }
}

// Function to display the list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        while (head != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

// Function to count the total number of nodes in the list
int countNodes(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to search for an element in the list
int searchElement(Node* head, int element) {
    int position = 1;
    while (head != NULL) {
        if (head->data == element) {
            return position;
        }
        head = head->next;
        position++;
    }
    return -1;
}

int main() {
    Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a list\n");
        printf("2. Display the list\n");
        printf("3. Insert a node\n");
        printf("4. Delete a node\n");
        printf("5. Count the total number of nodes\n");
        printf("6. Search for an element\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Create a list
                {
                    int numNodes;
                    printf("Enter the number of nodes: ");
                    scanf("%d", &numNodes);
                    for (int i = 0; i < numNodes; i++) {
                        printf("Enter data for node %d: ", i + 1);
                        scanf("%d", &data);
                        insertAtEnd(&head, data);
                    }
                }
                break;
            case 2:
                // Display the list
                displayList(head);
                break;
            case 3:
                // Insert a node
                printf("1. Insert at Beginning\n");
                printf("2. Insert at End\n");
                printf("3. Insert at Position\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                printf("Enter data: ");
                scanf("%d", &data);
                if (choice == 1) {
                    insertAtBeginning(&head, data);
                } else if (choice == 2) {
                    insertAtEnd(&head, data);
                } else if (choice == 3) {
                    printf("Enter position: ");
                    scanf("%d", &position);
                    insertAtPosition(&head, data, position);
                } else {
                    printf("Invalid choice\n");
                }
                break;
            case 4:
                // Delete a node
                printf("1. Delete from Beginning\n");
                printf("2. Delete from End\n");
                printf("3. Delete from Position\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                if (choice == 1) {
                    deleteFromBeginning(&head);
                } else if (choice == 2) {
                    deleteFromEnd(&head);
                } else if (choice == 3) {
                    printf("Enter position: ");
                    scanf("%d", &position);
                    deleteFromPosition(&head, position);
                } else {
                    printf("Invalid choice\n");
                }
                break;
            case 5:
                // Count the total number of nodes
                printf("Total number of nodes: %d\n", countNodes(head));
                break;
            case 6:
                // Search for an element
                printf("Enter element to search: ");
                scanf("%d", &data);
                position = searchElement(head, data);
                if (position != -1) {
                    printf("Element found at position %d\n", position);
                } else {
                    printf("Element not found in the list\n");
                }
                break;
            case 7:
                // Exit
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    printf("TEst print ");
    return 0;
}