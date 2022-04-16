#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long modpow(long long base, long long exp) {
	base %= MOD;
	long long result = 1;
	while (exp > 0) {
		if (exp & 1) result = (result * base) % MOD;
		base = (base * base) % MOD;
		exp >>= 1;
	}
	return result;
}

map<long long, int> factorize(long long num) {
	map<long long, int> factors;
	while (num % 2 == 0) {
		factors[2]++;
		num >>= 1;
	}
	for (long long i = 3; i * i <= num; i += 2) {
		while (num % i == 0) {
			num /= i;
			factors[i]++;
		}
	}
	if (num != 1ll) factors[num]++;
	return factors;
}

void solve() {
	long long x, c;
	cin >> x >> c;
	map<long long, int> m = factorize(x);
	for (auto [num, cnt]: m) {
		long long val = modpow(num, c);
		long long currMin = x;
		while (cnt > 0) {
			currMin = min(lcm(val, currMin) / gcd(val, currMin), currMin);
			cnt -= c;
		}
		x = min(x, currMin);
	}
	cout << x << '\n';
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