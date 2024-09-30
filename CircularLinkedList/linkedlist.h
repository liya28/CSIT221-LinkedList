#include <iostream>
#include "person.h"
#include "node.h"

using namespace std;

class LinkedList {
    node* head;      
    node* tail;     
    node* senior;   
    int size;      

public:
	
    LinkedList() 
	{
        head = new node;
        tail = new node;
        head->next = tail;
        tail->prev = head;
        senior = head; 
        size = 0;
    }
    
	node *find_person_by_name(string first_name)
	{
	    node *current = head->next;
	    while (current != tail)
	    {
	        if (current->person->first_name == first_name)
	        {
	            return current;
	        }
	        current = current->next;
	    }
	    return NULL; 
	}
	
	void swapNodes(node* node1, node* node2) {
        if (node1 == node2) return;

        // Swap node1 and node2
        if (node1->next == node2) 
		{  // Adjacent nodes
            node* prev = node1->prev;
            node* next = node2->next;
            node1->next = next;
            node1->prev = node2;
            node2->next = node1;
            node2->prev = prev;
            
            if (next) next->prev = node1;
            if (prev) prev->next = node2;
        } 
		
		else 
		{
            node* tempPrev = node1->prev;
            node* tempNext = node1->next;
            node1->prev = node2->prev;
            node1->next = node2->next;
            node2->prev = tempPrev;
            node2->next = tempNext;
            
            if (node1->prev) node1->prev->next = node1;
            if (node1->next) node1->next->prev = node1;
            if (node2->prev) node2->prev->next = node2;
            if (node2->next) node2->next->prev = node2;
        }

        if (node1 == head) head = node2;
        else if (node2 == head) head = node1;

        if (node1 == tail) tail = node2;
        else if (node2 == tail) tail = node1;
    }
		
	void delay(string name, int back) 
	{
        node* current = find_person_by_name(name);
        if (!current || back <= 0) return;

        for (int i = 0; i < back && current->next; i++) {
            swapNodes(current, current->next);
            current = current->next;
        }
    }

    void advance(string name, int forward) 
	{
        node* current = find_person_by_name(name);
        if (!current || forward <= 0) return;

        for (int i = 0; i < forward && current->prev; i++) {
            swapNodes(current->prev, current);
            current = current->prev;
        }
    }
	
	void trade(string name1, string name2) 
	{
        node* person1 = find_person_by_name(name1);
        node* person2 = find_person_by_name(name2);
        if (person1 && person2) 
		{
            swapNodes(person1, person2);
        }
    }

    node* addBetween(Person* p, node* pred, node* succ) 
	{
        node* n = new node;
        n->person = p;
        n->prev = pred;
        n->next = succ;

        pred->next = n;
        succ->prev = n;

        size++;
        return n;
    }

    void add(Person* p) 
	{
        if (p->age >= 60) 
		{ 
            senior = addBetween(p, senior, senior->next); 
            if (senior->next != tail) 
			{
                senior->next->prev = senior; 
            }
        } 
		
		else 
		{	
            addBetween(p, tail->prev, tail); 
        }
    }

    int reqIndex(char ch) 
	{
        switch (ch) 
		{
            case 'B': return 0;
            case 'M': return 1;
            case 'C': return 2;
            case 'D': return 3;
            default: return -1;
        }
    }

    void removeHead(node* n) 
	{
        node* pred = n->prev;
        node* succ = n->next;

        pred->next = succ;
        succ->prev = pred;

        size--;

        if (n == senior) 
		{
            senior = pred;
        }

        delete n;
    }

    Person* serveRequest(char ch) 
	{
        int index = reqIndex(ch);
        node* current = head->next;
        
        while (current != tail) 
		{
            if (current->person->requests[index] == 1) 
			{ 
                current->person->requests[index] = 0; 
                
                if (current->person->req_count() == 0) 
				{
                    Person* servedPerson = current->person;
                    removeHead(current); 
                    
                    return servedPerson; 
                }
                
                return current->person; 
            }
            
            current = current->next; 
        }
        return NULL;
    }

    Person* fastLane() 
	{
        node* current = head->next; 
        
        while (current != tail) 
		{
            if (current->person->req_count() == 1) 
			{ 
                Person* servedPerson = current->person;
                removeHead(current); 
                return servedPerson;
            }
            current = current->next; 
        }
        return NULL; 
    }

    void print() 
	{
        cout << "Counter: " << size << endl;
        cout << "From First:" << endl;
        node* current = head->next;
        int index = 1;

        while (current != tail) 
		{
            cout << index++ << ". ";
            current->person->print(); 
            current = current->next;
        }

        cout << "From Last:" << endl;
        current = tail->prev;
        index = size;

        while (current != head) 
		{
            cout << index-- << ". ";
            current->person->print(); 
            current = current->prev;
        }
    }
};

