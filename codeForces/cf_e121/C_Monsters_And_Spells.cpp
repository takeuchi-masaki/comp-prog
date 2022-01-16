#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    // vector<pair<long long, long long>> m(n);
    vector<long long> time(n), health(n);
    for(long long& ll : time) cin >> ll;
    for(long long& ll : health) cin >> ll;
    
    long long ans = 0;
    long long currTime = 0, currVal = 0;
    for(int i = 0; i < n; i++){
        long long t = time[i], h = health[i];
        long long tDiff = t - currTime;
        if(tDiff < h){
            currVal += tDiff;
        } else {
            ans += currVal * (currVal + 1) / 2;
            currVal = h;
        }
        currTime = t;
    }
    ans += currVal * (currVal + 1) / 2;
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}