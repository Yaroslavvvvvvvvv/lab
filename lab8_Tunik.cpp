#include <iostream>
#include <cmath>
using namespace std;

bool isFibonacci(int n) {
    int x1 = 5 * n * n + 4;
    int x2 = 5 * n * n - 4;
    int s1 = sqrt(x1);
    int s2 = sqrt(x2);
    return s1 * s1 == x1 || s2 * s2 == x2;
}

int main() {
    const int SIZE = 30;
    int arr[SIZE] = {
        0, 1, 2, 3, 4, 5, 6, 8, 10, 13,
        14, 15, 21, 22, 23, 34, 35, 36, 55, 60,
        1, 2, 3, 89, 100, 144, 233, 377, 610, 987
    };

    cout << "Fibonacci numbers in the array:\n";
    for (int i = 0; i < SIZE; ++i) {
        if (isFibonacci(arr[i]))
            cout << arr[i] << " ";
    }

    return 0;
}
