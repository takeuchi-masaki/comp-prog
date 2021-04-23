#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<bool> broken(n+1, false);
    for(int i = 0; i < m; i++){
        int step; cin>>step;
        broken[step]=true;
    }
    vector<int> dp(n+1);
    dp[0]=1;
    if(broken[1]) {
        dp[1]=0;
    } else {
        dp[1]=1;
    }
    for(int i = 2; i <= n; i++){
        if(broken[i]){
            if(broken[i-1]){
                cout << "0\n";
                return 0;
            }
            dp[i]=0;
        } else {
            dp[i]=dp[i-1]+dp[i-2];
            dp[i]%=mod;
        }
    }
    cout << dp[n] << '\n';
}