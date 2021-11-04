#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const string FIND = "atcoder";

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    vector<vector<long long>> dp(n+1, vector<long long>(FIND.size()+1));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= FIND.size(); j++){
            dp[i+1][j] += dp[i][j];
            if(s[i] == FIND[j]) dp[i+1][j+1] += dp[i][j];
        }
        for(int j = 0; j <= FIND.size(); j++){
            dp[i+1][j] %= MOD;
        }
    }
    cout << dp[n][FIND.size()] << '\n';
}