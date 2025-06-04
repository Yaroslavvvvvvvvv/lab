#include <iostream>
using namespace std;

template <typename T>
void appendElement(T*& arr, int& size, T newElement) {
    T* newArr = new T[size + 1];
    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }
    newArr[size] = newElement;
    delete[] arr;
    arr = newArr;
    ++size;
}

int main() {
    int size = 3;
    int* myArray = new int[size]{1, 2, 3};

    appendElement(myArray, size, 4);

    for (int i = 0; i < size; ++i)
        cout << myArray[i] << " ";

    delete[] myArray;
    return 0;
}
