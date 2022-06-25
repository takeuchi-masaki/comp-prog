#include <bits/stdc++.h>
using namespace std;

void solve() {
	vector<string> board(8);
	for (auto& s: board) cin >> s;
	for (int i = 1; i < 7; i++) {
		for (int j = 1; j < 7; j++) {
			if (board[i][j] == '#') {
				if (board[i - 1][j - 1] == '#' && board[i + 1][j + 1] == '#' && board[i - 1][j + 1] == '#' && board[i + 1][j - 1] == '#') {
					cout << i + 1 << ' ' << j + 1 << '\n';
				}
			}
		}
	}
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