#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	int ans = 0;
	for (char& c: s) {
		ans += c - '0';
	}
	ans = max(ans, (9 * ((int)s.size() - 1) + s.front() - '1'));
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}