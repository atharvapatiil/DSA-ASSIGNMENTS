/*
    =============================
 	 ASSIGNMENT 3 : MAGIC SQUARE 
    =============================
 
    Code by: SAHIL HADKE
    Roll No: 17
    Batch: S1
    Question: A magic square is an n * n matrix of the integers 1 to n^2
              such that the sum of each row,
              column, and diagonal is the same. Write C/C++ Program for checking a magic square.
*/
#include<iostream>
using namespace std;

bool isMagicSquare = true; //global variable

class MagicNumber
{

private:
    int n, row, column, sum = 0, current = 0;
    int matrix[100][100];

public:
    MagicNumber() //Constructor
    {
        getData();
        SetSum();
        printMatrix();
        CheckHorizontal();
        CheckVertical();
        CheckDiagonalLeftToRight();
        CheckDiagonalRightToLeft();
    }
    void getData();
    void SetSum();
    void printMatrix();
    void CheckHorizontal();
    void CheckVertical();
    void CheckDiagonalLeftToRight();
    void CheckDiagonalRightToLeft();
};

void MagicNumber::getData() //Takes input from user
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

void MagicNumber::SetSum() //Sets the sum of the give matrix. 
{
    for(row = 1; row <= n*n; row++)
    {
        sum += row;
    }
    sum /= n;
    row = 0;
    cout<<"\nSum is: "<<sum<<endl;
}

void MagicNumber::printMatrix()  //Prints the matrix
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

void MagicNumber::CheckHorizontal() //Checks the sum for all rows
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

void MagicNumber::CheckVertical()  //Checks the sum for all columns
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

void MagicNumber::CheckDiagonalLeftToRight() //Checks the sum of one diagonal.
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

void MagicNumber::CheckDiagonalRightToLeft()  //Checks the sum for other diagonal
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

int main()
{
    MagicNumber obj; 
    /*Since all the methods are c
    alled in the constructor, no need to call them in main
    */
    if(isMagicSquare)
    {
        cout<<"MAGIC SQUARE"<<endl;
    }
    else
    {
        cout<<"NOT A MAGIC SQUARE"<<endl;
    }

    return 0;
}
