#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b;
	char op;
	cin >> a >> op >> b;
	if (op == '+') {
		cout << a + b << '\n';
	} else if (op == '-') {
		cout << a - b << '\n';
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}