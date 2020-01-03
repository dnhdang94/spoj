#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t;
	string s;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> s;
		for (int k = 0; k < s.length() / 2; k += 2)
		{
			cout << s[k];
		}
		cout << endl;
	}

	return 0;
}
