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
        if(digit_sum + i % 9 == 0){
            can_add.push_back((i + '0'));
        }
    }

    vector<string> ans;
    string add1;
    if(add != '0'){
        add1 = add + s;
        ans.push_back(add1);
    }
    add1 = s + add;
    ans.push_back(add1);
    for(int i = 1; i < s.size() - 1; i++){
        string curr = s.substr(0, i) + add + s.substr(i);
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