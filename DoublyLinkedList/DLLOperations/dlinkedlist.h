#include "dlist.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class DLinkedList : public DList
{
	private:
		Node *head;
		Node *tail;
		int size;
	
	public:
		
		DLinkedList() : head(NULL), tail(NULL), size(0) {}
		
		void addNodeAtBeg(int num)
		{
			Node *new_node = (Node*)calloc(1, sizeof(Node));
			new_node->elem = num;
			
			if (!head)
			{
				head = tail = new_node;
				size++;
				return;
			}
			
			new_node->next = head;
			head->prev = new_node;
			head = new_node;
			
			size++;
			return;
		}
		
		void addNodeAtEnd(int num) 
		{
			Node *new_node = (Node*)calloc(1, sizeof(Node));
			new_node->elem = num;
			
			if (!head)
			{
				addNodeAtBeg(num);
				return;
			}
			
			tail->next = new_node;
			new_node->prev = tail;
			tail = new_node;
			
			size++;
			return;
		}
		
		int removeFirst() 
		{
			if (!head)
			{
				cout << "List is empty.\n";
				return -1;
			}
			
			Node *to_delete = head;
			int num = head->elem;
			
			if (head == tail)
			{
				head = tail = NULL;
			}
			else
			{
				head = head->next;
				head->prev = NULL;
			}
			
			delete to_delete;
			size--;
			return num;
		}
		
		int removeLast()
		{
			if (!head)
			{
				cout << "List is empty.\n";
				return -1;
			}
			
			Node *to_delete = tail;
			int num = tail->elem;
			
			if (head == tail)
			{
				head = tail = NULL;
			}
			else
			{
				tail = tail->prev;
				tail->next = NULL;
			}
			
			delete to_delete;
			size--;
			return num;
		} 
		
		void insertAtPos(int num, int pos) 
		{
			if (!head)
			{
				addNodeAtBeg(num);
				return;
			}
			
			if (pos == 1)
			{
				addNodeAtBeg(num);
				return;
			}
			
			if (pos >= size)
			{
				addNodeAtEnd(num);
				return;
			}
			
			Node *new_node = (Node*)calloc(1, sizeof(Node));
			new_node->elem = num;
			
			int i;
			Node *current = head;
			
			for (i = 1; i < pos - 1; i++)
			{
				current = current->next;
			}
			
			new_node->next = current->next;
			new_node->prev = current;
			
			if (current->next != NULL)
			{
				current->next->prev = new_node;
			}
			
			current->next = new_node;
			
			size++;
			
			return;
		}
		
		int removeAtPos(int pos) 
		{
			 if (!head)
			 {
			 	cout << "List is empty.\n";
			 	return -1;
			 }
			 
			 if (pos == 1)
			 {
			 	return removeFirst();
			 }
			 
			 if (pos >= size)
			 {
			 	return removeLast();
			 }
			 
			 int i;
			 int n;
			 Node *to_delete;
			 Node *current = head;
				 
			 for (i = 2; i < pos; i++)
			 {
			 	current = current->next;
			 }
			 
			 to_delete = current->next;
			 n = to_delete->elem;
			 
			 current->next = to_delete->next;
			 
			 if (to_delete->next != NULL)
			 {
			 	to_delete->next->prev = current;
			 }
		
			 delete to_delete;
			 size--;
			 return n;
		}
		
		int remove(int num) 
		{
		        Node* current = head;
		
		        while (current != nullptr) 
			{
		            if (current->elem == num) 
			    {
		                if (current == head) 
				{
		                    head = current->next;
		                    if (head != nullptr) 
				    {
		                        head->prev = nullptr;
		                    } 
				    else 
				     {
		                        tail = nullptr;
		                    }
		                } 
		                else if (current == tail) 
				{
		                    tail = current->prev;
		                    if (tail != nullptr) 
				    {
		                        tail->next = nullptr;
		                    } 
				    else 
				    {
		                        head = nullptr;
		                    }
		                } 
		                else 
				{
		                    current->prev->next = current->next;
		                    current->next->prev = current->prev;
		                }
		
		                delete current;
		                cout << "Number " << num << " removed.\n";
		                return 0;
		        }
		        current = current->next;
		    }
		    cout << "Number " << num << " not found.\n";
			return -1;
		}

		int removeAll(int num)
		{
			if (!head)
			{
				cout << "List is empty.\n";
				return -1;
			}
			
			int count = 0;
			
			Node *current = head;
			
			while (current)
			{
				if (current->elem == num)
				{
					if (current == head)
					{
						removeFirst();
					}
					else
					{
						Node *to_delete = current;
						current = current->next;
						
						if (to_delete == tail)
						{
							removeLast();
						}
						else
						{
							Node *prev = to_delete->prev;
							int pos = 1;
							while (prev)
							{
								pos++;
								prev = prev->prev;
							}
							removeAtPos(pos);
						}
					}
					count++;
				}
				else
				{
					current = current->next;
				}
			}
			return count;

			/* when the removeAll utilizes a remove() and not a removeAtPos()
   			int count = 0;
	  		while (remove(num) != -1)
	 		{
				count++;
			}
   			return count;
			*/
		}
		
		void reverse() 
		{
			if (!head)
			{
				cout << "List is empty,\n";
				return;
			}
			
			Node *current = head;
			Node *prev = NULL;
			Node *succ = NULL;
			
			while (current)
			{
				succ = current->next;
				
				current->next = prev;
				current->prev = succ;
				
				prev = current;
				current = succ;
			}
			
			head = prev;
			
			return;
		}
		
		int getSize() 
		{
			return size;
		}
		
		void print()
		{
			cout << "Size: " << size << endl;
			Node *current = head;
			while (current)
			{
				cout << current->elem << " -> ";
				current = current->next;
			}
			return;
		}
};
