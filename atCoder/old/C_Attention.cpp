#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;
    vector<int> e(n), w(n);
    int e_total = 0, w_total = 0;
    for(int i = 0; i < n; i++){
        if(s[i]=='E') e_total++;
        e[i]=e_total;
    }
    for(int i = n-1; i>=0; i--){
        if(s[i]=='W') w_total++;
        w[i]=w_total;
    }
    int res = 1e9;
    for(int i = 0; i < n; i++){
        int curr = e[i]+w[i];
        // cout << curr << '\n';
        res = min(res, n-curr);
    }
    cout << res << '\n';
}