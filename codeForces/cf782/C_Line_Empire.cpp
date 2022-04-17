#include <bits/stdc++.h>
using namespace std;


void solve() {
	long long n, A, B;
	cin >> n >> B >> A;
	vector<long long> pos;
	pos.push_back(0);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pos.push_back(num);
	}
	long long initial = pos[1] * A;

	int a = 0, b = n - 1;
	while (b - a > 3) {
		int c = (2 * a + b) / 3;
		int d = (a + 2 * b) / 3;
		long long costC = initial + (pos[c] * B), costD = initial + (pos[d] * B);
		for (int i = 2; i <= n; i++) {
			if (i <= c + 1) {
				costC += A * (pos[i] - pos[i - 1]);
			} else {
				costC += A * (pos[i] - pos[c]);
			}
			if (i <= d + 1) {
				costD += A * (pos[i] - pos[i - 1]);
			} else {
				costD += A * (pos[i] - pos[d]);
			}
		}
		if (costC < costD) {
			b = d;
		} else {
			a = c;
		}
	}

	long long ans = 1e18;
	for (int i = a; i <= b; i++) {
		long long curr = 0;
		for (int j = 1; j <= i; j++) {
			// cout << (pos[j] - pos[j - 1]) * A << '\n';
			// cout << (pos[j] - pos[j - 1]) * B << '\n';
			curr += (pos[j] - pos[j - 1]) * A;
			curr += (pos[j] - pos[j - 1]) * B;
		}
		for (int j = i + 1; j <= n; j++) {
			// cout << (pos[j] - pos[i]) * A << '\n';
			curr += (pos[j] - pos[i]) * A;
		}
		// cout << i << ' ' << curr << '\n' << '\n';
		ans = min(ans, curr);
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		solve();
	}
}