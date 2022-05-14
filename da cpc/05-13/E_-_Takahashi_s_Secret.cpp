#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> fr(n);
	for (int& i: fr) {
		cin >> i;
		i--;
	}
	int curr = x - 1;
	set<int> s;
	s.insert(curr);
	while (!s.count(fr[curr])) {
		s.insert(fr[curr]);
		curr = fr[curr];
	}
	cout << s.size() << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}