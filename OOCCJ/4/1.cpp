#include<iostream>
#include<fstream>
using namespace std;
int main()
{
ifstream fin;
fin.open("1.txt");
ofstream fout;
fout.open("2.txt");
char ch;

fin.get(ch);
fout.put(ch);
fin.close();
fout.close();

return 0;
}
