#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    int digit_sum = 0;
    for(char c : s){
        digit_sum += c - '0';
    }
    vector<char> can_add;
    for(int i = 0; i <= 9; i++){
        if((digit_sum + i) % 9 == 0){
            can_add.push_back((i + '0'));
        }
    }

    vector<string> ans;
    for(char c : can_add){
        string curr = "";
        int idx = 0;
        if(c == '0'){
            curr.push_back(s[idx++]);
        }
        for( ; idx < s.size(); idx++){
            if(s[idx] > c){
                break;
            } else {
                curr.push_back(s[idx]);
            }
        }
        curr.push_back(c);
        while(idx < s.size()){
            curr.push_back(s[idx++]);
        }
        ans.push_back(curr);
    }
    sort(ans.begin(), ans.end());
    cout << ans[0] << '\n';
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