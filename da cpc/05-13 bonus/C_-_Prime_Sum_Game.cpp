#include <bits/stdc++.h>
using namespace std;

bool prime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void solve() {
	int mina, maxa, minb, maxb;
	cin >> mina >> maxa >> minb >> maxb;

	for (int i = mina; i <= maxa; i++) {
		bool found_prime = false;
		for (int j = minb; j <= maxb; j++) {
			if (prime(i + j)) {
				found_prime = true;
				break;
			}
		}
		if (!found_prime) {
			cout << "Takahashi\n";
			return;
		}
	}
	cout << "Aoki\n";
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}