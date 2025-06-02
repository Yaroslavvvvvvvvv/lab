#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<double>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] < arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void selectionSort(vector<double>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int maxIdx = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[j] > arr[maxIdx])
                maxIdx = j;
        swap(arr[i], arr[maxIdx]);
    }
}

void insertionSort(vector<double>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        double key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int partition(vector<double>& arr, int low, int high) {
    double pivot = arr[high];
    int i = low;
    for (int j = low; j < high; ++j) {
        if (arr[j] > pivot) {
            swap(arr[i], arr[j]);
            ++i;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void quickSort(vector<double>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(const vector<double>& arr) {
    for (double val : arr)
        cout << val << " ";
    cout << endl;
}

int main() {
    vector<double> a = {12.5, 33.2, 45.0, 28.9, 17.1, 6.6, 91.3, 82.4, 35.6, 48.1,
                        13.9, 24.5, 37.7, 55.8, 61.6, 70.0, 39.9, 5.5, 18.3, 27.0};

    vector<double> b;
    for (int i = 0; i < a.size(); ++i)
        if (static_cast<int>(a[i]) % 2 != 0)
            b.push_back(a[i]);

    cout << "Масив a:\n";
    printArray(a);
    cout << "Непарні елементи (масив b):\n";
    printArray(b);

    vector<double> b1 = b, b2 = b, b3 = b, b4 = b;

    bubbleSort(b1);
    cout << "Сортування бульбашкою:\n";
    printArray(b1);

    selectionSort(b2);
    cout << "Сортування вибором:\n";
    printArray(b2);

    insertionSort(b3);
    cout << "Сортування вставкою:\n";
    printArray(b3);

    quickSort(b4, 0, b4.size() - 1);
    cout << "Швидке сортування:\n";
    printArray(b4);

    return 0;
}
