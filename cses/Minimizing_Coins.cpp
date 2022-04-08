#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve(){
    int n, x; cin >> n >> x;
    vector<int> cost(n);
    for(int& i : cost) cin >> i;
    vector<int> ok(x + 1, INF);
    ok[0] = 0;
    for(int i = 0; i < x; i++){
        if(ok[i] == INF) continue;
        for(int c : cost){
            int sum = i + c;
            if(sum <= x) ok[sum] = min(ok[sum], ok[i] + 1);
        }
    }
    if(ok[x] == INF){
        cout << "-1\n";
    } else {
        cout << ok[x] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    solve();
}