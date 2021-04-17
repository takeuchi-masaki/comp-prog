#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    long long k; cin >> k;
    int ans = 0;
    int n = s.size();
    if(n==2) {
        cout << (s[0]==s[1])*k << '\n';
        return 0;
    }
    bool all_same = true;
    char prev = s[0];
    for(int i = 1; i < n; i++){
        if(s[i]!=prev) {
            all_same = false;
            break;
        }
    }
    if(all_same) {
        cout << (n*k)/2 << '\n';
        return 0;
    }

    prev = ' ';
    for(int i = 0; i < n; i++){
        if(s[i]==prev) {
            ans++;
            prev = ' ';
        } else prev = s[i];
    }
    int ans2 = ans;
    if(s[0]==s[n-1] && (s[0]!=s[1] && s[n-2]!=s[n-1])) ans2++;
    cout << ans+(k-1)*ans2 << '\n';
}