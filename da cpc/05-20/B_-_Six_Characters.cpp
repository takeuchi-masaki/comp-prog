#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	assert(s.size() > 0);
	int mult = 6 / s.size();
	for (int i = 0; i < mult; i++) {
		cout << s;
	}
	cout << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}