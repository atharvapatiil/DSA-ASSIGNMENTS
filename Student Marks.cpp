/*
    ==============================
     ASSIGNMENT 2 : Student Marks
    ==============================
    Code by: SAHIL HADKE
    Roll Number: 17
    Batch: S1
    Question: Write a code that takes number of marks obtained by students of DSA as input.
              If the student is absent Enter -1 as Marks.
              1. Calculate Average.
              2. Display the maximum marks obtained.
              3. Display the minimum marks obtained.
              4. Display the same marks scored by many students.
*/

#include<iostream>
using namespace std;

class MyClass
{
    int n,i,p;
    int marks[100];
    int _count[100];
    float total;


public:
    MyClass()
    {
        cout<<"Enter the number of students : ";
        cin>>n;
        cout<<endl;
    }

    void getData();
    void Average();
    void MaxMarks();
    void MinMarks();
    void MaxSameMarks();

};

//Gets User Input
void MyClass::getData()
{
    cout<<"If the student is absent, enter -1"<<endl;
    for(i = 0; i < n; i++)
    {
        cout<<"Enter the marks of Student "<<i+1<<": ";
        cin>>marks[i];
        cout<<endl;
    }
}


//Calculates Average marks and displays it
void MyClass::Average()
{
    total = 0;
    p = 0;
    for(i = 0; i < n; i++)
    {
        if(marks[i] != -1)
        {
            total += marks[i];
            p++;
        }
    }
    cout<<"The avg. marks scored arr: "<<total/p<<endl;
}


//Displays the Maximum Marks Scored
void MyClass::MaxMarks()
{
    total = 0; //Here used as maximum count
    p = 0;     //Here used to store roll number of toper
    for(i = 0; i < n; i++)
    {
        if(marks[i] > total)
        {
            total = marks[i];
            p = i + 1;
        }
    }
    cout<<"Maximum Marks Scored: "<<total<<endl;
    cout<<"Maximum Marks Scored by Roll No. : "<<p<<endl;
}


//Displays the Minimum Marks Scored
void MyClass::MinMarks()
{
    total = marks[0]; //Here used as Minimum count
    p = 1;     //Here used to store roll number of minimum marks obtained
    for(i = 0; i < n; i++)
    {
        if((marks[i] < total) && (marks[i] != -1))
        {
            total = marks[i];
            p = i + 1;
        }
    }
    cout<<"Minimum Marks Scored: "<<total<<endl;
    cout<<"Minimum Marks Scored by Roll No. : "<<p<<endl;
}


//Displays the Marks which occur many times
void MyClass::MaxSameMarks()
{
    total = 0; //no of students occur many times
    p = 0;     //Max Number Marks
    for(i = 0; i < 100; i++)  //Sets every element of array _count to zero.
    {
        _count[i] = 0;
    }

    for(i = 0; i < n; i++)  //increments the elements in array _count as per marks array
    {
        if(marks[i] == -1)
        {
            _count[marks[i] - 1] = 0;
        }
        else
        {
             _count[marks[i] - 1] +=1;
        }
    }

    for(i = 0; i < 100; i++)  //Iteration for checking the marks which occur most of the time
    {
       if(total < _count[i])
       {
           total = _count[i];
           p = i + 1;
       }
    }

    for(i = 0; i < 100; i++) //Iteration for printing the max no. of marks along with no. of students
    {
        if(_count[i] == total)
        {
            cout<<_count[i]<<" student(s) scored "<<i+1<<" marks"<<endl;
        }
    }
}



//Main
int main()
{
    MyClass obj;
    obj.getData();
    cout<<endl;
    obj.Average();
    cout<<endl;
    obj.MaxMarks();
    cout<<endl;
    obj.MinMarks();
    cout<<endl;
    obj.MaxSameMarks();

    return 0;
}
