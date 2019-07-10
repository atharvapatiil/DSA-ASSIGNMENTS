/*
    ==========================================================
 	    ASSIGNMENT 3 : Magic Square 2 
    ==========================================================
 
    Code by: SAHIL HADKE
    Roll No: 17
    Batch: S1
    Question: MagicSquare
*/
#include<iostream>
using namespace std;


class MagicSquare
{
public:
	int n,row,col,i;
	int matrix[100][100];
	void getData();
	void InitiateMatrix();
	void putData();
	void printMatrix();

};

void MagicSquare::getData()
{
	cout<<"Enter n(odd):";
	cin>>n;
	cout<<endl;
}


void MagicSquare::InitiateMatrix()
{
	for(row = 0; row < n; row++)
	{
		for(col = 0; col < n; col++)
		{
			matrix[row][col] = 0;
		}
	}
}

void MagicSquare::putData()
{
	int i;
	row = n/2;
	col = n - 1;
	for(i = 1; i <= n*n; i++, row--, col++)
	{	
		if(row == -1 && col == n) //Rule 3 right corner
		{
			row = 0;
			col = n - 2;						
		}
		if(row < 0) //wrapping
		{
			row = n - 1;
		}
		if(col >= n) //wrapping
		{
			col = 0;
		}		
		if(matrix[row][col] != 0) //Rule 2 already occupied
		{
			col -= 2;
			row++;
			if(row < 0) //wrapping
			{
				row = n - 1;
			}
			if(col >= n) //wrapping
			{
				col = 0;
			}
		}	
		
		matrix[row][col] = i;
	}	
}

void MagicSquare::printMatrix()
{
    cout<<endl;
    cout<<"Your Matrix is: "<<endl;

    for(row = 0; row < n; row++)
    {
        for(col = 0; col < n; col++)
        {
            cout<<matrix[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    cout<<"Sum is: "<<n*(n*n + 1)/2<<endl;
}

int main()
{
	MagicSquare obj;
	obj.getData();
	obj.InitiateMatrix();
	obj.putData();
	obj.printMatrix();	
	
	return 0;
}    
