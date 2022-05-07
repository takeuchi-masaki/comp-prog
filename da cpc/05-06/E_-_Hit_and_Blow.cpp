#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int& i: a) cin >> i;
	for (int& i: b) cin >> i;
	int cntSame = 0, cntDiff = 0;
	set<int> in_a;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) {
			cntSame++;
		} else {
			in_a.insert(a[i]);
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			if (in_a.count(b[i])) {
				cntDiff++;
			}
		}
	}
	cout << cntSame << '\n'
		 << cntDiff << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}