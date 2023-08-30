#include <fstream>
#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;


class hotel{
string name;
int age;
int cust_id;
float income;
string city;
string room_type;
int d;
public:
hotel(){

}
hotel(string n,int a,int cid,float inc,string cy,string rt){
name=n;
age=a;
cust_id=cid;
income=inc;
city=cy;
room_type=rt;
}
void getD(){
cout<<"Enter Your Name"<<endl;
cin>>name;
cout<<"Enter your Customer ID"<<endl;
cin>>cust_id;
getage();
getinc();
getcity();
gettype();
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;

};

void getage()
{
cout<<"Input your age"<<endl;
cin>>age;
try
{
if(age<18 || age>55)
throw age;
else
d++;
}
catch(int n)
{
cout<<"Your Age is does not meet our requirement"<<endl;
}
}

void getinc()
{
cout<<"Input Your income"<<endl;
cin>>income;
try
{
if(income>100000 || income<50000)
throw income;
else
d++;
}
catch(float n)
{
cout<<"Your income should be between the range 50000 - 100000"<<endl;
}
}

void getcity()
{
cout<<"Enter your city"<<endl;
cin>>city;
try
{
if(city=="Pune" || city=="Mumbai")
d++;
else
throw city;
}
catch(string)
{
cout<<"only Mumbai or Pune city are acceptable"<<endl;
}
}

void gettype()
{
cout<<"Which room the type? Deluxe(D) or Super Deluxe(S)"<<endl;
cin>>room_type;
try
{
if(room_type=="D" || room_type=="S")
d++;
else
throw room_type;
}
catch(string)
{
cout<<"Room type must be D(Deluxe) or S(Super DEluxe)"<<endl;
}
}

void showD(){
if(d==4)
{
cout<<"Name is"<<name<<endl;
cout<<"Age is"<<age<<endl;
cout<<"cid is"<<cust_id<<endl;
cout<<"income is"<<income<<endl;
cout<<"City is"<<city<<endl;
cout<<"Room is"<<room_type<<endl;
}
else
{
cout<<"invalid info"<<endl;
}
};
};


int main(){
hotel s;
ofstream file;
file.open("aaa.txt",ios::out);
if(!file){
cout<<"Erorr in opening file"<<endl;
return 0;
}else{
cout<<"File Successfully Created"<<endl;
}

s.getD();
file.write((char*)&s,sizeof(s));
file.close();
cout<<"File closed successfully"<<endl;

ifstream file1;
file1.open("aaa.txt",ios::in);
if(!file1){
cout<<"Erorr in opening file"<<endl;
return 0;
}
else{
file1.read((char*)&s,sizeof(s));
s.showD();
file1.close();
return 0;
}


}
