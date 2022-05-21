#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5;

bool isPrime(int n) {
	if (n <= 1) return false;
	if (n == 2) return true;
	for (long long i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void solve() {
	vector<int> x;
	for (int i = 3; i <= mx; i += 2) {
		if (isPrime(i) && isPrime((i + 1) / 2)) {
			x.push_back(i);
		}
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		auto it1 = lower_bound(x.begin(), x.end(), l);
		auto it2 = upper_bound(x.begin(), x.end(), r);
		cout << (it2 - it1) << '\n';
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}