#include <bits/stdc++.h>
using namespace std;

// const int MOD = 1E9+7;
int comb(int n, int r){
    if(r > n || r < 0) return 0;
    return n*(n-1)/2;
}

void solve(){
    int n;
    int k = 2, m = 3;
    cin >> n; // >> k >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int res = 0;
    for(int i = 0; i < n; i++){
        int countLower = 
            lower_bound(a.begin(), a.end(), a[i]+k+1) - a.begin() - 1;
        res+=comb(countLower-i, m-1);
    }
    cout << res << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}