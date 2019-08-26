#include <iostream>
#include <tuple>

using namespace std;

typedef unsigned long long ll;

pair<ll, ll> factor(ll n);
ll pow(ll a, ll d, ll n);
bool test_a(ll s, ll d, ll n, ll a);
bool miller(ll n);
uint64_t mulmod(uint64_t a, uint64_t b, uint64_t n);

pair<ll, ll> factor(ll n) {
	ll s = 0;
	while ((n & 1) == 0) {
		s++;
		n >>= 1;
	}
	return{ s, n };
}

ll pow(ll a, ll d, ll n) {
	ll result = 1;
	a = a % n;
	while (d > 0) {
		if (d & 1) result = result * a % n;
		d >>= 1;
		a = mulmod(a, a, n);
	}
	return result;
}

bool test_a(ll s, ll d, ll n, ll a) {
	if (n == a) return true;
	ll p = pow(a, d, n);
	if (p == 1) return true;
	for (; s > 0; s--) {
		if (p == n - 1) return true;
		p = mulmod(p, p, n);
	}
	return false;
}

bool miller(ll n) {
	if (n < 2) return false;
	if ((n & 1) == 0) return n == 2;
	ll s, d;
	tie(s, d) = factor(n - 1);
	return test_a(s, d, n, 2) && test_a(s, d, n, 3);
}

uint64_t mulmod(uint64_t a, uint64_t b, uint64_t n) {
	// if (a >= n) a %= n;   /* Careful attention from the caller */
	// if (b >= n) b %= n;   /* should make these unnecessary.    */
	uint64_t r = 0;
	if ((a | b) < (1ULL << 32)) return (a*b) % n;
	if (a < b) { uint64_t t = a; a = b; b = t; }
	if (n <= (1ULL << 63)) {
		while (b > 0) {
			if (b & 1) { r += a;  if (r >= n) r -= n; }
			b >>= 1;
			if (b) { a += a;  if (a >= n) a -= n; }
		}
	}
	else {
		while (b > 0) {
			if (b & 1)  r = ((n - r) > a) ? r + a : r + a - n;    /* r = (r + a) % n */
			b >>= 1;
			if (b)      a = ((n - a) > a) ? a + a : a + a - n;    /* a = (a + a) % n */
		}
	}
	return r;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int m, n; cin >> m >> n;
		for (int i = m; i <= n; i++) if (miller(i)) {
			cout << i << '\n';
		}
		cout << '\n';
	}
}