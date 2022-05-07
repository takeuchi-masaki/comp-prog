#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long n, k, x;
	cin >> n >> k >> x;
	vector<int> a(n);
	for (int& i: a) cin >> i;
	long long mx_coupon = 0;
	vector<int> mx_remainder;
	for (int i: a) {
		mx_coupon += i / x;
		mx_remainder.push_back(i % x);
	}
	long long sum = accumulate(a.begin(), a.end(), 0LL);
	if (mx_coupon >= k) {
		sum -= k * x;
	} else {
		sum -= mx_coupon * x;
		long long coupon_left = k - mx_coupon;
		sort(mx_remainder.rbegin(), mx_remainder.rend());
		for (int i = 0; i < min(coupon_left, (long long)mx_remainder.size()); i++) {
			sum -= mx_remainder[i];
		}
	}
	cout << sum << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}