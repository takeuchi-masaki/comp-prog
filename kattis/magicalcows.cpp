#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // capacity, farms day 0, queries
    int c, n, m; cin >> c >> n >> m;
    const int day_max = 50;
    vector<vector<long long>> dp(day_max + 1, vector<long long>(c + 1));
    for(int i = 0; i < n; i++){
        int cnt; cin >> cnt;
        dp[0][cnt]++;
    }
    for(int day = 1; day <= 50; day++){
        for(int capacity = 1; capacity <= c; capacity++){
            int cap2 = capacity<<1;
            if(cap2 > c){
                dp[day][cap2/2] += dp[day - 1][capacity];
                dp[day][(cap2 + 1)/2] += dp[day - 1][capacity];
            } else {
                dp[day][cap2] += dp[day - 1][capacity];
            }
        }
    }

    for(int q = 0; q < m; q++){
        int day; cin >> day;
        long long ans = 0;
        for(int i = 1; i <= c; i++){
            ans += dp[day][i];
        }
        cout << ans << '\n';
    }
}