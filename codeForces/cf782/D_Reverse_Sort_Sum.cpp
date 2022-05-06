#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), ans(n);
	for (int& i: a) cin >> i;

	queue<int> idx;
	for (int i = 0; i < n; i++) {
		if(a[i] == 0) {
			ans[i] = 0;
		} else if(idx.empty()) {
			ans[i] = 1;
			idx.push(a[i]);
		} else if(i == idx.front()) {
			ans[i] = 0;
			idx.pop();
			idx.push(a[i] + i);
		} else {
			ans[i] = 1;
			idx.push(a[i]);
		}
	}

	for (int i: ans) {
		cout << i << ' ';
	}
	cout << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		solve();
	}
}