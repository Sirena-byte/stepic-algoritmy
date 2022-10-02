#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int get_pos(const vector<int>& numbers, int number) {//принимает вектор по ссылке и искомое число
    size_t l = 0;//начало
    size_t r = numbers.size() - 1;//конец
    while (l <= r) {//пока вектор не пуст
        size_t m = (l + r) / 2;//m= середина
        if (numbers[m] == number) {//если число совпало
            return m + 1;//возвращаем индекс+1(так как индексация начинается с нуля)
        }
        else if (numbers[m] < number) {//если искомое число больше срединного
            l = m + 1;//сдвигаем начало на единице больше середины
        }
        else {
            if (m == 0) {//если не нашли выходим
                break;
            }
            r = m - 1;//если искомое число меньше указателя на середину, то конец на единицу левее, чем середина
        }
    }
    return -1;//если не нашли возвращаем -1
}

int main() {
    size_t number_count;
    cin >> number_count;//размер массива
    vector<int> numbers(number_count);//массив
    for (auto& number : numbers) {
        cin >> number;//заполняем
    }
    assert(is_sorted(numbers.begin(), numbers.end()));// assert проверяет на истину (в данном случае проверяет отсортирован ли массив)

    size_t query_count;
    cin >> query_count;
    while (query_count-- > 0) {
        int number;
        cin >> number;
        cout << get_pos(numbers, number) << " ";//мечатаем индекс
    }
    cout << endl;
}