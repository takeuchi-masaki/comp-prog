#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int& i: a) cin >> i;

	int curr_double = 0, ans = 0;
	for (int i = 1; i < n; i++) {
		if ((a[i] << 1) > a[i - 1]) {
			curr_double++;
		} else {
			curr_double = 0;
		}
		if (curr_double >= k) ans++;
	}
	cout << ans << '\n';
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