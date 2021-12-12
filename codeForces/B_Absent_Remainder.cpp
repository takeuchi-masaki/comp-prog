#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int& i : a){
        cin >> i;
    }
    sort(a.begin(), a.end());
    int need = n/2;
    for(int i = 1; i <= need; i++){
        cout << a[i] << ' ' << a[0] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}