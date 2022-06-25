#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a;
	cin >> a;
	vector<int> v(3);
	for (int& i: v) cin >> i;
	int cnt = 0;
	for (int i: v) {
		if (i > a) {
			cnt++;
		}
	}
	cout << cnt << '\n';
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