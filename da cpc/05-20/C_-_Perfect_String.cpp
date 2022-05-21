#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	set<char> st;
	bool upper = false, lower = false;
	for (char c: s) {
		if (!st.insert(c).second) {
			cout << "No\n";
			return;
		}
		if (c >= 'A' && c <= 'Z') {
			upper = true;
		} else if (c >= 'a' && c <= 'z') {
			lower = true;
		}
	}
	if (upper && lower) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}