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

  // Open the file in binary mode for both reading and writing
  fstream file("6.txt", ios::in | ios::out | ios::binary);

  // Write S1 object to the file
  file.write((char *)&S1, sizeof(S1));

  // Move the file pointer to the beginning of the file
  file.seekg(0);

  // Read S2 object from the file
  file.read((char *)&S2, sizeof(S2));

  // Print the data of S2 object
  S2.putdata();

  // Close the file
  file.close();

  return 0;
}

