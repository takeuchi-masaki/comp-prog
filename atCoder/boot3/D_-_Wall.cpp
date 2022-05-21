#include <bits/stdc++.h>
using namespace std;

void solve() {
	int h, w;
	cin >> h >> w;
	vector<vector<int>> cost(10, vector<int>(10));
	for (auto& vi: cost) {
		for (int& i: vi) {
			cin >> i;
		}
	}

	int n = 10;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int num;
			cin >> num;
			if ((num == -1) || (num == 1)) continue;
			ans += cost[num][1];
		}
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}