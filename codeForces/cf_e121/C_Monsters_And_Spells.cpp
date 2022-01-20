#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    // vector<pair<long long, long long>> m(n);
    vector<long long> time(n), health(n);
    for(long long& ll : time) cin >> ll;
    for(long long& ll : health) cin >> ll;
    
    vector<pair<long long, long long>> add;
    for(int i = 0; i < n; i++){
        long long t = time[i], h = health[i];
        if(!add.size()){
            add.push_back({t, h});
        } else {
            auto p = add.back();
            while(t - p.first < h){
                h = max(h, p.second + (t - p.first));
                add.pop_back();
                if(!add.empty()){
                    p = add.back();
                } else {
                    break;
                }
            }
            add.push_back({t, h});
        }
    }

    long long ans = 0;
    for(auto [t, h] : add){
        ans += h*(h + 1)/2;
    }
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