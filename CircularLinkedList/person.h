#ifndef PERSON_H  // Check if PERSON_H is not defined
#define PERSON_H  // Define PERSON_H

#include <iostream>

using namespace std;

struct Person
{
	string first_name;
	string last_name;
	int age;
	int requests[4];
	
	void print_name()
	{
		cout << first_name << " " << last_name << endl;
	}
	
	void print()
	{
		cout << first_name << " " << last_name << " (" << age << ") - req: ";
		char req_ch[4] = {'B', 'M', 'C', 'D'};
		
		int i;
		for (i = 0; i < 4; i++)
		{
			if (requests[i] == 1)
			{
				cout << req_ch[i] << " ";
			}
		}
		cout << endl;
	}
	
	int req_count()
	{
		int ctr = 0;
		int i;
		for (i = 0; i < 4; i++)
		{
			ctr += requests[i];
		}
		return ctr;
	}
};

#endif // PERSON_H  // End of header guard
