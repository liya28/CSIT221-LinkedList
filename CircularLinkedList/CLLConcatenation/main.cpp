#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    
    Node (int value) : data(value), next(nullptr) {}
};

class Circular
{
    private:
        Node *head;
        Node *tail;
        
    public:
        Circular() : head(nullptr), tail(nullptr) {}
        
        void addAtBeginning(int value)
        {
            Node *new_node = new Node(value);
            
            if (head == nullptr)
            {
                head = new_node;
                head->next = head;
                tail = head;
                return;
            }
            
            new_node->next = head;
            tail->next = new_node;
            head = new_node;
            
            return;
        }
        
        void deleteNode(int value)
        {
            if (head == nullptr)
            {
                cout << "List is empty.";
                return;
            }
            
            Node *to_delete = nullptr;
            
            if (value == head->data)
            {
                to_delete = head;
                
                if (head == tail)
                {
                    head = nullptr;
                    tail = nullptr;
                }
                else
                {
                    tail->next = head->next;
                    head = head->next;
                }
                delete to_delete;
                return;
            }
            
            Node *prev = head;
            Node *current = head->next;
            while (current != head)
            {
                if (current->data == value)
                {
                    to_delete = current;
                    prev->next = current->next;
                    
                    if (current == tail)
                    {
                        tail = prev;
                    }
                    delete to_delete;
                    return;
                }
                prev = current;
                current = current->next;
            }
        }
        
        void splitList(Circular &firstHalf, Circular &secondHalf)
        {
            if (head == nullptr) return;
            
            Node *slow = head;
            Node *fast = head;
            
            while (fast->next != head && fast->next->next != head)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            
            // if even number of nodes
            if (fast->next->next == head)
            {
                fast = fast->next;
            }
            
            firstHalf.head = head;
            firstHalf.tail = slow;
            secondHalf.head = slow->next;
            secondHalf.tail = tail;
            
            firstHalf.tail->next = firstHalf.head;
            secondHalf.tail->next = secondHalf.head;
        }
        
        void concatenateLists(Circular &other)
        {
            if (head == nullptr) 
            {
                head = other.head;
                return;
            }
            
            tail->next = other.head;
            other.tail->next = head;
            
            return;
        }
        
        void printList()
        {
            Node *current = head;
            do
            {
                cout << current->data << " ";
                current = current->next;
            } while (current != head);
            
            cout << endl;
        }
};

int main()
{
    Circular myList;
    myList.addAtBeginning(10);
    myList.addAtBeginning(20);
    myList.addAtBeginning(30);
    myList.addAtBeginning(40);
    myList.addAtBeginning(50);
    
    cout << "Original CLL1: ";
    myList.printList();
    
    Circular myList2;
    
    myList2.addAtBeginning(60);
    myList2.addAtBeginning(70);
    myList2.addAtBeginning(80);
    myList2.addAtBeginning(90);
    myList2.addAtBeginning(100);
    
    cout << "Original CLL2: ";
    myList2.printList();
    
    myList.concatenateLists(myList2);
    
    cout << "List 1 after concatenation: ";
    myList.printList();
    
    return 0;
}

