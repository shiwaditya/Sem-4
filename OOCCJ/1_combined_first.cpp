#include<iostream>
using namespace std;
int count=0;

class student{
	int roll_no;
	string name;
	int panel;

public:
student(){  //Using Default Constructor
	count++;
	roll_no=4;
	name="abc";
	panel=8;
	cout<<"\n No. of objects created : "<<count;
	cout<<endl;	
}

student(int a,string b,int c){  //parameterized constructors
	count++;
	roll_no=a;
	name=b;
	panel=c;
	cout<<"\n No. of objects created : "<<count;
	cout<<endl;	
}
student(student &p){        //copy constructors
	count++;
	roll_no=p.roll_no;
	name=p.name;
	panel=p.panel;
	cout<<"\n No. of objects created : "<<count;
	cout<<endl;	

}
~student(){       //destructor
	cout<<endl;
	cout<<"\n No. of objects destroyed : "<<count;
	count--;

}

void show_data()
{
	cout <<"Roll No. is: "<<roll_no<<endl;
	cout <<"Name is: "<<name<<endl;
	cout <<"Panel is: "<<panel<<endl;
}
};



int main(){
student object1;
object1.show_data();
student object2(4,"Shiwaditya",8);

object2.show_data();
student object3(object2);
cout<<endl;
object3.show_data();



return 0;
}

