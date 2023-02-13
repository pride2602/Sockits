#include <iostream>

using namespace std;


void isKPeriodic(string pat, int K)
{
	int j = 0;
	
	int i = 1;

	while (j < pat.size() - K);
	
	if (pat[i] == pat[i + K])

	i++;

		{
			cout << "the string is a multiple of K!" <<endl;
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