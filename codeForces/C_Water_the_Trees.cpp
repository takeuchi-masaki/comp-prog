#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> h(n);
	for (int& i: h) cin >> i;
	sort(h.begin(), h.end());
	int mx = h.back();
	int mx2 = h.back() + 1;

	long long cnt1 = 0, cnt2 = 0;
	for (int i: h) {
		cnt1 += (mx - i) % 2; // how many MUST be 1
		cnt2 += (mx - i) / 2; // how many CAN be 2
	}
	long long diff = cnt2 - cnt1;
	if (diff > 1) {
		cnt1 += diff / 3 * 2;
		cnt2 -= diff / 3;
		diff %= 3;
		if (diff == 2) {
			cnt1 += 2;
			cnt2--;
		}
	}
	long long ans = cnt1 + cnt2;
	if (cnt1 - cnt2 > 1) {
		ans += cnt1 - cnt2 - 1;
	} else if (cnt2 > cnt1) {
		assert(cnt2 == cnt1 + 1);
		ans++;
	}

	cnt1 = 0, cnt2 = 0;
	for (int i: h) {
		cnt1 += (mx2 - i) % 2; // how many MUST be 1
		cnt2 += (mx2 - i) / 2; // how many CAN be 2
	}

	// balance cnt1 and cnt2
	diff = cnt2 - cnt1;
	if (diff > 1) {
		cnt1 += diff / 3 * 2;
		cnt2 -= diff / 3;
		diff %= 3;
		if (diff == 2) {
			cnt1 += 2;
			cnt2--;
		}
	}
	long long ans2 = cnt1 + cnt2;
	if (cnt1 - cnt2 > 1) {
		ans2 += cnt1 - cnt2 - 1;
	} else if (cnt2 > cnt1) {
		assert(cnt2 == cnt1 + 1);
		ans2++;
	}
	cout << min(ans, ans2) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin.exceptions(cin.failbit);
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		solve();
	}
}