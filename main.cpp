#include <iostream>

using namespace std;


bool isKPeriodic(string pat, int K)
{
	for (int j = 0; j < pat.length() - K; j++)
	{
		if (pat[j] == pat[j + K])
		{
			cout << "the string is a multiple of K!" << j << endl;
			return true;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	string pat;
	int K;
	cout << "Enter your string" <<endl;
	cin >> pat;
	cout << "Enter K for checking string" <<endl;
	cin >> K;
	isKPeriodic(pat, K);
	return 0;
}