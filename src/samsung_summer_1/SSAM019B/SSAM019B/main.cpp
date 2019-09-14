#include <iostream>
#include <vector>
#include <set>

using namespace std;

int findFirstRepeating(const vector<int>& v);

int findFirstRepeating(const vector<int>& v) {
	int min = -1, size = v.size();
	set<int> s;

	for (int i = size - 1; i >= 0; i--) {
		if (s.find(v[i]) == s.end()) {
			s.insert(v[i]);
		}
		else {
			min = i;
		}
	}

	return min;
}

int main()
{
	int T, N;

	cin >> T;
	for (int k = 0; k < T; k++) {
		vector<int> v;
		int n, res;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> n;
			v.push_back(n);
		}

		res = findFirstRepeating(v);
		if (res == -1) {
			cout << "NO\n";
		}
		else {
			cout << v[res] << "\n";
		}
	}
}