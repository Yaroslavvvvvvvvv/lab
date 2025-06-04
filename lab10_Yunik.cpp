#include <iostream>
#include <string>
using namespace std;

struct Microprocessor {
    string name;
    string firm;
    float frequency;
    int pins;
};

void printList(Microprocessor arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Назва: " << arr[i].name << ", "
             << "Фірма: " << arr[i].firm << ", "
             << "Частота: " << arr[i].frequency << " GHz, "
             << "Контактів: " << arr[i].pins << endl;
    }
}

void renameAMD(Microprocessor arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i].firm == "AMD")
            arr[i].name = "Celeron";
    }
}

int main() {
    const int SIZE = 5;
    Microprocessor stock[SIZE] = {
        {"Pentium", "IDC", 3.2, 1151},
        {"Athlon", "AMD", 2.8, 940},
        {"Duron", "Motorola", 2.5, 754},
        {"Celeron", "Texas Instrument", 2.0, 775},
        {"Athlon", "AMD", 3.0, 940}
    };

    cout << "Початковий список:\n";
    printList(stock, SIZE);

    renameAMD(stock, SIZE);

    cout << "\nПісля перейменування AMD на Celeron:\n";
    printList(stock, SIZE);

    return 0;
}
