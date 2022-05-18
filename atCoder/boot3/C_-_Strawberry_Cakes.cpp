#include <bits/stdc++.h>
using namespace std;

void solve() {
	int h, w, k;
	cin >> h >> w >> k;
	vector<string> grid(h);
	for (string& s: grid) cin >> s;
	set<int> ok_row;
	for (int i = 0; i < h; i++) {
		for (char c: grid[i]) {
			if (c == '#') {
				ok_row.insert(i);
				break;
			}
		}
	}
	int group = 0;
	vector<vector<int>> ans;
	{
		vector<int> firstRow(w);
		int curr = *ok_row.begin();
		int idx = 0;
		group++;
		while (grid[curr][idx] != '#') {
			idx++;
		}
		for (int i = 0; i <= idx; i++) {
			firstRow[i] = group;
		}
		for (int i = idx + 1; i < w; i++) {
			if (grid[curr][i] == '#') {
				group++;
			}
			firstRow[i] = group;
		}
		for (int i = 0; i <= curr; i++) {
			ans.push_back(firstRow);
		}
	}
	for (int i = *ok_row.begin() + 1; i < h; i++) {
		if (!ok_row.count(i)) {
			ans.push_back(ans.back());
			continue;
		}
		vector<int> row(w);
		int idx = 0;
		group++;
		while (grid[i][idx] != '#') {
			idx++;
		}
		for (int j = 0; j <= idx; j++) {
			row[j] = group;
		}
		for (int j = idx + 1; j < w; j++) {
			if (grid[i][j] == '#') {
				group++;
			}
			row[j] = group;
		}
		ans.push_back(row);
	}

	for (auto vi: ans) {
		for (int i: vi) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}