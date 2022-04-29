#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for (string& s: grid) cin >> s;
	for (int r = n - 2; r >= 0; r--) {
		for (int c = 0; c < m; c++) {
			if (grid[r][c] == '*' && grid[r + 1][c] == '.') {
				int final_pos = r + 1;
				while (final_pos + 1 < n && grid[final_pos + 1][c] == '.') {
					final_pos++;
				}
				grid[r][c] = '.';
				grid[final_pos][c] = '*';
			}
		}
	}
	for (string& s: grid) cout << s << '\n';
	cout << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		solve();
	}
}