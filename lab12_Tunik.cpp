#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 5;

void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
}

int productOfMaxIndexSums(int matrix[N][N]) {
    vector<pair<int, pair<int, int>>> diag;

    for (int i = 0; i < N; ++i) {
        int j = N - 1 - i;
        diag.push_back({matrix[i][j], {i, j}});
    }

    sort(diag.begin(), diag.end(), greater<>());

    int sum1 = diag[0].second.first + diag[0].second.second;
    int sum2 = diag[1].second.first + diag[1].second.second;

    return sum1 * sum2;
}

void sortLastColumnDescending(int matrix[N][N]) {
    vector<int> col;
    for (int i = 0; i < N; ++i)
        col.push_back(matrix[i][N - 1]);

    sort(col.begin(), col.end(), greater<>());

    for (int i = 0; i < N; ++i)
        matrix[i][N - 1] = col[i];
}

int main() {
    int matrix[N][N] = {
        {1,  2,  3,  4,  5},
        {6,  7,  8,  9,  10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    cout << "Початковий масив:\n";
    printMatrix(matrix);

    int result = productOfMaxIndexSums(matrix);
    cout << "\nДобуток сум індексів двох максимальних елементів побічної діагоналі: " << result << endl;

    sortLastColumnDescending(matrix);
    cout << "\nМасив після сортування останнього стовпця по спаданню:\n";
    printMatrix(matrix);

    return 0;
}
