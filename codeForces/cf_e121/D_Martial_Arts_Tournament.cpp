#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    sort(a.begin(), a.end());
    vector<int> frq;
    frq.push_back(1);
    for(int i = 1; i < n; i++){
        if(a[i] == a[i - 1]){
            frq.back()++;
        } else {
            frq.push_back(1);
        }
    }
    for(int i = 1; i < int(frq.size()); i++){
        frq[i] += frq[i - 1];
    }

    int ans = 1e9;
    int loop = 20;
    for(int i = 0; i < loop; i++){
        for(int j = 0; j < loop; j++){
            for(int k = 0; k < loop; k++){
                int g1 = 1<<i;
                int g2 = 1<<j;
                int g3 = 1<<k;
                int pos = upper_bound(frq.begin(), frq.end(), g1) - frq.begin();
                if(pos) g2 += frq[pos - 1];
                pos = upper_bound(frq.begin()+pos, frq.end(), g2) - frq.begin();
                if(pos) g3 += frq[pos - 1];
                auto it = upper_bound(frq.begin()+pos, frq.end(), g3);
                if(it == frq.end()){
                    ans = min(ans, (1<<i) + (1<<j) + (1<<k) - n);
                }
            }
        }
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