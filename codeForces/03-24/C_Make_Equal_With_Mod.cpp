#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    sort(a.begin(), a.end());
    set<int> s;
    for(int i : a) s.insert(i);
    if(!s.count(1) || s.size() == 1){
        cout << "YES\n";
        return;
    }
    for(auto it = s.rbegin(); it != s.rend(); it++){
        if(*it == 1) continue;
        if(*it == 2 || *it == 0){
            cout << "NO\n";
            return;
        }
        int minus1 = *it - 1;
        if(s.count(minus1)){
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