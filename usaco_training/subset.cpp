/*
ID: themasa1
TASK: subset
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("subset.in","r",stdin); freopen("subset.out","w",stdout);
    int n; cin >> n;
    int sum = n*(n+1)/2;
    if(sum & 1) {
        cout << "0\n";
        return 0;
    }
    sum /= 2;
    vector<long long> dp(sum + 1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = sum; j >= i; j--){
            dp[j] += dp[j-i];
        }
    }
    cout << dp[sum]/2 << '\n';
    return 0;
}