#include <bits/stdc++.h>
using namespace std;

void solve() {
	int q;
	cin >> q;
	queue<pair<int, int>> cylinder;
	for (int i = 0; i < q; i++) {
		int query;
		cin >> query;
		if (query == 1) {
			pair<int, int> p {};
			cin >> p.first >> p.second;
			cylinder.push(move(p));
		} else if (query == 2) {
			int rem;
			cin >> rem;
			long long sum = 0;
			while (rem > 0) {
				if (cylinder.front().second > rem) {
					sum += rem * (long long)cylinder.front().first;
					cylinder.front().second -= rem;
					rem = 0;
				} else {
					sum += (long long)cylinder.front().first * cylinder.front().second;
					rem -= cylinder.front().second;
					cylinder.pop();
				}
			}
			cout << sum << '\n';
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}