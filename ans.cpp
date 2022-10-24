#include <iostream>
#include <vector>
#include <string>

using namespace std;

int min(int a, int b)
{
    return a > b ? b : a;
}

int main()
{
    string Str1, Str2;

    cin >> Str1;
    cin >> Str2;

    vector<int> Current, Prev;//текущий, предыдущий

    Current.resize(Str1.length() + 1);//размер вектора на ячейку больше строки
    Prev.resize(Str1.length() + 1);//размер вектораа на ячейку больше строки

    for (int i = 0; i < Current.size(); ++i)
        Prev[i] = i;//->от 0 до 5

    for (int i = 1; i < Str2.length() + 1; ++i)
    {
        Current[0] = i;
        for (int j = 1; j < Current.size(); ++j)
        {
            int Del = Current[j - 1] + 1, Repl = 1 - (Str1[j - 1] == Str2[i - 1]) + Prev[j - 1], Add = Prev[j] + 1;

            Current[j] = min(Del, min(Repl, Add));//инициализируем ячейку минимальным значением
        }
        Prev = Current;
    }

    cout << Current[Current.size() - 1];

    return 0;
}