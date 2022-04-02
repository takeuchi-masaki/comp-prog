#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> to_void;
vector<bool> used;


long long go(int idx, long long sum, int currMax){
    

}

void solve(){
    adj.clear();
    to_void.clear();
    used.clear();

    int n; cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    adj.resize(n);
    used.resize(n);
    for(int i = 0; i < n; i++){
        int to; cin >> to;
        if(to == 0) {
            to_void.push_back(i);
        } else {
            adj[to - 1].push_back(i);
        }
    }

    long long ans = 0;
    for(int i : to_void){
        
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}