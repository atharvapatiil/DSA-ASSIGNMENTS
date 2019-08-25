/*
===================================
 ASSIGNMENT 3 : Password generator
===================================
Name: Sahil Hadke
Roll No. : 17
Batch: S2

Set A=(1,3, a, s, t, i} represent alphanumeric characters permitted to be used to set the
password of length 4. Write C/C++ program to generate all possible passwords
*/

#include<iostream>
using namespace std;

class PasswordGen
{
	char arr[6];
	
public:
	
	void getInput()
	{
		for(int i = 0; i < 6; i++)
		{
			cout << "Enter element " << i+1 << " :";
			cin >> arr[i];
			cout << endl;
		}
	}

	void generatePass()
	{
		cout<<endl;
		int i,j,k,l,count = 0;
		for(i = 0; i < 6; i++)
		{
			for(j = 0; j < 6; j++)
			{
				if(j == i)
					continue;
				else
				{
					for(k = 0; k < 6; k++)
					{
						if(k == j || k == i)
							continue;
						else
						{
							for(l = 0; l < 6; l++)
							{		
								if(l == k || l == j || l == i)
									continue;
								else
								{
									cout<<arr[i]<<arr[j]<<arr[k]<<arr[l];
									count++;
									cout<<endl;		
								}	
							}
						}						
					}
				}					
			}
		}	

		cout<<count<<endl;	
	}
};


int main()
{
	PasswordGen obj;
	obj.getInput();
	obj.generatePass();

	return 0;
}
