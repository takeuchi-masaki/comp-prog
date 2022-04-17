#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i: a) cin >> i;

    // highest health after taking x potions
    vector<long long> dp(n + 1, -INF);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        vector<long long> next_dp = dp;
        for(int x = 1; x <= n; x++){
            if(dp[x - 1] < 0){
                break;
            }
            if(dp[x - 1] + a[i] < 0) continue;
            next_dp[x] = max(dp[x - 1] + a[i], dp[x]);
        }
        dp = move(next_dp);
    }
    for(int i = n; i >= 0; i--){
        if(dp[i] >= 0){
            cout << i << '\n';
            return;
        }
    }
    assert(false);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}