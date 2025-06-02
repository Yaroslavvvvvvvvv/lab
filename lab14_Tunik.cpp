#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(int num) {
    int original = num, reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

void fillPalindromes(vector<int>& arr, int count) {
    int num = 1;
    while (arr.size() < count) {
        if (isPalindrome(num))
            arr.push_back(num);
        ++num;
    }
}

bool binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
            return true;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

int main() {
    vector<int> palindromes;
    fillPalindromes(palindromes, 25);

    cout << "Масив з 25 паліндромів за зростанням:\n";
    for (int p : palindromes)
        cout << p << " ";
    cout << endl;

    int value;
    cout << "Введіть число для пошуку: ";
    cin >> value;

    if (binarySearch(palindromes, value))
        cout << "Число знайдено в масиві." << endl;
    else
        cout << "Число не знайдено в масиві." << endl;

    return 0;
}
