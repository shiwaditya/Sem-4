#include <iostream>
#include <cassert>

using namespace std;

template<typename Item>
Item array_max(Item data[], int n) {
    assert(n > 0);
    Item answer = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] > answer) {
            answer = data[i];
        }
    }
    return answer;
}

int main() {
    int int_array[] = {5, 4, 6, 2, 1};
    double double_array[] = {2.3, 4.3, 1.1, 6.7};
    int max_int = array_max(int_array, 5);
    double max_double = array_max(double_array, 4);
    cout << "Max from int array is: " << max_int << endl;
    cout << "Max from double array is: " << max_double << endl;
    return 0;
}


