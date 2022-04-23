#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long n, m;
	cin >> n >> m;
	vector<long long> a(n);
	for (auto& i: a) cin >> i;
	sort(a.rbegin(), a.rend());

	long long fr = a[0] + 1, bck = m - 1 - a[0];
	for (int i = 1; i < n; i++) {
		if (fr > bck) {
			cout << "NO\n";
			return;
		}
		if (i & 1) {
			fr += a[i] + 1;
		} else {
			bck -= a[i] + 1;
		}
	}
	cout << "YES\n";
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		solve();
	}
}