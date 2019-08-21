/*
Write C++ program to store set of negative and positive numbers using linked list.
Write functions to
a)Insert numbers
b)Delete nodes with negative numbers
c)Create two more linked lists using this list, one containing all positive numbers and other containing negative numbers
d)For two lists that are sorted; Merge these two lists into third resultant list that is sorted
*/
#include<iostream>
using namespace std;

class Node
{
public:
	int num;
	Node *next;
};

class List
{
	Node *head, *head1, *head2;

public:

	List()
	{
		head = NULL;
		head1 = NULL;
		head2 = NULL;
	}

	void Insert();
	void Display();
	void DeleteNegative();
	void Sort();
};

void List::Insert()
{
	Node *newNode = new Node;
	int n;
	cout<<"Enter the number :";
	cin>>n;
	newNode->num = n;

	if(head == NULL)
	{
		head = newNode;
		return;
	}
	else
	{
		Node *current = head;
		while(current->next != NULL)
			current = current->next;
		current->next = newNode;
		return;
	}
}

void List::Display()
{    
    if(head == NULL)
    {
        cout<<"EMPTY LIST"<<endl;
    }
    else
    {
		Node *current;
    	current = head;
        while(current != NULL)
        {
            cout<<current->num<<endl;
            current = current->next;
        }
    }
}

void List::Sort()
{
	if(head == NULL)
	{
		cout<<"EMPTY LIST"<<endl;
		return;
	}
	else if(head->next == NULL)
	{
		cout<<"SORTED"<<endl;
		return;
	}
	else
	{
		Node *temp1 = head, *temp2 = head;
		
		while(temp1->next != NULL)
		{
			while(temp2->next != NULL )
			{
				temp2 = temp2->next;
				if(temp2->num < temp1->num)
				{
					int temp = temp2->num;
					temp2->num = temp1->num;
					temp1->num = temp; 		
				}
			}
			temp1 = temp1->next;
			temp2 = temp1;
		}
		return;
	}
}
/*
void List::DeleteNegative()
{
	if(head == NULL)
    {
        cout<<"EMPTY LIST"<<endl;
    }
	else
	{
		Node *pred = head, *current = head, *succ = head;
		while(pred->next != NULL)
		{
			if(current->num < 0)
				delete current;
		}
	}
}
*/
int main()
{
	List l1;
	l1.Insert();
	l1.Insert();
	l1.Insert();
	l1.Insert();

	l1.Sort();
	l1.Display();	

	return 0;
}
