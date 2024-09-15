#include <iostream>

using namespace std;

struct Node 
{
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList 
{
    private:
        Node* head;
    
    public:
        DoublyLinkedList() : head(nullptr) {}
    
        void addToEmpty(int value) 
        {
            Node* new_node = new Node(value);
            head = new_node;
        }
    
        void addAtBeg(int value) 
        {
            if (head == nullptr) 
            {
                addToEmpty(value);
                return;
            } 
            else 
            {
                Node* new_node = new Node(value);
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            }
        }
    
        void addAtEnd(int value) 
        {
            Node* new_node = new Node(value);
            if (head == nullptr) {
                addToEmpty(value);
                return;
            }
            Node* temp = head;
            while (temp->next != nullptr) 
            {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev = temp;
        }
    
        void addBeforePos(int value, int pos) 
        {
            Node* new_node = new Node(value);
    
            if (pos <= 1) {
                addAtBeg(value);
                return;
            }
    
            Node* temp = head;
            for (int i = 1; i < pos - 1 && temp != nullptr; ++i) {
                temp = temp->next;
            }
    
            if (temp == nullptr || temp->next == nullptr) 
            {
                addAtEnd(value);
            } 
            else 
            {
                new_node->next = temp->next;
                new_node->prev = temp;
                if (temp->next != nullptr) 
                {
                    temp->next->prev = new_node;
                }
                temp->next = new_node;
            }
        }
    
        void addAfterPos(int value, int pos) 
        {
            Node* new_node = new Node(value);
    
            Node* temp = head;
            for (int i = 1; i < pos && temp != nullptr; ++i) 
            {
                temp = temp->next;
            }
    
            if (temp == nullptr) 
            {
                addAtEnd(value);
            } 
            else 
            {
                new_node->next = temp->next;
                new_node->prev = temp;
                if (temp->next != nullptr) 
                {
                    temp->next->prev = new_node;
                }
                temp->next = new_node;
            }
        }
    
        void deleteFirstNode() 
        {
            if (head == nullptr) return;
            Node *temp = head;
            head = head->next;
            if (head != nullptr) 
            {
                head->prev = nullptr;
            }
            delete temp;
        }
    
        void deleteIntermediary() 
        {
            if (head == nullptr) return;
            if (head->next == nullptr) 
            {
                deleteFirstNode();
                return;
            }
        
            Node *slow = head;
            Node *fast = head;
        
            while (fast != nullptr && fast->next != nullptr) 
            {
                slow = slow->next;
                fast = fast->next->next;
            }
        
            if (slow->prev != nullptr) 
            {
                slow->prev->next = slow->next;
            }
            if (slow->next != nullptr) {
                slow->next->prev = slow->prev;
            }
        
            if (slow == head) 
            {
                head = slow->next;
            }
        
            delete slow;
        }
    
        void deleteLastNode() 
        {
            if (head == nullptr) 
            {
                cout << "List is already empty." << endl;
                return;
            }
            
            if (head->next == nullptr) 
            {
                delete head;
                head = nullptr;
                return;
            }
            
            Node* last = head;
            while (last->next != nullptr) 
            {
                last = last->next;
            }
            
            last->prev->next = nullptr;
            
            delete last;
        }
        
        void deleteAtPos(int pos, char option)
        {
            if (head == nullptr) return;
            
            Node *temp = head;
            for (int i = 1; i < pos && temp != nullptr; i++)
            {
                temp = temp->next;
            }
            
            if (temp == nullptr)
            {
                cout << "Node not found\n";
                return;
            }
            
            Node *to_delete = nullptr;
            switch (option)
            {
                case 'a': // after the position
                    if (temp->next == nullptr) 
                    {
                        cout << "No node found after the position\n";
                        return;
                    }
                    
                    to_delete = temp->next;
                    
                    break;
                    
                case 'b':
                    if (temp->prev == nullptr)
                    {
                        cout << "No node found before the position\n";
                        return;
                    }
                    
                    to_delete = temp->prev;
                    
                    break;
                
                default:
                    to_delete = temp;
                    break;
            }
            
            if (to_delete->prev == nullptr)
            {
                deleteFirstNode();
                return;
            }
                    
            if (to_delete->next == nullptr)
            {
                deleteLastNode();
                return;
            }
                    
            to_delete->prev->next = to_delete->next;
            to_delete->next->prev = to_delete->prev;
                    
            delete to_delete;
        }
        
        Node *reverseList(Node *head)
        {
            Node *current = head;
            Node *prev = nullptr;
            Node *next = nullptr;
            
            while (current != nullptr)
            {
                next = current->next;
                
                current->next = prev;
                current->prev = next;
                
                prev = current;
                current = next;
            }
            
            head = prev;
            
            return head;
        }
        
        void reverseEntireList()
        {
            head = reverseList(head);
        }
        
        bool isPalindrome()
        {
            if (head == nullptr || head->next == nullptr) return true;
            
            Node *slow = head;
            Node *fast = slow->next;
            
            while (fast != nullptr)
            {
                fast = fast->next;
                if (fast != nullptr)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            
            Node *first_half = head;
            Node *second_half = reverseList(slow->next);
            
            while (second_half != nullptr)
            {
                if (first_half->data != second_half->data)
                    return false;
                first_half = first_half->next;
                second_half = second_half->next;
            }
            
            slow->next = reverseList(second_half);
            
            return true;
        }
        
        void printList() 
        {
            Node* temp = head;
            while (temp != nullptr) 
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main() 
{
    DoublyLinkedList myList;
    
    myList.addToEmpty(1);
    myList.addAtEnd(2);
    myList.addAtEnd(3);
    myList.addAtEnd(2);
    myList.addAtEnd(1);
    myList.printList();

    myList.reverseEntireList();
    myList.printList();

    int res = myList.isPalindrome();
    
    (res == 1) ? cout << "Is Palindrome\n" : cout << "Is Not Palindrome\n";
    
    myList.printList();
    return 0;
}
