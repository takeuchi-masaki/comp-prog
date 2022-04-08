#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

void solve(){
    int n, x; cin >> n >> x;
    vector<int> cost(n);
    for(int& i : cost) cin >> i;
    sort(cost.begin(), cost.end());
    vector<long long> dp(x + 1);
    dp[0] = 1;

    for(int j = 0; j < n; j++){
        for(int i =  0; i < x; i++){
            if(dp[i] == 0) continue;
            int sum = i + cost[j];
            if(sum <= x){
                dp[sum] += dp[i];
                dp[sum] %= MOD;
            }
        }
    }
    cout << dp[x] << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    solve();
}