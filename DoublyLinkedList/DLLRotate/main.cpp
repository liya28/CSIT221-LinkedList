#include <iostream>

using namespace std;

struct Node 
{
    int data;
    Node *prev;
    Node *next;
    
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyList
{
    private:
        Node *head;
        
    public:
        DoublyList() : head(nullptr) {}
        
        void addAtPos(int pos, int value)
        {
            Node *new_node = new Node(value);
            if (pos == 0)
            {
                new_node->next = head;
                if (head != nullptr)
                {
                    head->prev = new_node;
                }
                head = new_node;
                return;
            }
            
            Node *current = head;
            for (int i = 0; i < pos - 1 && current != nullptr; i++)
            {
                current = current->next;
            }
            
            if (current == nullptr)
            {
                cout << "Position out of bounds";
                delete new_node;
                return;
            }
            
            Node *next_to_current = current->next;
            
            new_node->next = next_to_current;
            new_node->prev = current;
            
            if (next_to_current != nullptr)
            {
                next_to_current->prev = new_node;
            }
            current->next = new_node;
        }
        
        void printList()
        {
            Node *current = head;
            while (current != nullptr)
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
        
        void deleteNode(int pos)
        {
            Node *to_delete = nullptr;
            if (pos == 0)
            {
                if (head == nullptr)
                {
                    cout << "List is empty. Nothing to delete";
                    return;
                }
                
                to_delete = head;
                head = head->next;
                
                if (head != nullptr)
                {
                    head->prev = nullptr;
                }
                
                delete to_delete;
                return;
            }
            
            Node *current = head;
            for (int i = 0; i < pos && current != nullptr; i++)
            {
                current = current->next;
            }
            
            to_delete = current;
            
            if (current->prev != nullptr)
                to_delete->prev->next = to_delete->next;
            
            if (current->next != nullptr)
                to_delete->next->prev = to_delete->prev;
            
            delete to_delete;
        }
        
        void reverseList()
        {
            Node *current = head;
            Node *prev = nullptr;
            
            while (current != nullptr)
            {
                Node *next = current->next;
                
                current->next = prev;
                current->prev = next;
                
                prev = current;
                current = next;
            }
            
            head = prev;
        }
        
        void concatenateLists(DoublyList &other)
        {
            if (head == nullptr)
            {
                head = other.head;
                return;
            }
            
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            
            current->next = other.head;
            
            if (other.head != nullptr)
            {
                other.head->prev = current;
            }
            
            other.head = nullptr; // optional
        }
        
        void swapAdjacent()
        {
            Node *current = head;
            while (current != nullptr && current->next != nullptr)
            {
                Node *next = current->next;
                Node *prev = current->prev;
                Node *nextNext = next->next;
                
                if (prev == nullptr)
                {
                    head = next;
                }
                else
                {
                    prev->next = next;
                }
                
                next->prev = prev;
                next->next = current;
                
                current->prev = next;
                current->next = nextNext;
                
                if (nextNext != nullptr)
                {
                    nextNext->prev = current;
                }
                
                current = current->next;
            }
        }
        
        void rotateRight(int k)
        {
            if (head == nullptr || k == 0)
            {
                return;
            }
            
            Node *current = head;
            int length = 1;
            while (current->next != nullptr)
            {
                current = current->next;
                length++;
            }
            
            Node *last = current;
            
            k = k % length;
            if (k == 0)
            {
                return;
            }
            
            int steps_to_new_head = length - k;
            current = head;
            
            for (int i = 0; i < steps_to_new_head - 1; i++)
            {
                current = current->next;
            }
            
            Node *new_head = current->next;
            current->next = nullptr;
            current->prev = nullptr;
            
            last->next = head;
            head->prev = last;
            
            head = new_head;
        }
};

// 1 2 3 

// 4 5 k = 2
// new_head = 4
// last = 5

int main()
{
    DoublyList myList1;
    
    myList1.addAtPos(0, 10);
    myList1.addAtPos(1, 15);
    myList1.addAtPos(2, 20);
    myList1.addAtPos(3, 25);
    
    // DoublyList myList2;
    
    // myList2.addAtPos(0, 10);
    // myList2.addAtPos(1, 15);
    // myList2.addAtPos(2, 20);
    
    cout << "Original list: ";
    myList1.printList();
    
    myList1.rotateRight(2);
    cout << "After rotating to right: ";
    myList1.printList();
    
    return 0;
}
