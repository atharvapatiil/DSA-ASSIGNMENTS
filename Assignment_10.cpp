#include <iostream>
#include <cstring>
#define max 50
using namespace std;

class Stack
{
    char stack[max];
    int top;
public:
    Stack()
    {
        top = -1;
    }

    void Push(char ch);
    char Pop();
    void lower();
    void CheckPalindrome();
};

void Stack::Push(char ch)
{
    if(top == max - 1)  //Stack full condition
    {
        cout<<"STACK FULL"<<endl;
        return;
    }
    else
    {
        stack[top+1] = ch;
        top++;
        return;
    }
}

char Stack::Pop()
{
    if(top == -1)
    {
        cout<<"STACK EMPTY"<<endl;
        return 0;
    }
    else
    {
        char temp = stack[top];
        stack[top] = 0;
        top--;
        return temp;
    }
}

void Stack::lower()
{
    for(int i = 0; stack[i] != '\0'; i++)
    {
        if((int)stack[i] <= 90 && (int)stack[i] >= 65)
            stack[i] = (char)((int)stack[i] + 32);
    }
}

void Stack::CheckPalindrome()
{
    int len = top + 1;
    for(int i = 0; i < len/2; i++)
    {
        if(stack[i] != Pop())
        {
            cout<<"NOT PALINDROME"<<endl;
            return;
        }
    }
    cout<<"IS PALINDROME"<<endl;
}

int main()
{
    Stack s;

    //Input string from user
    char arr[max];
    string str;
    cout<<"Enter string:";
    getline(cin, str);

    //Clear white spaces
    for(int i = 0, j = 0; i < 50 && j < 50;i++)
    {
        if(str[i] == ' ')
        {
            continue;
        }
        arr[j] = str[i];
        j++;
    }

    //Push all characters in stack
    for(int i = 0; arr[i] != '\0'; i++)
        s.Push(arr[i]);

    //Check palindrome
    s.lower();
    s.CheckPalindrome();

    return 0;
}
