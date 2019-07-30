#include<iostream>
using namespace std;

class Node
{
public:
    int info;
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
    void InsertAtEnd(int x);
    void InsertAtStart(int x);
    void InsertInMiddle(int num, int index);
    int Count();
    void Display();
    int ElementAtIndex(int index);
};

int List::ElementAtIndex(int index)
{
    Node*current = first;
    int _count = 0;
    if(first == NULL)
    {
        cout<<"Emplty List"<<endl;
        return -1;
    }
    if(index == 0)
    {
        return (first->info);
    }
    else
    {
        while(_count < index)
        {
            current = current->next;
            _count++;
        }
        return(current->info);
    }
}

void List::InsertInMiddle(int x, int index)
{
    if(index == 0)
    {
        InsertAtStart(x);
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
        newNode->info = x;

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

void List::InsertAtStart(int x)
{
    Node *newNode;
    newNode = new Node;
    newNode->info = x;
    newNode->next = first;
    first = newNode;
}

void List::InsertAtEnd(int x)
{
    Node *current, *newNode;
    newNode = new Node;
    newNode->info = x;
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
            cout<<current->info<<" ";
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
    l1.InsertAtEnd(1);
    l1.InsertAtEnd(2);
    l1.InsertAtEnd(4);
    l1.InsertAtEnd(5);
    l1.InsertAtEnd(6);
    l1.InsertAtStart(0);
    l1.InsertInMiddle(3, 3);

    l1.Display();
    cout<<endl;
    cout<<"ELEMENT AT INDEX 2: "<<l1.ElementAtIndex(0);
    cout<<endl;
    cout<<"The list contains: "<<l1.Count()<<" items"<<endl;
    return 0;
}
