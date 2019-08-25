/*
==========================================
 ASSIGNMENT 9 : Positive-Negative Numbers
==========================================

Name : Sahil Hadke
Roll No. : 17
Batch: S2

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
public:

    Node *head, *head1, *head2;

	List()
	{
		head = NULL;
		head1 = NULL;
		head2 = NULL;
	}

	void Insert();
	void Display(Node *s);
	void DeleteNegative();
	void Sort();
	void Split();
	void Merge();
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

void List::Display(Node *s)
{
    if(s == NULL)
    {
        cout<<"EMPTY LIST"<<endl;
    }
    else
    {
		Node *current;
    	current = s;
        while(current != NULL)
        {
            cout<<current->num<<" ";
            current = current->next;
        }
        cout<<endl;
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

void List::DeleteNegative()
{
	Sort();

	Node *temp = head, *temp2;

	while(temp->num < 0)
	{

        temp2 = temp->next;
        delete temp;
        temp = temp2;
        if(temp->num > 0)
            head = temp;
        temp = temp->next;
	}
}

void List::Split()
{
    Sort();

    head1 = head;
    Node *temp = head, *prev = head;
    while(temp->num < 0)
    {
        if((prev->next)->num < 0)
            prev = prev->next;
        temp = temp->next;
    }
    head2 = temp;
    prev->next = NULL;
    head = NULL;
}

void List::Merge()
{
    head = head1;
    Node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
}

int main()
{
	List l1;

	int count, condition = 1;
	cout<<"Enter number of times you want to insert data :";
	cin>>count;

	for(int i = 0; i < count; i++)
    {
        l1.Insert();
    }
    int choice;

    do
    {
        cout<<"1 - Display\n2 - Split\n3 - Merge\n4 - Delete Negative\n5 - Sort\nEnter choice here :";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Starting from head :";
                l1.Display(l1.head);
                cout<<"Starting from head1 :";
                l1.Display(l1.head1);
                cout<<"Starting from head2 :";
                l1.Display(l1.head2);
                break;
            case 2:
                l1.Split();
                break;
            case 3:
                l1.Merge();
                break;
            case 4:
                l1.DeleteNegative();
                break;
            case 5:
                l1.Sort();
                break;
            default:
                cout<<"Wrong Input"<<endl;
        }

        cout<<"Enter 1 to Continue, 0 to exit :";
        cin>>condition;
    }while(condition);

	return 0;
}
