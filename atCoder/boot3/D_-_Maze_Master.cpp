#include <bits/stdc++.h>
using namespace std;

void solve() {
	int h, w;
	cin >> h >> w;
	vector<string> vs(h);
	for (auto& s: vs) cin >> s;
	vector<vector<int>> dist(h, vector<int>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (vs[i][j] == '#') {
				dist[i][j] = -1;
				continue;
			}
			vector<vector<bool>> visited(h, vector<bool>(h));
			queue<tuple<int, int, int>> q;
			q.push({ i, j, 0 });
			visited[i][j] = true;
			while (!q.empty()) {
				auto [currI, currJ, currD] = q.front();
				q.pop();
				vector<pair<int, int>> directions = {
					{ currI - 1, currJ },
					{ currI + 1, currJ },
					{ currI, currJ - 1 },
					{ currI, currJ + 1 }
				};
				for (auto [nextI, nextJ]: directions) {
					if (nextI < 0 || nextI >= h || nextJ < 0 || nextJ >= w) {
						continue;
					}
					if (vs[nextI][nextJ] == '#' || visited[nextI][nextJ]) {
						continue;
					}
					dist[i][j] = max(dist[i][j], currD + 1);
					visited[nextI][nextJ] = true;
					q.push({ nextI, nextJ, currD + 1 });
				}
			}
		}
	}
	int mx = -1;
	for (auto vi: dist) {
		for (int i: vi) {
			mx = max(mx, i);
		}
	}
	cout << mx << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}