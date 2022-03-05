#include <bits/stdc++.h>
using namespace std;

void solve(){
    int g; cin >> g;
    unordered_set<int> s;
    for(int i = 0; i < g; i++){
        int num; cin >> num;
        if(s.count(num)){
            s.erase(num);
        } else {
            s.insert(num);
        }
    }
    cout << *s.begin() << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}