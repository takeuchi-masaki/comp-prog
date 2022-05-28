#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
vector<long long> fact;

void initFact(int n, int p) {
	fact = vector<long long>(n + 1);
	fact[0] = fact[1] = 1;
	for (int i = 2; i <= n; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= p;
	}
}

long long powmod(long long a, long long b, long long p) {
	a %= p;
	if (a == 0) return 0;
	long long product = 1;
	while (b > 0) {
		if (b & 1) {
			product *= a;
			product %= p;
			--b;
		}
		a *= a;
		a %= p;
		b >>= 1;
	}
	return product;
}

long long inv(long long a, long long p) {
	return powmod(a, p - 2, p);
}

long long nCr(long long n, long long k, long long p) {
	if (fact.empty()) initFact(n, p);
	return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n - k], p)) % p;
}

void solve() {
	long long x, y;
	cin >> x >> y;
	if ((x + y) % 3 != 0) {
		cout << "0\n";
		return;
	}
	for (int a = 0; a <= x; a++) {
		int b = x - a;
		if (b & 1) continue;
		b /= 2;
		if (2 * a + b == y) {
			cout << nCr(a + b, a, MOD) << '\n';
			return;
		}
	}
	cout << "0\n";
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}