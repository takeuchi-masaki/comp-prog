#include <bits/stdc++.h>
using namespace std;

void solve() {
	int q;
	cin >> q;
	multiset<long long> s;
	for (int i = 0; i < q; i++) {
		int query;
		cin >> query;
		if (query == 1) {
			long long x;
			cin >> x;
			s.insert(x);
		} else if (query == 2) {
			long long x, k;
			cin >> x >> k;
			bool ok = true;
			auto it = s.upper_bound(x);
			if (it == s.begin()) {
				ok = false;
			} else {
				it--;
			}
			for (int j = 0; ok && j < k - 1; j++) {
				if (it == s.begin()) {
					ok = false;
					break;
				}
				it--;
			}
			if (ok) {
				cout << *it << '\n';
			} else {
				cout << "-1\n";
			}
		} else {
			assert(query == 3);
			long long x, k;
			cin >> x >> k;
			auto it = s.lower_bound(x);
			bool ok = true;
			if (it == s.end()) {
				ok = false;
			}
			for (int j = 0; ok && j < k - 1; j++) {
				it++;
				if (it == s.end()) {
					ok = false;
					break;
				}
			}
			if (ok) {
				cout << *it << '\n';
			} else {
				cout << "-1\n";
			}
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}