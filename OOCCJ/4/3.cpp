#include<iostream>
#include<fstream>
using namespace std;
int main()
{
ifstream fin;
fin.open("4.txt");
ofstream fout;
fout.open("5.txt");
char ch[30];

fin>>ch;
fout<<ch;
fin.close();
fout.close();

return 0;
}
