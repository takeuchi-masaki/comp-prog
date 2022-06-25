#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, p;
	cin >> n >> p;
	vector<int> a(n);
	for (int& i: a) cin >> i;
	int fail = 0;
	for (int i: a) {
		if (i < p) {
			fail++;
		}
	}
	cout << fail << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}