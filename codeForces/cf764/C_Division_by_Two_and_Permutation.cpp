#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    set<int> s;
    vector<int> remaining;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if((x <= n && !s.emplace(x).second)
        || x > n){
            remaining.push_back(x);
        }
    }
    for(int i : remaining){
        bool added = false;
        while(!added && i > 0){
            if(i <= n && s.emplace(i).second){
                added = true;
            }
            i >>= 1;
        }
        if(!added) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}