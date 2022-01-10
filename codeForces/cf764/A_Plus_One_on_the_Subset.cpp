#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    map<int,int> m;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        m[num]++;
    }
    cout << m.rbegin()->first - m.begin()->first << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}