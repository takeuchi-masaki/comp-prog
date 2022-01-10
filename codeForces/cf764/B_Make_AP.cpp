#include <bits/stdc++.h>
using namespace std;

void solve(){
    vector<int> v(3);
    for(int& i : v) cin >> i;

    int diff0 = v[1] - v[0];
    int diff1 = v[2] - v[1];
    int diff2 = v[2] - v[0];
    if(diff0 == diff1){
        cout << "YES\n";
        return;
    }

    if(
        ((v[1] - diff1 > v[0]) && ((v[1] - diff1) % v[0] == 0)) 
    ){
        cout << "YES\n";
        return;
    }

    if(
        (diff2 % 2 == 0) 
        && (v[0] + diff2/2 > v[1])
        && ((v[0] + diff2 / 2) % v[1] == 0)
    ){
        cout << "YES\n";
        return;
    }

    if(
        ((v[1] + diff0 > v[2]) && (v[1] + diff0) % v[2] == 0)
    ){
        cout << "YES\n";
        return;
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