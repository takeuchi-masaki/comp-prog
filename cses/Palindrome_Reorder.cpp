#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    vector<int> char_cnt(26);
    for(char c : s) char_cnt[c - 'A']++;
    int one = -1;
    for(int i = 0; i < 26; i++){
        if(char_cnt[i]&1){
            if(one != -1){
                cout << "NO SOLUTION\n";
                return 0;
            }
            one = i;
            char_cnt[i]--;
        }
    }
    string ans = "";
    for(int i = 0; i < 26; i++){
        if(char_cnt[i] == 1 || char_cnt[i] == 0) continue;
        ans.append(char_cnt[i]/2, i + 'A');
    }
    cout << ans;
    if(one != -1) cout << char(one + 'A');
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}