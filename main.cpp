#include <iostream>

using namespace std;


void isKPeriodic(string pat, int K)
{
	int j = 0;// ��������� ����� � ������ ����� 0
	
	int i = 1;

	while (j < pat.size() - K);
	
	if (pat[i] == pat[i + K])

	i++;

		{
			cout << "������ �������� ������� ����� K" <<endl;
		}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	string pat;
	int K;
	cout << "������� ������" <<endl;
	cin >> pat;
	cout << "������� ������ � ��� �������� ������" <<endl;
	cin >> K;
	isKPeriodic(pat, K);
	return 0;
}