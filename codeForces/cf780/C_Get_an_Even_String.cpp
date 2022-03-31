#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    int n = s.size();
    int l = 0, r = n - 1;
    while(l < n - 1 && s[l] == s[l+1]){
        l+=2;
    }
    while(r >= l && s[r] == s[r-1]){
        r-=2;
    }
    if(r < l){
        cout << "0\n";
        return;
    }
    vector<vector<int>> next_char(26);
    vector<int> next_pair;
    for(int i = l; i <= r; i++){
        if(i < r && s[i] == s[i+1]){
            next_pair.push_back(i);
        } else {
            next_char[s[i] - 'a'].push_back(i);
        }
    }

    int ans = 0, curr_pair = 0;
    for(int i = l; i <= r; i++){
        if(curr_pair < (int)next_pair.size() && i == next_pair[curr_pair]){
            i++;
            curr_pair++;
            continue;
        }
        auto it = lower_bound(next_char[s[i] - 'a'].begin(), next_char[s[i] - 'a'].end(), i+1);
        if(it == next_char[s[i] - 'a'].end()
        || ((curr_pair < (int)next_pair.size()) && (next_pair[curr_pair] < *it))
        ) {
            ans++;
        } else {
            ans += *it - i - 1;
            i = *it;
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