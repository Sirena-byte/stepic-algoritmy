//Первая строка содержит число  n ,
//вторая — массив A[1…n], содержащий натуральные числа.
//Необходимо посчитать число пар индексов
// 1≤i<j≤n, для которых A[i]>A[j].
// (Такая пара элементов называется инверсией массива.
// Количество инверсий в массиве является в некотором смысле его
// мерой неупорядоченности: например, в упорядоченном по неубыванию
// массиве инверсий нет вообще, а в массиве, упорядоченном по убыванию,
// инверсию образуют каждые два элемента.)

// для корректного подсчета количества инверсий к входным
// данным добавляются нули в начале, чтобы количество элементов было всегда
#include <algorithm>// sort
#include <cstddef>// size_t
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
// работаем исключительно на стеках,а не на массивах

stack<size_t> reverse(stack <size_t>& s) {// функция реверса стека
    stack<size_t> rez;

    while (!s.empty()) {//пока не пусто
        rez.push(s.top());//добавляем элемент в результирующий массив 
        s.pop();//удаляем его из входного массива
    }

    return rez;//возвращаем перевернутый массив
}

// распечатка стека
void printStack(stack <size_t> s) {
    while (!s.empty()) {
        cout << s.top() << " ";//берем первый
        s.pop();//удаляем
    }
    cout << endl;
}

stack<size_t> merge(stack<size_t>& st_b, stack<size_t>& st_c, size_t& count) {
    // на входе функции имеем
    // два отсортированных(по ворастанию) стека,
    // которые требуется слить в один
    // b[] = {1, 3, 4, 7}
    // c[] = {2, 5, 6, 8}

    stack<size_t> rez;//результирующий массив - слияние двух массивов

    while (!st_b.empty() && !st_c.empty()) {
        if (st_b.top() <= st_c.top()) {//если элемент первого подмассива меньше или равен 
            rez.push(st_b.top());//добавляем в результат
            st_b.pop();//удаляем
        }
        else if (st_b.top() > st_c.top()) {//проверка не выполняется,
            // если сработал другой if
            rez.push(st_c.top());
            st_c.pop();
            count += st_b.size();
        }
    }

    if (st_c.empty()) {//если массив st_c закончился
        while (!st_b.empty()) {
            rez.push(st_b.top());//добавляем st_b до конца
            st_b.pop();
        }
    }
    if (st_b.empty()) {
        while (!st_c.empty()) {
            rez.push(st_c.top());
            st_c.pop();
        }
    }

    return reverse(rez);//возвращаем отсортированный массив
}

// вмешний итеративный алгоритм, использующий Merge

stack<size_t> iterativeMergeSort(vector<size_t>& A, size_t& count) {//делим поэлементно на единичные стеки
    queue<stack <size_t>> q;// создаем очередь, состоящую из стеков;

    size_t i = 0;
    while (i < A.size()) {//заполняем очередь стеками
        stack <size_t> temp;
        temp.push(A[i]);
        q.push(temp);
        i++;
    }// работает верно

    while (q.size() != 1) {
        stack<size_t> buf = q.front();//вынимаем и запоминаем первый элемент очереди
        q.pop();// теперь он нам не нужен
        q.push(merge(buf, q.front(), count));
        // вынимаем из очереди два первых элемента, мерджим их,
        // результат кладем в конец очереди
        q.pop();// второй элемент сравнения больше не нужен
        //PrintStack(q.back());// распечатка положенного в очередь стека
    }

    return q.front();
}

size_t logC(size_t& n) {
    size_t pow = 0;
    size_t n_copy = n;
    while (n_copy > 0) {
        n_copy >>= 1;
        pow++;
    }
    return pow;
}

int main() {
    vector <size_t> array;
    size_t n;// количество элементов во входном массиве
    cin >> n;

    size_t cheat = logC(n); // ближайшая степень
    // двойки к исходному количеству элементов
    size_t n1 = 1;
    while (cheat-- != 0) {
        n1 *= 2;
    }
    size_t count_zero = n1 - n;
    // дополняем количество элементов массива до 2^cheat.
    // Т.о. создаем идеальные условия сортировки.
    while (count_zero-- != 0) {
        array.push_back(0);
    }
    while (n-- > 0) {
        int a;
        cin >> a;
        array.push_back(a);
    }// заполняем входной массив элементами с клавиатуры;

    // распечатка модифицированного входного массива
//    size_t j = 0;
//    while(j < array.size()) {
//        cout << array[j] << " ";
//        j++;
//    }

    size_t count = 0;// количество инверсий в массиве
    stack<size_t> result = iterativeMergeSort(array, count);

    //  PrintStack(result);

    cout << count << endl;

    return  0;
}