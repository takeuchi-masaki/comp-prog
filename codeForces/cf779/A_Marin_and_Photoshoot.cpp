#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; 
    string s;
    cin >> n >> s;
    vector<int> zero_idx;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') zero_idx.push_back(i);
    }
    if(zero_idx.size() <= 1){
        cout << "0\n";
        return;
    }
    
    int ans = 0;
    for(int i = 0; i < zero_idx.size() - 1; i++){
        int diff = zero_idx[i + 1] - zero_idx[i] - 1;
        if(diff <= 1){
            ans += 2 - diff;
        }
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}