#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	for (int r = 0; r < n; r++) {
		for (int i = 0; i < a; i++) {
			for (int c = 0; c < n; c++) {
				for (int j = 0; j < b; j++) {
					if ((r & 1) ^ (c & 1)) {
						cout << '#';
					} else {
						cout << '.';
					}
				}
			}
			cout << '\n';
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}