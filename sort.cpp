#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> vec(10, 0);
	int x, n;
	cin >> n;
	while (n--) {
		cin >> x;
		vec[x - 1]++;
	}
	for (int i = 0; i < vec.size(); i++) {
		while (vec[i]--) cout << i + 1 << ' ';
	}
}