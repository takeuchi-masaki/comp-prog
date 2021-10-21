#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> h(n), l(n), r(n);
    for(int&i:h) cin >> i;
    for(int i = 1; i<n-1; i++){
        l[i] = max(l[i-1], h[i-1]);
    }
    for(int i = n-2; i>0; i--){
        r[i] = max(r[i+1], h[i+1]);
    }
    // for(int i:l) cout << i << ' ';
    // cout << endl;
    // for(int i:r) cout << i << ' ';
    // cout << endl;
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, min(l[i],r[i]) - h[i] );
    }
    cout << ans << endl;
}