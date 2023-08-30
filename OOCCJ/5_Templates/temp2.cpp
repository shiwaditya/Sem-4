#include <iostream>

using namespace std;

template <class T>
class Addition {
public:
    T Add(T n1, T n2);
};

template <class T>
T Addition<T>::Add(T n1, T n2) {
    T res;
    res = n1 + n2;
    return res;
}

int main() {
    Addition<int> obj1;
    Addition<long> obj2;
    int A = 10, B = 20, C;
    long I = 11, J = 22, K;

    C = obj1.Add(A, B);
    cout << "\nThe sum of integer values: " << C;

    K = obj2.Add(I, J);
    cout << "\nThe sum of long values: " << K;

    return 0;
}
