/*

	========================
	   SINGLY LINKED LIST
	========================

	Name : Sahil Hadke
	Roll Number: 17
	
	Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of Second, third and final year of department can be granted membership on request.  Similarly one may cancel the membership of club. First node is reserved for president of club and last node  is  reserved  for  secretary  of  club.  Write  C++  program  to  maintain  club  member‘s information using singlylinked list. Store student PRN and Name. Write functions to 
	
a)Add and delete the members as well as president or even secretary.
b)Compute total number of members of club
c)Display members 
d)Display list in reverse order using recursion
e)Two linked lists existsfor two divisions. Concatenate two lists.
*/

#include<iostream>
#include<string>
using namespace std;

class Node
{
public:
    int prn;
	string name;
    Node *next;
};

class List
{
public:
    Node *first;
    List()
    {
        first = NULL;
    }
    void InsertAtEnd(int x, string str);				//Done
    void InsertAtStart(int x, string str);				//Done
    void InsertInMiddle(int x, string str, int index);	//Done
    int Count();										//Done
    void Display();										//Done
    void ElementAtIndex(int index);						//Done
    void Remove(int index);								//Done
	void Reverse();										//Done
	void Concat(List &l2);								//Done
};

void List::Concat(List &l2)
{
	Node *current1 = first;
	Node *current2 = l2.first;

	if(first == NULL) //l1 is Empty
	{
		cout<<"The first list is empty"<<endl;
		return;
	}
	else if(l2.first == NULL) //l2 is Empty
	{
		cout<<"The second list is empty"<<endl;
		return;
	}
	else
	{
		while(current1->next != NULL)
		{
			current1=current1->next;
		}
		current1->next = current2;		
	}
}

void List::Reverse()
{
	int _count = 0, _count2 = 0;	
	for(int i = 0; i < Count(); i++)
	{	
		Node *current = first;
		for(int j = Count() - i; j > 1; j--)
		{
			current=current->next;
		}  		
		cout<<"PRN: "<<current->prn<<" Name: "<<current->name<<endl;
	}		
}

void List::Remove(int index)
{
	if(index == 0)
	{
		Node* second = (first->next);
		delete first->next;
		first = second;
	}
	else if(index == Count() - 1)
	{
		Node *current = first;
		int _count = 0;
		while(_count <= index)
		{
			current = current->next;
		}		
	}
	else
	{
		Node *previous = first;
		Node *current, *later;
		
		int _count = 0;
		while(_count < index - 1)
		{
			previous = previous->next;
			_count++;
		}
		current = previous->next;
		later = current->next;
	
		previous->next = later;
		delete current;
	}
}

void List::ElementAtIndex(int index)
{
    Node*current = first;
    int _count = 0;
    if(first == NULL)
    {
        cout<<"Emplty List"<<endl;
		return;
    }
    if(index == 0)
    {
        cout<<"PRN: "<<first->prn<<" Name: "<<first->name<<endl;
    }
    else
    {
        while(_count < index)
        {
            current = current->next;
            _count++;
        }
        cout<<"PRN: "<<(current->prn)<<" Name: "<<endl;
    }
}

void List::InsertInMiddle(int x, string str, int index)
{
    if(index == 0)
    {
        InsertAtStart(x, str);
        return;
    }
    else if(index >= Count())
    {
        cout<<"Invalid"<<endl;
        return;
    }
    else
    {
        Node *newNode = new Node;
        Node *current, *prev = first;
        int _count = 0;
        newNode->prn = x;
		newNode->name = str;

        while(_count < index - 1)
        {
            prev = prev->next;
            _count++;
        }
        current = prev->next;
        prev->next = newNode;
        newNode->next = current;
    }
}

void List::InsertAtStart(int x, string str)
{
    Node *newNode;
    newNode = new Node;
    newNode->prn = x;
	newNode->name = str;
    newNode->next = first;
    first = newNode;
}

void List::InsertAtEnd(int x, string str)
{
	Node *newNode = new Node;
    Node *current;  
    newNode->prn = x;
	newNode->name = str;
    newNode->next = NULL;

    if(first == NULL)
    {
        first = newNode;
    }
    else
    {
        current = first;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void List::Display()
{
    Node *current;
    current = first;
    if(current == NULL)
    {
        cout<<"EMPTY LIST";
    }
    else
    {
        while(current != NULL)
        {
            cout<<"PRN: "<<current->prn<<" Name: "<<current->name<<endl;
            current = current->next;
        }
    }
}

int List::Count()
{
    int _count = 0;
    Node *current;
    current = first;
    if(current == NULL)
    {
        return 0;
    }
    else
    {
        while(current != NULL)
        {
            _count++;
            current = current->next;
        }
        return _count;
    }
}

int main()
{
	List l1;
	cout<<"List l1 created!"<<endl;
	cout<<"Displaying list: "<<endl;
	l1.Display();
	cout<<endl;

	l1.InsertAtEnd(2, "Roll Number Two"); 
	l1.InsertAtEnd(4, "Roll Number Four"); 
	cout<<"Inserted 2 and 4 Roll numbers at end."<<endl;
	cout<<"Displaying list: "<<endl;
	l1.Display();
	cout<<endl;
	
	l1.InsertInMiddle(3, "Roll Number Three", 1); //At index 1
	l1.InsertAtStart(1, "Roll Number One");
	cout<<"Inserted roll no. 3 at index 1 and then inserted roll no. 1 at start"<<endl;
	cout<<"Displying list: "<<endl;
	l1.Display();
	cout<<endl;

	List l2;
	cout<<"Created List l2"<<endl;	
	l2.InsertAtEnd(5, "Roll Number Five");
	l2.InsertAtEnd(6, "Roll Number Six");
	cout<<"Displaying list l2: "<<endl;
	l2.Display();
	cout<<endl;

	cout<<"Joining two lists and displaying: "<<endl;
	l1.Concat(l2);
	l1.Display();
	cout<<endl;

	cout<<"Removing Roll number 2 at index 1 and displaying."<<endl;
	l1.Remove(1);
	l1.Display();
	cout<<endl<<"Code by Sahil Hadke";

    return 0;
}
