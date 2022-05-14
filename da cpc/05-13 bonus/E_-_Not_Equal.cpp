#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i: a) cin >> i;
	sort(a.begin(), a.end());
	long long ans = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] - i <= 0) {
			cout << "0\n";
			return;
		}
		// cout << ans << ' ';
		ans *= (a[i] - i);
		ans %= MOD;
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}