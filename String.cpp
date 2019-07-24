#include<iostream>
#include<cstring>
using namespace std;

class String
{
public:
	char str[50];	
	int length(char arr[50]);	
	void copyString(char arr[50]); 
	void Reverse();
	

};

void String::Reverse()
{

}

int String::length(char arr[50]) //Returns the length of argument
{
	int count = 0;
	for(int i = 0; i < 50; i++)
	{
		if(arr[i] == '\0')
			break;

		count++;		
	}
	return count;
}

void String::copyString(char arr[50]) //Copys the argument to the obj.str
{
	for(int i = 0; i < 50; i++)
	{
		this->str[i] = arr[i];
		if(arr[i] == '\0')
			break;
	}	
}


int main()
{
	int condition;
	cout<<"Enter the operation:";
	cin>>condition;

	switch(condition)
	{
		case 1: //Length
			String s1;
			cout<<"\nEnter your string:";
			cin>>s1.str;
			cout<<s1.length(s1.str)<<endl;
			delete s1;
			break;

		case 2: //CopyString
			String s1;
			cout<<"\nEnter your string:";
			cin>>s1.str;
			char arr[50];
			cout<<endl<<"Enter the string you want to copy:";
			cin>>arr;
			s1.copyString(arr);
			cout<<"Copied String is:"
			cout<<s1.str;
			delete s1;
			break;

		case 3
			

	}

	return 0;
}
