#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	for (int& i: a) cin >> i;
	for (int& i: b) cin >> i;
	vector<vector<int>> dp(n, vector<int>(2));
	dp[0][0] = true, dp[0][1] = true;
	for (int i = 1; i < n; i++) {
		if (dp[i - 1][0]) {
			dp[i][0] |= (abs(a[i] - a[i - 1]) <= k);
			dp[i][1] |= (abs(b[i] - a[i - 1]) <= k);
		}
		if (dp[i - 1][1]) {
			dp[i][0] |= (abs(a[i] - b[i - 1]) <= k);
			dp[i][1] |= (abs(b[i] - b[i - 1]) <= k);
		}
	}
	if (dp.back()[0] || dp.back()[1]) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}