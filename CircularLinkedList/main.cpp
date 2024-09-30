#include <iostream>
#include "linkedlist.h"
#include "person.h"

using namespace std;

int main()
{
	LinkedList *requests = new LinkedList();
	char operation;
	string name;
	int num;
	
	while (true)
	{
		cout << "Enter operation (a: add, s: serve, f: fast lane, p: print, x: exit, d: delay, t: trade, v: advance): ";
        cin >> operation;
        
	    if (operation == 'a') 
		{
	        Person *p = new Person; 
	        cout << "Enter first name: ";
	        cin >> p->first_name;
	        cout << "Enter last name: ";
	        cin >> p->last_name;
	        cout << "Enter age: ";
	        cin >> p->age;
	        
			cout << "Enter requests (B, M, C, D) as 1 for yes, 0 for no (e.g., 1 0 1 0): ";
	        for (int i = 0; i < 4; i++) 
			{
	            cin >> p->requests[i];
	        }
	
	        requests->add(p); 
	        cout << "Person added!" << endl;
	
	    } 
		else if (operation == 's') 
		{
	        char docType;
	        cout << "Enter document type to serve (B, M, C, D): ";
	        cin >> docType;
	        Person *servedPerson = requests->serveRequest(docType);
	        
			if (servedPerson) 
			{
	            cout << "Served: ";
	            servedPerson->print();
	            if (servedPerson->req_count() == 0) 
				{
	                delete servedPerson; 
	            }
	        } 
			
			else 
			{
	        	cout << "No requests found for " << docType << "." << endl;
	        }
	
		} 
		
		else if (operation == 'f') 
		{
	        Person *fastLanePerson = requests->fastLane();
	        if (fastLanePerson) 
			{
	            cout << "Fast lane served: ";
	            fastLanePerson->print();

	            if (fastLanePerson->req_count() == 0) 
				{
	                    delete fastLanePerson; 
	            }
	        } 
			else 
			{
	            cout << "No one in the fast lane." << endl;
	        }
	
	    } 
	    
		else if (operation == 'd')
		{
		    string name;
		    cout << "Enter name to delay: ";
		    cin.ignore();  // Clear the input buffer before using getline
		    getline(cin, name);  // Use getline for full name input
		
		    int num;
		    cout << "How many positions to move back? ";
		    cin >> num;
		
		    requests->delay(name, num);  // Call the delay function
		}
		
		else if (operation == 'v')
		{
		    string name;
		    cout << "Enter name to advance: ";
		    cin.ignore();  // Clear the input buffer before using getline
		    getline(cin, name);  // Use getline for full name input
		
		    int num;
		    cout << "How many positions to move forward? ";
		    cin >> num;
		
		    requests->advance(name, num);  // Call the advance function
		}
		
		else if (operation == 't')
		{
		    string name1, name2;
		    cout << "Enter first name to trade: ";
		    cin.ignore();  // Clear the input buffer before using getline
		    getline(cin, name1);  // Use getline for full name input
		
		    cout << "Enter second name to trade: ";
		    getline(cin, name2);  // Use getline for second name
		
		    requests->trade(name1, name2);  // Call the trade function
		}
		
		else if (operation == 'p') 
		{
	        requests->print(); 
	    } 
		
		else if (operation == 'x') 
		{
	        cout << "Exiting..." << endl;
	        break;
	    } 
		
		else 
		{
	        cout << "Invalid operation! Please try again." << endl;
	    }
	}
	
	return 0;
}
