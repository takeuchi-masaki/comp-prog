#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    int ans = 1, rep = 1;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i-1]) rep++;
        else rep = 1;
        ans = max(ans, rep);
    }
    cout << ans << '\n';
}