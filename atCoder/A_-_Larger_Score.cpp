#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<long long> a(n);
	for (auto& i: a) cin >> i;
	long long s = 0;
	for (int i = 0; i < k; i++) {
		s += a[i];
	}
	vector<pair<long long, long long>> numIdx;
	for (int i = k; i < n; i++) {
		numIdx.push_back({ a[i], i });
	}
	sort(numIdx.begin(), numIdx.end());
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}