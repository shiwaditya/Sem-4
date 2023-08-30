#include<iostream>
#include<fstream>
using namespace std;
int main()
{
string str;
ifstream fin;
fin.open("3.txt");
getline(fin,str);
cout<<"Data of file is: "<<endl;
cout<<str<<endl;;


fin.close();
return 0;
}
