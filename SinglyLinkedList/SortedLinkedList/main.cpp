#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printLinkedList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void insertAtEnd(Node** head_ref, int data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    Node* curr = *head_ref;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
}

void swapData(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSort(Node* head) {
    int swapped;
    Node* curr;
    Node* last = NULL;

    if (head == NULL) {
        return;
    }

    do {
        swapped = 0;
        curr = head;

        while (curr->next != last) {
            if (curr->data > curr->next->data) {
                swapData(curr, curr->next);
                swapped = 1;
            }
            curr = curr->next;
        }
        last = curr;
    } while (swapped);
}

int main() {
    Node* head = NULL;

    // Create linked list
    int size, data;
    cout << "Enter size of linked list: ";
    cin >> size;

    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i+1 << ": ";
        cin >> data;
        insertAtEnd(&head, data);
    }

    // Print original linked list
    cout << "Original linked list: ";
    printLinkedList(head);

    // Sort linked list using bubble sort
    bubbleSort(head);

    // Print sorted linked list
    cout << "Sorted linked list: ";
    printLinkedList(head);

    return 0;
}
