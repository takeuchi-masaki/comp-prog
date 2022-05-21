#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	string prefix {}, ans {};
	int open = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			ans.push_back('(');
			open++;
		} else if (open > 0) {
			ans.push_back(')');
			open--;
		} else {
			prefix.push_back('(');
			ans.push_back(')');
		}
	}
	while (open > 0) {
		open--;
		ans.push_back(')');
	}
	cout << prefix << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}