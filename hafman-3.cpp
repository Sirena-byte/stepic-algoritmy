#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int n=0;
	vector<int> a(26,0);//сюда пихаю сколько раз символ появлялся в строке
	vector<string> s555(52, "");//тут двоичный код для символа
	vector<pair<int, int>> mest(52, { -1,-1 });//сюда пихаю детей для вершины(левое и правое)
	for (int i = 0; i < s.size(); i++) {
		a[s[i] - 97]++;//исмвол "а" в т. аски 97
	}
	for (int i = 0; i < 26; i++) {
		if (a[i] > 0) {
			n++;
		}
	}
	for (int i = 26; i < 25+n; i++) {//тут ищу 2 символа,которые встречаются меньше всего раз в строке
		int i1=-1, i2=-1, z1=100000, z2=100000;
		for (int j=0;j<i;j++){
			if (a[j] < z1 && a[j] > 0) {
				i1 = j;
				z1 = a[j];
			}
		}
		a[i1] = -1;
		for (int j = 0; j < i; j++) {
			if (a[j] < z2 && a[j] > 0) {
				i2 = j;
				z2 = a[j];
			}
		}
		
		a[i2] = -1;
		a.push_back(z2 + z1);//добавляю для этих двух символов родителя 
		mest[i].first = i1;
		mest[i].second = i2;
	}
	for (int i = 25 + n - 1; i > 25; i--) {//когда у меня остался 1 символ ,то это корень дерева
		s555[mest[i].first] += s555[i];//теперь иду от него и для каждого ребенка добавляю
		s555[mest[i].second] += s555[i];//двоичный код родителя + 1, если правый, или + 0 ,если левый
		s555[mest[i].first] += "0";
		s555[mest[i].second] += "1";
	}
	string sans = "";
	if (n == 1) {//эта часть программы работает ,когда в строке лишь один знак,который может повторяться
		for (int i = 0; i < 26; i++) {
			if (a[i] != 0) {
				s555[i] += "0";
				break;
			}
		}
	}
	for (int i = 0; i < s.size(); i++) {//строю двоичный код
		sans += s555[s[i] - 97];
	}
	int m1 = sans.size();//размер этого кода
	cout << n << " " << m1<<endl;
	for (int i = 0; i < 26; i++) {
		if (a[i] !=0) {
			cout << char(97+i) << ": " << s555[i] << endl;//вывожу коды для каждого символа
		}
	}
	cout << sans;
	return 0;
}