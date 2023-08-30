#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> items;
    int choice, item;

    do {
        cout << "MENU\n";
        cout << "1. Add item\n";
        cout << "2. Remove item\n";
        cout << "3. Find item\n";
        cout << "4. Sort list\n";
        cout << "5. Print list\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item: ";
                cin >> item;
                items.push_back(item);
                break;
            case 2:
                if (items.empty()) {
                    cout << "List is empty\n";
                } else {
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
                break;
            case 3:
                if (items.empty()) {
                    cout << "List is empty\n";
                } else {
                    cout << "Enter item to find: ";
                    cin >> item;
                    auto pos = find(items.begin(), items.end(), item);
                    if (pos == items.end()) {
                        cout << "Item not found\n";
                    } else {
                        cout << "Item found at position " << distance(items.begin(), pos) + 1 << endl;
                    }
                }
                break;
            case 4:
                if (items.empty()) {
                    cout << "List is empty\n";
                } else {
                    sort(items.begin(), items.end());
                    cout << "List sorted\n";
                }
                break;
            case 5:
                if (items.empty()) {
                    cout << "List is empty\n";
                } else {
                    cout << "List of items:\n";
                    for (auto i : items) {
                        cout << i << endl;
                    }
                }
                break;
            case 6:
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid choice\n";
        }

        cout << endl;

    } while (choice != 6);

    return 0;
}
