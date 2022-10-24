#include <iostream>         //mid- индекс текущего эл
#include <vector>           //pos-
                            //low- длинаа последовательности
#include <algorithm>


template <class Type>
std::vector<int> LNIS_bottom_up_bs(const std::vector<Type>& A) {//формируется неубывающая последовательность

    int n = A.size(), len = 0;
    std::vector<int> D(n + 1), P(n);//создаем два вектора 

    // current <= last: Append current element
    // current > last : Replace it with current element
    //нахождение длины последовательности
    for (int i = 0; i < n; ++i) {

        int low = 1;//
        int high = len;//
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (A[D[mid]] >= A[i])
                low = mid + 1;//если текущий меньше или равен последнему,добавить текущий элемент
            else 
                high = mid - 1;
        }
        int pos = low;//текущий
        // Parent (backtrack)
        //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        P[i] = D[pos - 1];
        D[pos] = i;
        if (pos > len) len = pos;//текущий > последний : заменить его текущим элементом
    }
    int k = D[len];
    std::vector<int> seq(len);
    for (int i = 0; i < len; ++i) {
        seq[len - 1 - i] = k + 1;//запонляется с конца
        k = P[k];
    }

    return seq;
}

int main() {//ЗАПОЛНЯЕМ ВЕКТОР ЧИСЛАМИ
    int n;
    std::cin >> n;
    std::vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> A[i];
    }

    std::vector<int> seq = LNIS_bottom_up_bs(A);
    std::cout << seq.size() << std::endl;//длина невозрастающая послеедовательности
    for (size_t i = 0; i < seq.size(); ++i) {
        std::cout << seq[i] << " ";//последовательность
    }

    return 0;
}