#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    set<char> valid = {
        'A', 'C', 'G', 'T'
    };
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        int curr = 0;
        while(i < s.size() && valid.count(s[i])){
            i++, curr++;
        }
        ans = max(ans, curr);
    }
    cout << ans << '\n';
}