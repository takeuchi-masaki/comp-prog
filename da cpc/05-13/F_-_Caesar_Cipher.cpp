#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s, t;
	cin >> s >> t;
	int n = s.size();
	if ((int)t.size() != n) {
		cout << "No\n";
		return;
	}
	for (int i = 1; i < n; i++) {
		int diff1 = (s[i] - s[i - 1] + 26) % 26;
		int diff2 = (t[i] - t[i - 1] + 26) % 26;
		if (diff1 != diff2) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}