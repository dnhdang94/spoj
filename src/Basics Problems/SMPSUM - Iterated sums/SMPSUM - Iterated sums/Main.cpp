#include <iostream>

using namespace std;


int main()
{
	int a, b, t;
	long s;

	cin >> a >> b;
	t = b - a;

	s = (t + 1) * a * a + ((t + 1) * t / 2) * 2 * a + t * (t + 1) * (2 * t + 1) / 6;
	cout << s;

	return 0;
}
