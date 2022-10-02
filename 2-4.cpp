#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<int> arr;
int index;

void insert(int x) {
	arr.push_back(x);//добавляем элемент в вектор
	index = arr.size() - 1;
	if (index != 0) {
		while (arr[index] > arr[(index - 1) / 2]) {//если текущий больше своего родителя 
			swap(arr[index], arr[(index - 1) / 2]);//меняем местами
			index = (index - 1) / 2;//индекс сдвигаем
			if (index == 0) break;
		}
	}
}

//извлекает из очереди элемент с максимальным приоритетом
void extractMax() {
	cout << arr[0] << endl;//выводим элемент с нулевым индексом, то есть родителя
	swap(arr[0], arr[arr.size() - 1]);//меняем текущий с последним
	arr.pop_back();//удаляем последний элемент вектора
	index = 0;
	int size = arr.size() - 1;//размер уменьшаем на 1
	while (true) {
		if (index * 2 + 1 > size)break;//проверка на наличие детей
		else if (index * 2 + 2 > size && index * 2 + 1 <= size) {//проверка на 1 ребенка
			if (arr[index * 2 + 1] > arr[index]) {//если ребенок больше родителя
				swap(arr[index * 2 + 1], arr[index]);//меняем местами
			}
			break;
		}
		else {//2 детей
			if (arr[index * 2 + 1] >= arr[index * 2 + 2]) {//если первый ребенок больше второго
				if (arr[index * 2 + 1] > arr[index]) {//и первый больше родителя
					swap(arr[index * 2 + 1], arr[index]);//меняем местами
					index = index * 2 + 1;
				}
				else break;
			}
			else if (arr[index * 2 + 2] >= arr[index * 2 + 1]) {//если второй больше первого
				if (arr[index * 2 + 2] > arr[index]) {//и больше родителя
					swap(arr[index * 2 + 2], arr[index]);//меняем местами
					index = index * 2 + 2;
				}
				else break;
			}
		}
	}
}



int main() {
	string str;
	int n, input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "Insert") {
			cin >> input;
			insert(input);
		}
		else {
			if (arr.size() > 0) extractMax();
		}
	}
	return 0;
}