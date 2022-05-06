#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	int i1, i2;
	cin >> s >> i1 >> i2;
	swap(s[i1 - 1], s[i2 - 1]);
	cout << s << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}