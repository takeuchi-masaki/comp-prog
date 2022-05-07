#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long n, w;
	cin >> n >> w;
	vector<pair<long long, long long>> a(n);
	for (int i = 0; i < n; i++) {
		auto& [taste, cnt] = a[i];
		cin >> taste >> cnt;
	}
	sort(a.rbegin(), a.rend());
	long long ans = 0;
	for (auto& [taste, cnt]: a) {
		ans += min(w, cnt) * taste;
		w -= min(w, cnt);
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}