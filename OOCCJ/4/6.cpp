#include <iostream>
#include <fstream>
using namespace std;

class student {
    private:
        char name[30];
        int age;
    public:
        void getData(void) {
            cout << "Enter name:";
            cin.getline(name, 30);
            cout << "Enter age:";
            cin >> age;
        }
        void showData(void) {
            cout << "Name:" << name << ", Age:" << age << endl;
        }
};

int main() {
    student s;
    ofstream file; // Declare an object of type ofstream for writing to file
    file.open("4.txt"); // Open the file "4.txt" in write mode (ios::out)
    if (!file) {
        cout << "Error in creating file.." << endl;
        return 0;
    }
    cout << "File created successfully." << endl; // Print success message
    // Write data to file
    s.getData();
    file.write(reinterpret_cast<char*>(&s), sizeof(s));
    file.close(); // Close the file
    cout << "File saved and closed successfully." << endl;
    // Reopen the file in input mode and read data
    ifstream filel; // Declare an object of type ifstream for reading from file
    filel.open("4.txt"); // Open the file "4.txt" in read mode (ios::in)
    if (!filel) {
        cout << "Error in opening file.." << endl;
        return 0;
    }
    // Read data from file
    filel.read((char*)&s, sizeof(s));
    // Display data on monitor
    s.showData();
    // Close the file
    filel.close();
    return 0;
}

