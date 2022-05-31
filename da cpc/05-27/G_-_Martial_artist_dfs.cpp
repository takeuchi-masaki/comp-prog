#include <bits/stdc++.h>
using namespace std;

void dfs(int curr, vector<vector<int>>& need, vector<bool>& will_learn) {
	if (will_learn[curr]) { return; }
	will_learn[curr] = true;
	for (int& i: need[curr]) {
		dfs(i, need, will_learn);
	}
}

void solve() {
	int n;
	cin >> n;
	vector<bool> will_learn(n);
	vector<int> learn_time(n);
	vector<vector<int>> need(n, vector<int>());

	for (int i = 0; i < n; i++) {
		int k;
		cin >> learn_time[i] >> k;
		for (int j = 0; j < k; j++) {
			int req;
			cin >> req;
			need[i].push_back(req - 1);
		}
	}

	dfs(n - 1, need, will_learn);

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (will_learn[i]) {
			ans += learn_time[i];
		}
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}