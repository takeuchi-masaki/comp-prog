#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e10;

int to_bit(string s){
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'Y'){
            ans += (1<<i);
        }
    }
    // cout << ans << '\n';
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<long long> cost(m), contain(m);
    for(int i = 0; i < m; i++){
        string s;
        cin >> s >> cost[i];
        contain[i] = to_bit(s);
    }
    vector<long long> dp(1<<n, INF);
    dp[0] = 0;
    for(int package = 0; package < m; package++){
        for(int i = 0; i < (1<<n); i++){
            int contain_after = i | contain[package];
            dp[contain_after] = min(dp[contain_after], 
                dp[i] + cost[package]);
        }
    }
    if(dp[(1<<n)-1] == INF) {
        cout << -1 << '\n';
        return 0;
    }
    cout << dp[(1<<n)-1] << '\n';
}