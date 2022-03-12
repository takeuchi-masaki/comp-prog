#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<long double> odds(n), dp(1<<n);
    for(auto& l : odds) cin >> l;

    for(int group = 0; group < (1<<n); group++){
        if(__builtin_popcount(group) <= 2) continue;
        long double all0 = 1.0L, all1 = 1.0L;
        for(int kid = 0; kid < n; kid++){
            if(group>>kid&1){
                all1 *= odds[kid];
                all0 *= (1 - odds[kid]);
            }
        }

        long double curr = 0;
        for(int kid = 0; kid < n; kid++){
            if(group>>kid&1){
                long double prob = (all1 / odds[kid] * (1 - odds[kid])) + (all0 / (1 - odds[kid]) * odds[kid]);
                dp[group] += prob * dp[group ^ (1<<kid)];
                curr += prob;
            }
        }
        dp[group] = (dp[group] + 1) / curr;
    }
    cout << fixed << setprecision(10);
    cout << dp[(1<<n)-1] << '\n';
}