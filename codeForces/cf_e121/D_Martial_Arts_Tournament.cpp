#include <bits/stdc++.h>
using namespace std;

vector<int> pow2;

void find_pow2(){
    int curr = 1;
    while(curr <= 2e5){
        pow2.push_back(curr);
        curr<<=1;
    }
}

void solve(){
    int n; cin >> n;
    vector<int> prefix(n + 1), cnt(n + 1);
    for(int i = 0; i < n; i++){
        int w; cin >> w;
        cnt[w]++;
    }
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i - 1] + cnt[i];
    }
    // 1 group
    // int ans = *lower_bound(pow2.begin(), pow2.end(), n) - n + 2;
    int ans = 1e9;
    
    // 2 groups
    for(int i = 0; i <= n; i++){
        int x = prefix[i], y = prefix[n] - x;
        int currAns = *lower_bound(pow2.begin(), pow2.end(), x) - x + 1;
        currAns += *lower_bound(pow2.begin(), pow2.end(), y) - y;
        ans = min(ans, currAns);
    }

    // 3 groups
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    find_pow2();

    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}