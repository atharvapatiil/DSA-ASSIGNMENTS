/*
    ===================================
       ASSIGNMENT 3 : Magic Square 2
    ===================================

    Code by: SAHIL HADKE
    Roll No: 17
    Batch: S1
    Question: MagicSquare
*/
#include<iostream>
using namespace std;


bool isMagicSquare = true; //global variable

class MagicSquare //Returns true if the user input is magic square
{

private:
    int n, row, column, sum = 0, current = 0;
    int matrix[100][100];

public:
    MagicSquare() //Default Constructor where all the functions are called
    {
        getData();
        SetSum();
        printMatrix();
        CheckHorizontal();
        CheckVertical();
        CheckDiagonalLeftToRight();
        CheckDiagonalRightToLeft();
        Result();
    }
    void getData();
    void SetSum();
    void printMatrix();
    void CheckHorizontal();
    void CheckVertical();
    void CheckDiagonalLeftToRight();
    void CheckDiagonalRightToLeft();
    void Result();
};

class CreateMS //Creates a magic square of n*n
{
    int n,row,col,i;
	int matrix[100][100];

public:
    CreateMS() //Default Constructor where all the member functions are called
    {
        getData();
        InitiateMatrix();
        putData();
        printMatrix();
    }

	void getData();
	void InitiateMatrix();
	void putData();
	void printMatrix();
};

void MagicSquare::getData() //Takes input from user
{
    cout<<"Enter n for (n x n) matrix: ";
    cin>>n;
    cout<<endl;

    for(row = 0; row < n; row++)
    {
        for(column = 0; column < n; column++)
        {
            cout<<"Enter number in row("<<row+1<<"), column("<<column+1<<") :";
            cin>>matrix[row][column];
            cout<<endl;
        }
    }
}

void MagicSquare::SetSum() //Sets the sum of the give matrix.
{
    for(row = 1; row <= n*n; row++)
    {
        sum += row;
    }
    sum /= n;
    row = 0;
    cout<<"\nSum is: "<<sum<<endl;
}

void MagicSquare::printMatrix()  //Prints the matrix
{
    cout<<endl;
    cout<<"Your Matrix is: "<<endl;

    for(row = 0; row < n; row++)
    {
        for(column = 0; column < n; column++)
        {
            cout<<matrix[row][column]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void MagicSquare::CheckHorizontal() //Checks the sum for all rows
{
    if(isMagicSquare)
    {
        current = 0;
        for(row = 0; row < n; row++)
        {
            current = 0;
            for(column = 0; column < n; column++)
            {
                current += matrix[row][column];
            }
            if(current != sum)
            {
                isMagicSquare = false;
                break;
            }
        }
    }
}

void MagicSquare::CheckVertical()  //Checks the sum for all columns
{
    if(isMagicSquare)
    {
        current = 0;
        for(column = 0; column < n; column++)
        {
            current = 0;
            for(row = 0; row < n; row++)
            {
                current += matrix[row][column];
            }
            if(current != sum)
            {
                isMagicSquare = false;
                break;
            }
        }
    }
}

void MagicSquare::CheckDiagonalLeftToRight() //Checks the sum of one diagonal.
{
    if(isMagicSquare)
    {
        current = 0;
        for(row = 0; row < n; row++)
        {
            current += matrix[row][row];
        }
        if(current != sum)
        {
            isMagicSquare = false;
        }
    }
}

void MagicSquare::CheckDiagonalRightToLeft()  //Checks the sum for other diagonal
{
    if(isMagicSquare)
    {
        current = 0;
        for(row = n - 1, column = 0; row >= 0, column < n; row--,column++)
        {
            current += matrix[row][column];
        }
        if(current != sum)
        {
            isMagicSquare = false;
        }
    }
}

void MagicSquare::Result()
{
    if(isMagicSquare)
    {
        cout<<"MAGIC SQUARE"<<endl;
    }
    else
    {
        cout<<"NOT A MAGIC SQUARE"<<endl;
    }
}

void CreateMS::getData()
{
	cout<<"Enter n(odd):";
	cin>>n;
	cout<<endl;
}

void CreateMS::InitiateMatrix()
{
	for(row = 0; row < n; row++)
	{
		for(col = 0; col < n; col++)
		{
			matrix[row][col] = 0;
		}
	}
}

void CreateMS::putData() //Puts all the numbers in the matrix in order
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

void CreateMS::printMatrix()  //Prints matrix
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
    int UserWish;
    cout<<"Do you want to check the given matrix is magic square or not? PRESS 1\nOr do you want me to print a magic square of size n*n for you? PRESS 2"<<endl;
    cin>>UserWish;

    if(UserWish == 1)
    {
        MagicSquare obj;
    }
    else if(UserWish == 2)
    {
        CreateMS obj;
    }
    else{
        cout<<"Something went wrong!";
    }

	return 0;
}
