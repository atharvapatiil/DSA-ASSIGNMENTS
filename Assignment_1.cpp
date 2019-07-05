/*
    ==========================================================
 	ASSIGNMENT 1 : CALCULATOR USING SWITCH AND CLASSES 
    ==========================================================
 
    Code by: SAHIL HADKE
    Roll No: 17
    Batch: S1
    This assignment can also be used as OOP 1st Assignment.
    Question: Write a code using basic OOP concepts.
*/

#include<iostream>
using namespace std;

class Calc
{
    int num1, num2;
    
public:

    char op;  //operator is declared in public because it is used in switch 

    Calc()  //Constructor
    {
	cout<<"Enter operation to be performed in the format 'number operator number'"<<endl;
	cin>>num1>>op>>num2;
    }

    void Add();        //Adds 2 numbers
    void Subtract();   //Subtracts 2 numbers
    void Multiply();   //Multiplies 2 numbers
    void Divide();     //Divides 2 numbers
    void Mod();        //Returns the remainder of 2 of division of numbers

}; 

void Calc::Add()
{    
    cout<<"Answer: "<<num1+num2<<endl;
}

void Calc::Subtract()
{
    cout<<"Answer: "<<num1-num2<<endl;
}

void Calc::Divide()
{
    cout<<"Answer: "<<(float)num1/num2<<endl;  

    /*
      Some integers when divided give answer in points
      For example: 5/2 = 2.5
      So if we print num1/num2, we get answer as 2 instead of 2.5, beacause
      the compiler will be giving result in int form.
     
      To avoid this, I used typecasting which considers the float value of num1/num2
    */
}

void Calc::Mod()
{
    cout<<"Answer: "<<num1%num2<<endl;
}

void Calc::Multiply()
{
    cout<<"Answer: "<<num1*num2<<endl;
}



int main()
{

    int _condition = 1;

    do{
    	Calc obj;    
	
    	switch(obj.op)
    	{

		case '+':
	    	    obj.Add();
	    	    break;
		case '-':
	    	    obj.Subtract();
	    	    break;
		case '*':
		    obj.Multiply();
		    break;
		case '/':
		    obj.Divide();
		    break;
		case '%':
		    obj.Mod();
		    break;
		default:
		    cout<<"You Entered wrong character"<<endl;
        }

	cout<<"Do you want to continue? \n1: Yes\n0: No\n";
	cin>>_condition;

    }while(_condition);

   /*
	1 = true 
	0 = false
   */

    return 0;
}
