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
	vector<int> diff1(n), diff2(n);
	for (int i = 1; i < n; i++) {
		diff1[i - 1] = (s[i] - s[i - 1] + 26) % 26;
		diff2[i - 1] = (t[i] - t[i - 1] + 26) % 26;
	}
	for (int i = 0; i < n; i++) {
		if (diff1[i] != diff2[i]) {
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