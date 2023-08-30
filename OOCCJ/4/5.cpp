#include <iostream>
#include <fstream>
using namespace std;

class Student
{
  int rollno;
  string name;

public:
  void getdata()
  {
    cout << "Enter roll no & name of student: ";
    cin >> rollno >> name;
  }

  void putdata()
  {
    cout << "Roll: " << rollno << endl;
    cout << "Name: " << name << endl;
  }
};

int main()
{
  Student S1, S2;
  S1.getdata();
  fstream file;
  file.open("6.txt", ios::binary);
  file.write((char *)&S1, sizeof(S1));
  file.read((char *)&S2, sizeof(S2));
  S2.putdata();
  file.close();

  return 0;
}

