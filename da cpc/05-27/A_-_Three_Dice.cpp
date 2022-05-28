#include <bits/stdc++.h>
using namespace std;

void solve() {
	vector<int> a(3);
	for (int& i: a) cin >> i;
	int sum = 0;
	for (int& i: a) {
		sum += (7 - i);
	}
	cout << sum << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}