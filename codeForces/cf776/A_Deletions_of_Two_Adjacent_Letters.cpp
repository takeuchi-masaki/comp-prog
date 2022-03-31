#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; char c;
    cin >> s >> c;
    vector<int> ans;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == c) ans.push_back(i);
    }
    for(int i : ans){
        int before = i, after = s.size() - i - 1;
        if(before % 2 == 0 && after % 2 == 0){
            cout << "YES\n";
            return;
        }
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