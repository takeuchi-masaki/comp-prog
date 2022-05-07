#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	map<string, int> m;
	vector<string> name1(n), name2(n);
	for (int i = 0; i < n; i++) {
		cin >> name1[i] >> name2[i];
		m[name1[i]]++;
		m[name2[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (m[name1[i]] > 1 && m[name2[i]] > 1) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}