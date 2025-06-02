#include <iostream>
using namespace std;

double recursiveSeries(int n) {
    if (n == 1) return 40;
    return recursiveSeries(n - 1) / 2;
}

int main() {
    int n;
    cout << "Введіть номер члена ряду n: ";
    cin >> n;

    if (n < 1) {
        cout << "Номер члена має бути >= 1" << endl;
    } else {
        cout << n << "-й член ряду: " << recursiveSeries(n) << endl;
    }

    return 0;
}
