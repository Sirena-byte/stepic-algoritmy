#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

pair<int, int> partition(vector<int>& v, int l, int r) {//передаем v=начальные точки отрезков, l=начальный индекс вектора, r=конец вектора
    int random = l + (rand() % static_cast<int>(r - l + 1));//ищем рандомный индекс
    swap(v[l], v[random]);//устанавливаем туда начало
    int x = v[l];//и делаем его опорным эл-том
    pair<int, int> index = { l, l };//заводим пару-->0,0
    for (int i = l + 1; i <= r; ++i) {
        if (v[i] < x) {//если текущий элемент меньше опорного
            index.first++;//--->1
            index.second++;//--->1
            swap(v[index.second], v[i]);//
            swap(v[index.second], v[index.first]);//двигаемся влево
        }
        else if (v[i] == x) {//если текущий равен опорному
            index.second++;//передвигаемся на ячейку 
            swap(v[index.second], v[i]);//вправо
        }
    }
    swap(v[l], v[index.first]);//двигаем элемент влево!!
    return index;
}

void quick3_sort(vector<int>& v, int l, int r) {//передаем v= начальные точки отрезков, l=0,r = крайний индекс массива
    while (l < r) {//пока левый элемент меньше правого
        auto index = partition(v, l, r);
        quick3_sort(v, l, index.first - 1);
        l = index.second + 1;
    }
}

int num_segments(const vector<int>& v1, const vector<int>& v2, int x) {
    auto s = upper_bound(v1.begin(), v1.end(), x);
    auto b= v1.begin();
    auto l = lower_bound(v2.begin(), v2.end(), x);
    auto num_start = s - b;
    auto num_end = l - b;
    return num_start - num_end;
}

int main() {

    srand(time(0));
    int n, m;
    cin >> n >> m;//вводим колимество отрезков и точек

    vector<int> start_segment(n);//точки начала отрезков
    vector<int> end_segment(n);//точки концов отрезков
    for (int i = 0; i < n; ++i) {
        cin >> start_segment[i] >> end_segment[i];//заполняем массивы
    }

    quick3_sort(start_segment, 0, n - 1);//передаем начальные точки отрезков, ??, размер массива(количество индексов
    quick3_sort(end_segment, 0, n - 1);

    for (int i = 0; i < m; ++i) {
        int p;
        cin >> p;
        int res = num_segments(start_segment, end_segment, p);
        cout << res << " ";
    }

    return 0;
}