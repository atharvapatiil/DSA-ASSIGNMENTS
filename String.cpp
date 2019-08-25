/*
==================================
 ASSIGNMENT 6 : String Operations
==================================

Name : Sahil Hadke
Roll No : 17
Batch : S2

Write C++ program for string operations- copy, concatenate, check substring, equal, reverse
and length
*/

#include<iostream>
#include<cstring>
using namespace std;

const int size = 50;

class String
{
public:
	char str[size];	
	int length(char arr[size]);					
	int length();											
	void copyString(char arr[size], char arr2[size]); 		
	void Reverse(char arr[size]);							
	void Concat(char arr[size], char arr2[size]); 			
	void getData();
	bool Search(char arr[size]);										
	bool checkEqual(char arr[size]);
	bool Palindrome();

};

bool String::Palindrome()
{
	char arr[size];
	Reverse(str);
	copyString(arr, str);
	Reverse(str);

	return(checkEqual(arr));		
}

bool String::checkEqual(char arr[size])
{	
	for(int i = 0; i < length(); i++)
	{
		if(str[i] != arr[i])
			return false;
	}
	return true;
}

bool String::Search(char arr[size])
{
	int len = length(arr);
	int i,j,count = 0;
	for(i = 0; i <= length()-len; i++)
	{
		for(j = 0; j < len; j++)
		{
			if(str[i + j] != arr[j])		
				break;
			
			count++;			
		}	
		if(count == len)		
			return true;		
		else		
			count = 0;		
	}
	
	return false;
}

void String::Concat(char arr[size], char arr2[size])  //Concates and stores in first argument
{
	int i,j;
	for(i = length(arr), j = 0; i < size; i++, j++)
	{
		arr[i] = arr2[j];
		if(arr[j] == '\0')
			break;
	}
}

void String::Reverse(char arr[size])
{
	for(int i = 0; i < length(arr)/2; i++)
	{
		char temp = arr[i];
		arr[i] = arr[length(arr) - 1 - i];
		arr[length(arr) - 1 - i] = temp;
	}
}

void String::getData()  //gets input
{
	cout<<"Enter your string:";
	cin>>str;
}

int String::length()  //returns the length of this->str
{
	int count = 0;
	for(int i = 0; i < size; i++)
	{
		if(str[i] == '\0')
			break;

		count++;		
	}
	return count;
}

int String::length(char arr[size]) //Returns the length of argument
{
	int count = 0;
	for(int i = 0; i < size; i++)
	{
		if(arr[i] == '\0')
			break;

		count++;		
	}
	return count;
}

void String::copyString(char arr[size], char arr2[size]) //Copys the argument to the obj.str
{
	for(int i = 0; i < size; i++)
	{
		arr[i] = arr2[i];
		if(arr[i] == '\0')
			break;
	}	
}


int main()
{
	String s1;
	s1.getData();	
	cout<<s1.Palindrome();
	

	return 0;
}
