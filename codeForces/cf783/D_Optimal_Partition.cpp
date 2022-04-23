#include <bits/stdc++.h>
using namespace std;


void solve() {
	int n;
	cin >> n;
	vector<long long> a(n);
	for (auto& i: a) cin >> i;
	vector<pair<long long, int>> pref(n);
	pref[0] = { a[0], 0 };
	for (int i = 1; i < n; i++) {
		pref[i] = { pref[i - 1].first + a[i], i };
	}
	
    cout << res << '\n';
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