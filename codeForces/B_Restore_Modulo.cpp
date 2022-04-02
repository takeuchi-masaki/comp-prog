#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    set<int> s;
    for(int i = 1; i < n; i++){
        s.insert(a[i] - a[i - 1]);
    }
    if(s.size() > 2){
        cout << "-1\n";
        return;
    }
    if(s.size() < 2){
        cout << "0\n";
        return;
    }
    int m = abs(*s.begin() - *s.rbegin());
    for(int i : a){
        if(i >= m){
            cout << "-1\n";
            return;
        }
    }
    cout << m << ' ' << max(*s.begin(), *s.rbegin()) << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}