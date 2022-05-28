#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	bool palindrome = true;
	for (int i = 0; i < n / 2; i++) {
		if (s[i] != s[n - 1 - i]) {
			palindrome = false;
			break;
		}
	}
	if (palindrome || k == 0) {
		cout << "1\n";
	} else {
		cout << "2\n";
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