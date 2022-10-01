#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <queue>

using namespace std;

void show_Huffman_map(map<char, string> Huffman_map) {
    for (auto it = Huffman_map.begin(); it != Huffman_map.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
}


map<char, string> get_Huffman_map(string str) {//получает введенную пользователем строку
    //высчитываем частоту встречаемости символа
    //заполняем контейнер парами, состоящими из символа и его повторов
   
    map<char, int> freq;
    for (auto& c : str) {

        freq[c] += 1;
    }
    //организуем массив, для создания графа
    priority_queue<pair<int, string>> q;
 
    //погружаем в него элементы слова
    /*пары: первый элемент= повторы со знаком -, второй сам символ*/
    for (auto it = freq.begin(); it != freq.end(); it++) {//указатель на начало, пока не конец
        //cout<<it->first<<": "<<it->second<<endl;//потом закоментить
        string s;
        s = it->first;//символ
        q.push(make_pair(-it->second, s));//количество повторений
    }
    /**************************************************************************/
    map<char, string> result;
    if (q.size() > 1) {
      
        while (q.size() > 1) {//пока массив пар не пуст
            pair<int, string> p1 = q.top();//берем первую пару
            for (auto& c : p1.second) {//перебираем по вторым элементам р1(формируем код символа)
          
                result[c] = "1" + result[c];
               /*первый элемент пары символ, второй полученный код*/
            }
            
            q.pop();//удаляем
            pair<int, string> p2 = q.top();//берем первую пару
            for (auto& c : p2.second) {//второй элемент пары
                result[c] = "0" + result[c];
            
            }
            
            q.pop();//удаляем
            string s = p1.second + p2.second;//склеиваем символы
            q.push(make_pair(p1.first + p2.first, s));//(
        }
    }
    else {
      
        result[q.top().second[0]] = "0";
    }

    return result;
}

string get_code(map<char, string>Huffman_map, string str) {
    string result;
    for (auto& c : str) {
        result = result + Huffman_map[c];
    }
    return result;
}

int main() {
    string str;//строка символов
    cin >> str;

    map<char, string> Huffman_map = get_Huffman_map(str);
    string answer = get_code(Huffman_map, str);

    cout << Huffman_map.size() << " " << answer.size() << endl;
    show_Huffman_map(Huffman_map);

    cout << answer << endl;
}