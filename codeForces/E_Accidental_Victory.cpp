#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<pair<int,int>> a(n);
    for(int i = 1; i<=n; i++){
        int temp; cin >> temp;
        a[i-1]={temp, i};
    }
    sort(a.begin(), a.end()); // sort by value
    long long sum = 0;
    for(int i = 0; i<n; i++){
        
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}