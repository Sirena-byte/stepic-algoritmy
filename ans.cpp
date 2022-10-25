#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int count;
	cin >> count;
	int a = 0, b = 0;
	for (int i = 0; i < count; ++i)
	{
		int tmp = b;
		int nom = 0;
		cin >> nom;
		b = std::max(a, b) + nom;
		a = tmp;
	}

	cout << b;

	return 0;
}