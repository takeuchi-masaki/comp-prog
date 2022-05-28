#include <bits/stdc++.h>
using namespace std;

void solve() {
	int h, w;
	cin >> h >> w;

	for (int i = 0; i < (w + 2); i++) {
		cout << '#';
	}
	cout << '\n';

	for (int i = 0; i < h; i++) {
		string s;
		cin >> s;
		cout << '#' << s << "#\n";
	}

	for (int i = 0; i < (w + 2); i++) {
		cout << '#';
	}
	cout << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}