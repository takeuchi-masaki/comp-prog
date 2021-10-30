#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int&i:a)cin >> i;
    if(n%2 == 0){
        cout << "YES\n";
        return;
    }
    for(int i = 0; i < n-1; i++){
        if(a[i] >= a[i+1]){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}