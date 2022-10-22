#include <iostream>
#include <vector>

template <class Type>
int numbers(const std::vector<Type>& A) {
    std::vector<Type> D(A.size(), 1);//в векторе храним последовательности чисел

    for (size_t i = 1; i < A.size(); ++i) {
        D[i] = 1;
        for (size_t j = 0; j < i; ++j) {
            if (A[i] % A[j] == 0 && D[j] + 1 > D[i]) {//сравниваем поочередно все элементы с остальными элементами массива, если числа делятся без остатка и мы нашли число большее, чем найденное предыдущее, тоо запоминаем его в массив
                D[i] = D[j] + 1;

            }
        }
    }
        //ищем максимальную последовательность
        int ans = 0;
        for (size_t i = 0; i < A.size(); ++i) {
            ans = std::max(ans, D[i]);
        }

        return ans;
    }


    int main() {
        int n;
        std::cin >> n;
        std::vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> A[i];
        }

        std::cout << numbers(A);

        return 0;
    }
