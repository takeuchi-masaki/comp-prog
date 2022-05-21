#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	map<int, vector<int>> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		m[a].push_back(i + 1);
	}
	for (int i = 0; i < q; i++) {
		int x, k;
		cin >> x >> k;
		k--;
		auto it = m.find(x);
		if (it == m.end() || (int)it->second.size() <= k) {
			cout << "-1\n";
		} else {
			cout << it->second[k] << '\n';
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}