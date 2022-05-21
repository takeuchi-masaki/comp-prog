#include <bits/stdc++.h>
using namespace std;

void solve() {
	string og;
	cin >> og;
	int n = og.size();
	bool isPalindrome = true;
	for (int i = 0; i < n / 2; i++) {
		if (og[i] != og[n - 1 - i]) {
			isPalindrome = false;
			break;
		}
	}
	if (isPalindrome) {
		cout << "0\n";
		return;
	}
	string s {};
	for (char c: og) {
		if (c != 'x') {
			s.push_back(c);
		}
	}
	n = s.size();
	isPalindrome = true;
	for (int i = 0; i < n / 2; i++) {
		if (s[i] != s[n - 1 - i]) {
			isPalindrome = false;
			break;
		}
	}
	if (isPalindrome) {
		int st = 0, ed = (int)og.size() - 1;
		int curr = 0;
		while (og[st] == 'x') {
		}
	} else {
		cout << "-1\n";
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}