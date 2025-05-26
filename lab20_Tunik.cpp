#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

bool isFibonacci(int n) {

    int x1 = 5 * n * n + 4;
    int x2 = 5 * n * n - 4;
    int s1 = (int)std::sqrt(x1);
    int s2 = (int)std::sqrt(x2);
    return (s1 * s1 == x1) || (s2 * s2 == x2);
}

int main() {
    std::srand(std::time(nullptr)); 
    std::vector<int> vec(30);

    for (int i = 0; i < 30; ++i) {
        vec[i] = std::rand() % 101;
    }

    std::cout << "Вектор з 30 елементів:\n";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << "\n\nЧисла Фібоначчі у векторі:\n";


    for (int num : vec) {
        if (isFibonacci(num)) {
            std::cout << num << " ";
        }
    }

    std::cout << std::endl;
    return 0;
}
