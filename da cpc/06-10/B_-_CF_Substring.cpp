#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;

	int n = s.size();
	int first_c_idx = n;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'C') {
			first_c_idx = i;
			break;
		}
	}
	for (int i = first_c_idx + 1; i < n; i++) {
		if (s[i] == 'F') {
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}