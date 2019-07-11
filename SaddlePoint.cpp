/*
    ===================================
       ASSIGNMENT 3 : Saddle Point
    ===================================
    Code by: SAHIL HADKE
    Roll No: 17
    Batch: S1
    Question: Saddle Point
*/

#include<iostream>
using namespace std;

int matrix[100][100];
int row, n, _row, _col, column, i, _min, _max, currentCol;

void getData()
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

void printData()
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

int checkCol(int _col)
{    
    _max = matrix[0][_col];
    for(i = 0; i < n; i++)
    {
        if(matrix[i][_col] > _max)
        {
            _max = matrix[_row][i];            
        }
    }    
    return _max;    
}

void checkRow(int _row)
{
    currentCol = 0;
    _min = matrix[_row][0];
    for(i = 0; i < n; i++)
    {
        if(matrix[_row][i] < _min)
        {
            _min = matrix[_row][i];
            currentCol = i;
        }
    }
    
    if(_min == checkCol(currentCol))
        cout<<"Saddle is "<<_min<<endl;   
}

int main()
{
    int h;
    getData();
    printData();
    for(h = 0; h < n; h++)
    {
        checkRow(h);
    }
    
    return 0;
   
}
