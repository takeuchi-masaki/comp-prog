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

	queue<int> q;
	q.push(n - 1);
	will_learn[n - 1] = true;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int& i: need[curr]) {
			if (will_learn[i]) { continue; }
			will_learn[i] = true;
			q.push(i);
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