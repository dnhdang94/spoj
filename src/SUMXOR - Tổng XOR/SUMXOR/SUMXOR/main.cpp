#include <iostream>
using namespace std;

void decToBinary(int n) { 
	for (int i = 31; i >= 0; i--) {

		int k = n >> i; 
		if (k & 1) {
			cout << "1"; 
		} else {
			cout << "0";
		}
	} 
} 

int debug(int n) {

	int res = 0;

	cout << 0 << " SUMXOR = " << 0;
	cout << " ("; 
	decToBinary(0);
	cout << ")" << endl;
	for (int i = 1; i <= n; i++) {
		res = res ^ i;
		cout << i << " SUMXOR = " << res;
		cout << " ("; 
		decToBinary(i);
		cout << ")" << endl;
	}
	return res;
}

int main() {

	int n;

	cin >> n;

	//for (int i = 1; i <= n; i++) {
	//	debug(n);
	//}

	if (n % 4 == 0) {
		cout << n;
	} else if (n % 4 == 1) {
		cout << 1;
	} else if (n % 4 == 2) {
		cout << n + 1;
	} else {
		cout << 0; 
	}

	return 0;
}