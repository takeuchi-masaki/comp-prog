#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<vector<long long>> dp(n, vector<long long>(9));
	for (int i = 0; i < 9; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		dp[i] = dp[i - 1];
		dp[i][0] += dp[i - 1][1];
		dp[i][0] %= MOD;
		dp[i][8] += dp[i - 1][7];
		dp[i][8] %= MOD;
		for (int j = 1; j < 8; j++) {
			dp[i][j] += dp[i - 1][j - 1];
			dp[i][j] += dp[i - 1][j + 1];
			dp[i][j] %= MOD;
		}
	}
	long long ans = accumulate(dp.back().begin(), dp.back().end(), 0LL);
	ans %= MOD;
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}