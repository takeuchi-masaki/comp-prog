#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

void solve() {
	int mx_h, n;
	cin >> mx_h >> n;
	vector<int> dmg(n), cost(n);
	for (int i = 0; i < n; i++) {
		cin >> dmg[i] >> cost[i];
	}
	vector<long long> dp(mx_h + 1, INF);
	dp[0] = 0;
	for (int h = 1; h <= mx_h; h++) {
		dp[h] = min(dp[h], dp[max(0, h - dmg[0])] + cost[0]);
	}
	for (int spell = 1; spell < n; spell++) {
		vector<long long> curr = dp;
		for (int h = 1; h <= mx_h; h++) {
			curr[h] = min(curr[h], curr[max(0, h - dmg[spell])] + cost[spell]);
		}
		dp = move(curr);
	}
	// for (auto i: dp) cout << i << ' ';
	// cout << '\n';
	cout << dp.back() << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}