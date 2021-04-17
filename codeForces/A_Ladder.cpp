#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    const int INF = 1E9;
    vector<int> h(n+5), dp(n+5,-INF);
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    dp[0] = 0;
    for(int i = 0; i <= n; i++){
        dp[i+1] = max(dp[i+1],dp[i]+h[i+1]);
        dp[i+2] = max(dp[i+2],dp[i]+h[i+2]);
    }
    cout << dp[n] << endl;
}