#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n; cin >> n;
    map<int, int> num_cnt, frq;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        num_cnt[temp]++;
    }
    for(auto& [num, cnt] : num_cnt){
        frq[cnt]++;
    }

    auto it = frq.rbegin();
    int prev_f = it->first, prev_c = it->second;
    long long ans = n - (prev_f * prev_c);
    long long prev = ans;
    it++;
    for( ; it != frq.rend(); it++){
        auto [f, c] = *it;
        long long curr = prev + (prev_f - f) * prev_c;
        curr -= f * c;
        prev_f = f;
        prev_c += c;
        prev = curr;
        ans = min(ans, curr);
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}