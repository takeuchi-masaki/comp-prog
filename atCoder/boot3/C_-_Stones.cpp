#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	int dot = 0, hash = 0;
	for (char c: s) {
		if (c == '.') {
			dot++;
		} else {
			hash++;
		}
	}

	vector<int> cnt_dot(n);
	cnt_dot.back() = (s.back() == '.');
	for (int i = n - 2; i >= 0; i--) {
		cnt_dot[i] = cnt_dot[i + 1] + (s[i] == '.');
	}

	vector<int> cnt_hash(n);
	cnt_hash.front() = (s.front() == '#');
	for (int i = 1; i < n; i++) {
		cnt_hash[i] = cnt_hash[i - 1] + (s[i] == '#');
	}

	int ans = min(dot, hash);
	for (int i = 0; i < n - 1; i++) {
		ans = min(ans, cnt_dot[i + 1] + cnt_hash[i]);
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}