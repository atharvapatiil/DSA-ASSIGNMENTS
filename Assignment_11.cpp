/*
    INFIX TO POSTFIX
*/
#include <iostream>
#include <string>
#define max 50
using namespace std;

class Stack
{
public:

    int top;
    char stack[max];

    Stack()
    {
        top = -1;
    }

    void Push(char ch)
    {
        if(top == max - 1)
        {
            cout<<"STACK FULL"<<endl;
            return;
        }
        stack[top + 1] = ch;
        top++;
    }

    char Pop()
    {
        if(top == -1)
        {
            cout<<"STACK EMPTY"<<endl;
            return 0;
        }
        char temp = stack[top];
        top--;
        return temp;
    }

    char Peek()
    {
        return stack[top];
    }
};

int Precedence(char ch)
{
    switch(ch)
    {
        case '+':
            return 1;
        case '-':
            return 1;
        case '/':
            return 1;
        case '*':
            return 1;
        case '^':
            return 3;
    }
}

bool isOperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '/' || ch == '^' || ch == '*')
        return true;
    return false;
}

int main()
{
    Stack s;
    string infix, postfix;

    cout<<"Enter infix expression :";
    getline(cin, infix);

    for(int i = 0; i < infix.size(); i++)
    {
        if(!isOperator(infix[i]))
            cout<<infix[i];
        else
        {
            if(s.top != -1 && Precedence(infix[i]) < Precedence(s.Peek()))
            {
                s.Push(infix[i]);
            }
            else
            {
                while(Precedence(s.Peek()) > infix[i])
                {
                    cout<<s.Pop();
                }
                s.Push(infix[i]);
            }
        }
    }
    while(s.top >= 0)
    {
        cout<<s.Pop();
    }

    return 0;
}
