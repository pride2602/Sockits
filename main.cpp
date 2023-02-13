#include <iostream>

using namespace std;


void isKPeriodic(string pat, int K)
{
	int j = 0;// кратность числа К всегда равна 0
	
	int i = 1;

	while (j < pat.size() - K);
	
	if (pat[i] == pat[i + K])

	i++;

		{
			cout << "строка является кратной числу K" <<endl;
		}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	string pat;
	int K;
	cout << "Введите строку" <<endl;
	cin >> pat;
	cout << "Введите индекс К для проверки строки" <<endl;
	cin >> K;
	isKPeriodic(pat, K);
	return 0;
}