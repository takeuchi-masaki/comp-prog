#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int& i:a)cin>>i;
    int sum = 0;
    vector<int> prefix(n+1);
    for(int i = 0; i < n; i++){
        prefix[i+1]=prefix[i]+a[i];
    }
    int prev = 0, res = 0;
    for(int i = 1; i <= n; i++){
        if( (prefix[i]-prev)%m==0 ){
            res++; prev = prefix[i];
        }
        //  else {

        // }
    }
    cout << n-res << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}