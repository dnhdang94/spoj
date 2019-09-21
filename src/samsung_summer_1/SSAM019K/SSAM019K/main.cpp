#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

long calculateDigitSum(unsigned long n);
vector<int> decomposeIntoPrime(unsigned long n);

vector<int> decomposeIntoPrime(unsigned long n) {
	unsigned long number = n;
	vector<int> v;

	while (number % 2 == 0) {
		number /= 2;
		v.push_back(2);
	}

	for (long i = 3; i <= (long)sqrt(number); i += 2) {
		while (number % i == 0) {
			number /= i;
			v.push_back(i);
		}
	}

	if (number > 2) {
		v.push_back(number);
	}

	return v;
}

long calculateDigitSum(unsigned long n) {
	long sum = 0;
	unsigned long number = n;

	char digit;
	while (number > 0) {
		digit = number % 10;
		sum += digit;
		number /= 10;
	}

	return sum;
}

int main() {
	unsigned long n, sum1 = 0, sum2 = 0;
	vector<int> v;

	cin >> n;
	sum1 = calculateDigitSum(n);
	v = decomposeIntoPrime(n);
	for (int i = 0; i < v.size(); i++) {
		sum2 += calculateDigitSum(v[i]);
	}

	if (sum1 == sum2) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}
