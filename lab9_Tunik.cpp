#include <iostream>
#include <cmath>
using namespace std;

const int ROWS = 4;
const int COLS = 4;

int main() {
    int matrix[ROWS][COLS] = {
        {3, 0, 7, 2},
        {1, 5, 2, 4},
        {8, 6, 3, 9},
        {4, 2, 1, 5}
    };

    int minSideDiag = matrix[0][COLS - 1];
    for (int i = 0; i < ROWS; ++i) {
        int val = matrix[i][COLS - 1 - i];
        if (val < minSideDiag)
            minSideDiag = val;
    }

    int rowProducts[ROWS];
    for (int i = 0; i < ROWS; ++i) {
        int product = 1;
        for (int j = 0; j < COLS; ++j) {
            product *= matrix[i][j];
        }
        rowProducts[i] = product;
    }

    int firstZeroCol = -1;
    for (int j = 0; j < COLS; ++j) {
        for (int i = 0; i < ROWS; ++i) {
            if (matrix[i][j] == 0) {
                firstZeroCol = j;
                break;
            }
        }
        if (firstZeroCol != -1)
            break;
    }

    int sumAboveMainDiag = 0;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = i + 1; j < COLS; ++j) {
            sumAboveMainDiag += abs(matrix[i][j]);
        }
    }

    cout << "Мінімальний елемент побічної діагоналі: " << minSideDiag << endl;

    cout << "Добутки елементів рядків:\n";
    for (int i = 0; i < ROWS; ++i)
        cout << rowProducts[i] << " ";
    cout << endl;

    if (firstZeroCol != -1)
        cout << "Номер першого стовпця з нульовим елементом: " << firstZeroCol << endl;
    else
        cout << "Нульових елементів у стовпцях немає.\n";

    cout << "Сума модулів елементів вище головної діагоналі: " << sumAboveMainDiag << endl;

    return 0;
}
