#include <bits/stdc++.h>
using namespace std;

void solve() {
	int start, end, x;
	cin >> start >> end >> x;
	if (end <= start) {
		end += 24;
		if (x < start) {
			x += 24;
		}
	}
	bool ok = (x >= start) && (x < end);
	cout << (ok ? "Yes\n" : "No\n");
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}