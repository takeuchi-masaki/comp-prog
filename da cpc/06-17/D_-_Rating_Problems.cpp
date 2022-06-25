#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	int sum = 0;
	for (int i = 0; i < k; i++) {
		int score;
		cin >> score;
		sum += score;
	}
	int remain = n - k;
	int mn = sum - 3 * remain;
	int mx = sum + 3 * remain;
	double ans1 = (double)mn / n;
	double ans2 = (double)mx / n;
	cout << fixed << setprecision(10);
	cout << ans1 << ' ' << ans2 << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}