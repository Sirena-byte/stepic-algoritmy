#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <string>
using namespace std;

struct comparator {
	bool operator()(const pair<string, int> &p1, const pair<string, int> &p2) {
		return (p1.second != p2.second ? p1.second > p2.second : p1.first > p1.first);
	}
};

 // дописать 0 или 1 в код символа (идём из конца в начало)
void assign(map<string, vector<int>> &hc, const int &v, string &s) {
	for (int i = 0; i < s.size(); ++i) {
		hc[string(1, s[i])].emplace(hc[string(1, s[i])].begin(), v);
	}
}

int main() {
	string word;
	cin >> word;//вводим строку
	map<string, int> frequency;
	map<string, vector<int>> huffman_code;
	for (int j = 0; j < word.length(); ++j) {//заполняем контейнер , если ключ не уникален, то увеличиваем на единицу его значение
		++frequency[string(1, word[j])]; // a -> 1
	}
	//количество различных букв k, встречающихся в строке 
	cout << frequency.size() << ' ';
	// 1 вид символов
	if (frequency.size() == 1) {//если буква уникальна
		cout << frequency.size() * frequency[string(1, word[0])] << endl;
		huffman_code[string(1, word[0])].push_back(0);
	}
	// >= 2 подобных символов
	else {
		priority_queue<pair<string, int>, vector<pair<string, int>>, comparator> q; 
		for (map<string, int>::iterator it = frequency.begin(); it != frequency.end(); ++it) q.push(make_pair(it->first, it->second));
		while (q.size() > 1) {
			int freq_1 = q.top().second;
			string c_1 = q.top().first;
			q.pop();
			int freq_2 = q.top().second;
			string c_2 = q.top().first;
			q.pop();
			// 0 к вершине с меньшим приоритетом или слева (при равном приоритете) 
			if (freq_1 <= freq_2) {
				assign(huffman_code, 0, c_1);
				assign(huffman_code, 1, c_2);
			}
			else {
				assign(huffman_code, 1, c_1);
				assign(huffman_code, 0, c_2);
			}
			q.emplace(make_pair(c_1 + c_2, freq_1 + freq_2));
		}
		//размер получившейся закодированной строки
		int cnt = 0;
		map<string, int>::iterator fr_it = frequency.begin();
		for (map<string, vector<int>>::iterator it = huffman_code.begin(); it != huffman_code.end(); ++it) {
			fr_it = frequency.find(it->first);
			cnt += fr_it->second * it->second.size();
		}
		cout << cnt << endl;
	}
	// вывод словаря
	for (map<string, vector<int>>::iterator it = huffman_code.begin(); it != huffman_code.end(); ++it) {
		cout << it->first << ": ";
		for (int i = 0; i < it->second.size(); ++i) cout << it->second[i];
		cout << endl;
	}
	// вывод закодированного слова
	for (int j = 0; j < word.length(); ++j) {
		map<string, vector<int>>::iterator it = huffman_code.find(string(1, word[j]));
		for (int i = 0; i < it->second.size(); ++i) cout << it->second[i];
	}
	return 0;
}