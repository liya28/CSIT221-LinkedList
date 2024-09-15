#include <iostream>

using namespace std;

struct Node 
{
    int num;
    Node *next;
    
    Node(int value) : num(value), next(nullptr) {}
};

class LinkedList
{
    private:
        Node *head;
        
    public:
        LinkedList() : head(nullptr) {}
        
        ~LinkedList()
        {
            Node *current = head;
            while (current != nullptr)
            {
                Node *next_node = current->next;
                delete current;
                current = next_node;
            }
            head = nullptr;
        }
        
        void addNodeToEnd(int num)
        {
            Node *new_node = new Node(num);
            
            if (head == nullptr)
            {
                head = new_node;
                return;
            }
            
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = new_node;
        }
        
        void printList()
        {
            cout << "Linked list contents: ";
            
            Node *current = head;
            while (current != nullptr)
            {
                cout << current->num << " ";
                current = current->next;
            }
            
            cout << endl;
        }
        
        int findLength()
        {
            int count = 0;
            
            if (head == nullptr)
            {
                return 0;
            }
            
            Node *current = head;
            
            while (current != nullptr)
            {
                ++count;
                current = current->next;
            }
            
            return count;
        }
};

int main()
{
    LinkedList list;
    
    int num;
    
    do 
    {
        cout << "Enter element (enter 0 to stop): ";
        cin >> num;
        
        if (num != 0) list.addNodeToEnd(num);
        
    } while (num != 0);
    
    list.printList();
    cout << "Linked list length: " << list.findLength();
    
    return 0;
}
