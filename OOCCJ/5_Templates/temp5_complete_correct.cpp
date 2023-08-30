#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void addItem(vector<int>& items);
void removeItem(vector<int>& items);
void findItem(const vector<int>& items);
void sortList(vector<int>& items);
void reverseList(vector<int>& items);
void printList(const vector<int>& items);

int main() {
    vector<int> items;
    int choice;

    do {
        cout << "MENU\n";
        cout << "1. Add item\n";
        cout << "2. Remove item\n";
        cout << "3. Find item\n";
        cout << "4. Sort list\n";
        cout << "5. Reverse list\n";
        cout << "6. Print list\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addItem(items);
                break;
            case 2:
                removeItem(items);
                break;
            case 3:
                findItem(items);
                break;
            case 4:
                sortList(items);
                break;
            case 5:
                reverseList(items);
                break;
            case 6:
                printList(items);
                break;
            case 7:
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid choice\n";
        }

        cout << endl;

    } while (choice != 7);

    return 0;
}

void addItem(vector<int>& items) {
    int item;
    cout << "Enter item: ";
    cin >> item;
    items.push_back(item);
}

void removeItem(vector<int>& items) {
    if (items.empty()) {
        cout << "List is empty\n";
    } else {
        int item;
        cout << "Enter item to remove: ";
        cin >> item;
        auto pos = find(items.begin(), items.end(), item);
        if (pos == items.end()) {
            cout << "Item not found\n";
        } else {
            items.erase(pos);
            cout << "Item removed\n";
        }
    }
}

void findItem(const vector<int>& items) {
    if (items.empty()) {
        cout << "List is empty\n";
    } else {
        int item;
        cout << "Enter item to find: ";
        cin >> item;
        auto pos = find(items.begin(), items.end(), item);
        if (pos == items.end()) {
            cout << "Item not found\n";
        } else {
            cout << "Item found at position " << distance(items.begin(), pos) + 1 << endl;
        }
    }
}

void sortList(vector<int>& items) {
    if (items.empty()) {
        cout << "List is empty\n";
    } else {
        sort(items.begin(), items.end());
        cout << "List sorted\n";
    }
}

void reverseList(vector<int>& items) {
    if (items.empty()) {
        cout << "List is empty\n";
    } else {
        reverse(items.begin(), items.end());
        cout << "List reversed\n";
    }
}

void printList(const vector<int>& items) {
    if (items.empty()) {
        cout << "List is empty\n";
    } else {
        cout << "List of items:\n";
        for (auto i : items) {
            cout << i << endl;
        }
    }
}
