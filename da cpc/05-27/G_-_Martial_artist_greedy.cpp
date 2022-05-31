#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> learn_time(n);
	vector<vector<int>> need(n, vector<int>());
	vector<bool> will_learn(n);
	for (int i = 0; i < n; i++) {
		int k;
		cin >> learn_time[i] >> k;
		for (int j = 0; j < k; j++) {
			int req;
			cin >> req;
			need[i].push_back(req - 1);
		}
	}

	will_learn[n - 1] = true;
	for (int i = n - 1; i >= 0; i--) {
		if (!will_learn[i]) { continue; }
		for (int req: need[i]) {
			will_learn[req] = true;
		}
	}

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