/*
=====================================
 ASSIGNMENT-8 : Circular Linked List
=====================================
Name : Sahil Hadke
Roll No. : 17
Batch : S2

The ticket booking system of Cinemax theater has to be implemented using C++ program. 
There are 10 rows and 7 seats in each row. 
Doubly circular linked list has to be maintained to keep track of free seats at rows. 
Assume some random booking to start with. 
Use array to store pointers (Head pointer) to each row.  On demand 
a) The list of available seats is to be displayed
b) The seats are to be booked
c)  The booking can be cancelled.
*/

#include<iostream>
using namespace std;

class Node
{
public:
	int available;
	Node* next;
	Node()
	{
		available = 1;
	}
};

class List
{
public:
	Node* head;
	List()
	{
		head = NULL;
	}

	void InsertAtEnd(int i);
	void Display();
	void Book();
	void UnBook();
};

void List::InsertAtEnd(int i = 1)
{
	Node *newNode = new Node;
	
	if(head == NULL)
	{
		head = newNode;
		newNode->next = head;
	}
	else
	{
		Node *current;
		current = head;
		while(current->next != head)
			current = current->next;
		current->next = newNode;
		newNode->next = head;	
	}	
}

void List::Display()
{
	Node *current = head;
	while(current->next != head)
	{
		cout << current->available << " ";
		current = current->next;
	}
	cout<<endl;	
}

void List::Book()
{	
	int num2;
	cout<<"Enter seat number(1-7) :";
	cin>>num2;
	num2--;
	if(num2 < 0 || num2 > 7)
	{
		cout<<"Wrong Input";
		return;
	}	
		
	Node *current = head;
	int i = 1;
	while(current->next!= head && i <= num2)
	{
		current = current->next;
		i++;
	}
	current->available = 0;		
}

void List::UnBook()
{	
	int num2;
	cout<<"Enter seat number(1-7) :";
	cin>>num2;
	num2--;
	if(num2 < 0 || num2 > 7)
	{
		cout<<"Wrong Input";
		return;
	}	
		
	Node *current = head;
	int i = 1;
	while(current->next!= head && i <= num2)
	{
		current = current->next;
		i++;
	}
	current->available = 1;		
}

int main()
{	
	//Create an array of pointers to lists
	List* arr[10];
	for(int i = 0; i < 10; i++)
	{
		arr[i] = new List;	
		for(int j = 0; j <= 7; j++)
		{
			arr[i]->InsertAtEnd();
		}
	}
	int condi = 1;

	do
	{
		int choice, n1, n2;
		cout<<"Enter 1 to Book, enter 2 to unbook, enter 3 to display"<<endl;
		cin>>choice;
	
		switch(choice)
		{
			case 1:
				cout<<"Enter row to book(1-10) :";
				cin>>n1;
				n1--;
				arr[n1]->Book();
				break;
			case 2:				
				cout<<"Enter row to book(1-10) :";
				cin>>n2;
				n2--;
				arr[n2]->UnBook();
				break;
			case 3:
				cout<<"===========DISPLAYING===========\n1 = Available, 0 = Booked"<<endl;
				for(int i = 0; i < 10; i++)
					arr[i]->Display();
				cout<<"===========DISPLAYING FINISHED==========="<<endl;
				break;
		}

		cout<<"Enter 1 to Continue or 0 to exit :";
		cin>>condi; 
	}while(condi);
	
	return 0;
}
