#include <iostream>
using namespace std;

int main() {
    double a, b;
    cout << "Введіть значення a: ";
    cin >> a;
    cout << "Введіть значення b: ";
    cin >> b;

    double* pA = &a;
    double* pB = &b;

    *pA *= 3;
    *pB /= 3;

    cout << "Значення a після збільшення в 3 рази: " << a << endl;
    cout << "Значення b після зменшення в 3 рази: " << b << endl;

    return 0;
}
