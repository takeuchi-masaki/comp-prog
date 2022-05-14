#include <bits/stdc++.h>
using namespace std;

void solve() {
	char c;
	cin >> c;
	if (c >= 'A' && c <= 'Z') {
		cout << "A\n";
	} else {
		cout << "a\n";
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}