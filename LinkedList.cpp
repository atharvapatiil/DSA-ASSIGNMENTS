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
    void Remove(int index);
};

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
	l1.InsertAtEnd(1, "Sahil Hadke");
	l1.InsertAtEnd(2, "Roll two");
	l1.InsertAtStart(0, "Roll zero");
	l1.InsertInMiddle(5, "Second element", 1);
	cout<<l1.Count();
	l1.Display();
    return 0;
}
