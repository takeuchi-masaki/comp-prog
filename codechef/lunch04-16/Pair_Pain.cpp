#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	map<long long, long long> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		m[num]++;
	}

	long long ans = 0;
	for (auto [num, cnt]: m) {
        if(num <= 2){
            ans += (cnt * (cnt - 1)) / 2;
        }
	}
    long long non_one = n - m[1];
    ans += m[1] * non_one;
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