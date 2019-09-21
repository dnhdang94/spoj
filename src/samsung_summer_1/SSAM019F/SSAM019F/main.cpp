#include <iostream>

using namespace std;

long long int findFibo(int n);

long long int findFibo(int n) {
	if (n < 3) {
		return 1;
	}

	long long int f_n1 = 1, f_n2 = 1, sum;
	for (int i = 3; i <= n; i++) {
		sum = f_n1 + f_n2;
		f_n1 = f_n2;
		f_n2 = sum;
	}

	return sum;
}

int main() {
	int t, n;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << findFibo(n) << "\n";
	}

	return 0;
}
