#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	for (int& i: a) cin >> i;
	vector<int> prefix(n + 1);
	for (int i = 0; i < n; i++) {
		prefix[i + 1] = prefix[i] + a[i];
	}

	const int INF = 1e9;
	int ans = INF;
	for (int start = 0; start < n; start++) {
		int target = s + prefix[start];
		auto it = upper_bound(prefix.begin(), prefix.end(), target);
		if (it - prefix.begin() < start) continue;
		if (it != prefix.begin()) it--;
		if (*it == target) {
			int operations = start + (prefix.end() - it) - 1;
			ans = min(ans, operations);
		}
	}
	if (ans == INF) ans = -1;
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