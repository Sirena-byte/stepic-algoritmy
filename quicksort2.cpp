#include <iostream>
#include <string>
#include <vector>

using namespace std;
//двигаем элементы счетчиков друг к другу, пока левый не  встретит элемент больше опорно , а  правый - меньше опорного. тогда элементы меняются местами. как только замена была произведена, смещаем i вправо, а j влево, сравниваем i с опорным элементом. как только i становится больше j первый этап заканчивается
//второй этап: счетчики расставляются на оставшемся участке: i на прежнем месте, j в конец

void quiteSort(vector<int>& a, int i, int j) {//вектор, i=0, j= последний индекс вектора
    int leftPointer = i;
    int rightPointer = j;
    auto referens = a[(leftPointer + rightPointer) >> 1];//сдвигаем
    while (leftPointer < rightPointer) {
        while (a[leftPointer] < referens) {//левый меньше опорного
            leftPointer++;//двигаем дальше
        }
        while (referens < a[rightPointer]) {//опорный меньше правого
            rightPointer--;//двигаем влево
        }
        if (leftPointer <= rightPointer) {//если правый больше или равен левому- меняем их местами, сдвигаем левый вправо, правый- влево
            swap(a[leftPointer], a[rightPointer]);
            leftPointer++; rightPointer--;
        }
    }
    if (leftPointer < j) {
        quiteSort(a, leftPointer, j);//если левый больше правого, то левый остается на месте, правый идет в конец и сортируется этот участок массива
    }
    if (i < rightPointer) {
        quiteSort(a, i, rightPointer);
    }
}


int searchPoint(const vector<int>& a, int k, bool last = false) {
    int leftPointer = 0;//начало
    int rightPointer = (int)a.size() - 1;//конец
    while (leftPointer <= rightPointer) {
        int referens = (leftPointer + rightPointer) >> 1;
        if (k > a[referens] || (k == a[referens] && last)) {
            leftPointer = referens + 1;//то идем в ячейку на единицу больше опорной
        }
        else {
            rightPointer = referens - 1;//если меньше, то на единицу меноше опорной
        }
    }
    return leftPointer;//возвращаем количество точек попавших в начало отрезка
}


int main() {
    unsigned int n;
    unsigned int m;
    cin >> n >> m;//количество отрезков, количество точек
    auto leftA= vector<int>(n);//левый вектор
    auto rightA = vector<int>(n);//правый вектор
    for (int i = 0; i < n; i++) {
        cin >> leftA[i] >> rightA[i];//заполняем
    }
    quiteSort(leftA, 0, n - 1);
    quiteSort(rightA, 0, n - 1);
    int k;
    for (int i = 0; i < m; i++) {
        cin >> k;
        cout << searchPoint(leftA, k, true) - searchPoint(rightA, k) << " ";
    }
    cout << endl;
    return 0;
}