#include <bits/stdc++.h>
using namespace std;

void solve() {
	int h, w;
	cin >> h >> w;

	vector<string> grid(h);
	for (string& s: grid) cin >> s;
	if (grid[0][0] == '#' || grid.back().back() == '#') {
		cout << "-1\n";
		return;
	}
	const int INF = 1e9;
	vector<vector<int>> dist(h, vector<int>(w, INF));
	dist[0][0] = 0;

	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	while (!q.empty()) {
		auto [i, j] = q.front();
		q.pop();
		vector<pair<int, int>> dir = {
			{ i - 1, j },
			{ i + 1, j },
			{ i, j - 1 },
			{ i, j + 1 }
		};
		for (auto& [x, y]: dir) {
			if (x < 0 || y < 0 || x >= h || y >= w) { continue; }
			if (grid[x][y] == '#') { continue; }
			if (dist[x][y] == INF) {
				dist[x][y] = dist[i][j] + 1;
				q.push({ x, y });
			}
		}
	}
	if (dist.back().back() == INF) {
		cout << "-1\n";
		return;
	}
	int cnt = 0;
	for (string& s: grid) {
		for (char& c: s) {
			cnt += (c == '.');
		}
	}
	// cout << cnt << ' ' << dist.back().back() << '\n';
	cout << max(cnt - dist.back().back() - 1, 0) << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}