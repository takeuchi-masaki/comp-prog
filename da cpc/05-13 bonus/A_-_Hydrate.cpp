#include <bits/stdc++.h>
using namespace std;

void solve() {
	int c0, c, r, mult;
	cin >> c0 >> c >> r >> mult;
	if (r * mult - c <= 0) {
		cout << "-1\n";
	} else {
		cout << (c0 + (r * mult - c) - 1) / (r * mult - c) << '\n';
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}