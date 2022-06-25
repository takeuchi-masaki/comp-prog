#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> lights;
	for (int i = 0; i < k; i++) {
		int light;
		cin >> light;
		lights.push_back(light - 1);
	}

	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	vector<long double> mn_dist(n, 1e18);
	for (int i = 0; i < n; i++) {
		for (int light: lights) {
			long double diffX = x[i] - x[light];
			long double diffY = y[i] - y[light];
			long double curr_dist = sqrtl(diffX * diffX + diffY * diffY);
			mn_dist[i] = min(mn_dist[i], curr_dist);
		}
	}
	long double ans = *max_element(mn_dist.begin(), mn_dist.end());
	cout << fixed << setprecision(10);
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}