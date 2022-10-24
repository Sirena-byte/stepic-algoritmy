#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	unsigned int capacity, num;
	cin >> capacity >> num;//вместимость рюкзака, число золотых слитков
	vector<int> weights(num);//веса золотых слитков
	for (int j = 0; j < num; ++j) cin >> weights[j];

	vector<int> prev(capacity + 1, 0);//предыдущий
	vector<int> current(capacity + 1);//текущий
	for (int i = 0; i < num; ++i) {
		current[0] = 0;
		for (int j = 1; j < current.size(); ++j) {
			if (weights[i] <= j) current[j] = max(prev[j], prev[j - weights[i]] + weights[i]);
			else current[j] = prev[j];
		}
		current.swap(prev);//переставляем текущий на предыдущий
	}
	cout << prev[capacity];//макс вес, который можно унести в рюкзаке
	return 0;
}

