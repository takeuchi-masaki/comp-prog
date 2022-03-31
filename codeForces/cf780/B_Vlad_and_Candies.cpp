#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    map<int, int> frq;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        frq[num]++;
    }
    if(n == 1 && frq.count(1)){
        cout << "YES\n";
        return;
    }
    for(auto it = frq.rbegin(); it != frq.rend(); it++){
        if(it->second == 1 && !frq.count((it->first) - 1)){
            cout << "NO\n";
            return;
        } else {
            cout << "YES\n";
            return;
        }
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