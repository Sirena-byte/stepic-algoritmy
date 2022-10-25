#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

int main()
{
	// —читываем число N
	unsigned  n= 0;
	std::cin>> n;
	/*
	Ѕудем искать минимальное количество операций дл€ каждого числа. ќбозначим result[i] - минимальное число операций
	дл€ числа i. ¬ыразим result[i] через ответы дл€ меньших подзадач. result[i] = min{result[i/3] + 1, result[i/2] + 1, result[i-1] + 1}, причем
	деление выполн€етс€ в случае делимости i нацело.
	*/
	// ѕромежуточные результаты складываем в массив
	std::vector<unsigned > result;
	// ћассив дл€ отслеживани€ промежуточных чисел
	std::vector<std::vector<unsigned >> parents(n+ 1, std::vector<unsigned >());
	result.push_back(0);
	result.push_back(0);       // ƒл€ i = 1 требуетс€ 0 операций
	parents[1].push_back(1); // ƒл€ i = 1 промежуточное значение и есть 1
	for (unsigned  i = 2; i <= n; ++i) {
		unsigned  x_div_3 = std::numeric_limits<int>::max();
		if ((i % 3) == 0) x_div_3 = result[i / 3] + 1;
		unsigned  x_div_2 = std::numeric_limits<int>::max();
		if ((i % 2) == 0) x_div_2 = result[i / 2] + 1;
		unsigned  min_val = std::min({ x_div_3, x_div_2, result[i - 1] + 1 });
		result.push_back(min_val);
		if (min_val == x_div_3) { parents[i] = parents[i / 3]; parents[i].push_back(i); }
		if (min_val == x_div_2) { parents[i] = parents[i / 2]; parents[i].push_back(i); }
		if (min_val == result[i - 1] + 1) { parents[i] = parents[i - 1]; parents[i].push_back(i); }
	}
	std::cout << result[n] << std::endl;
	// ¬осстанавливаем решение
	for (auto elem : parents[n]) std::cout << elem << " ";
	std::cout << std::endl;
	return 0;
}