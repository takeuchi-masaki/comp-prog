#include <bits/stdc++.h>
using namespace std;

void solve(){
    int m, k; cin >> m >> k;
    if(k<=1) {
        cout << k << endl;
        return;
    }
    int ans = 0;
    // brute force
    vector<int> a(m);
    for(int i = 0; i < m; i++){
        a[i] = i+1;
    }
    do{
        int cnt = 0, prev = 0;
        for(int i : a){
            if(i>prev) cnt++;
            prev = i;
        }
        if(cnt == k) ans++;
    } while(next_permutation(a.begin(), a.end()));
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}