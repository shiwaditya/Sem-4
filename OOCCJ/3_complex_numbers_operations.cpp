#include<iostream>
using namespace std;
int ch;
char choice;
class complex
{
	public:
		double real;
		double imaginary;
	public:	
		complex()
		{
			real=0;
			imaginary=0;
		}
		
		complex(double a,double b)
		{
			real=a;
			imaginary=b;
		}
		
		void getComplex()
		{
			cout<<"Enter the Real part of a number : "<<endl;
			cin>>real;
			cout<<"Enter the Imaginary part of a number : "<<endl;
			cin>>imaginary;
			cout<<endl;
		}
		
		complex operator+(complex c)
		{
			complex temp;
			temp.real=real+c.real;
			temp.imaginary=imaginary+c.imaginary;
			return temp;
		}
		
		
		complex operator-(complex c)
		{
			complex temp;
			temp.real=real-c.real;
			temp.imaginary=imaginary-c.imaginary;
			return temp;
		}
		
		
		complex operator*(complex c)
		{
			complex temp;
			temp.real=real*c.real - imaginary*c.imaginary;
			temp.imaginary=real*c.imaginary + imaginary*c.real;
			return temp;
		}

		complex operator/(complex c)
		{
			complex temp;
			temp.real = (real*c.real + imaginary*c.imaginary)/(c.real*c.real + c.imaginary*c.imaginary);
			temp.imaginary = (imaginary*c.real - real*c.imaginary)/(c.real*c.real + c.imaginary*c.imaginary);
			return temp;
		}

		void printComplex()
		{
	
		cout<<"The Real part of a number is : "<<real<<endl;
		cout<<"The Imaginary part of a number is : "<<imaginary<<endl;
		cout<<"The Number is : "<<real<<"+i"<<imaginary<<endl;
		
		}
};
		
		int main()
		{
		do
		{
		complex c1(3,4),c2(5,6),c3;
		c1.getComplex();
		c2.getComplex();
		c1.printComplex();
		c2.printComplex();
		
		cout<<"Enter the Choice : "<<"1.Addition\n"<<"2.Subtraction\n"<<"3.Product\n"<<"4.Division\n"<<endl;
		cin>>ch;
		
		switch(ch)
		{
		case 1:
			c3=c1+c2;
			c3.printComplex();
		
			break;
		case 2:
			c3=c1-c2;
			c3.printComplex();
			break;
		case 3:
			c3=c1*c2;
			c3.printComplex();
			break;
		case 4:
			c3=c1/c2;
			c3.printComplex();
			break;
		default:
			cout<<"Wrong Input"<<endl;
			break;
		}
		cout<<"Do you want to exit? (y/n) : ";
		cin>>choice;
		}while(choice!='y');
		return 0;
		}
		
