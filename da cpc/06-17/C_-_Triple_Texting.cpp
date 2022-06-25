#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	assert(s.size() % 3 == 0);
	int n = s.size() / 3;
	string s1 = s.substr(0, n);
	string s2 = s.substr(n, n);
	string s3 = s.substr(2 * n);
	if (s1 == s2 || s1 == s3) {
		cout << s1 << '\n';
	} else if (s2 == s3) {
		cout << s2 << '\n';
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}