#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int p, t; cin >> p >> t;
    int ans = 0;
    for(int prob = 0; prob < p; prob++){
        bool ok = true;
        for(int test = 0; test < t; test++){
            string s; cin >> s;
            for(int i = 1; i < s.size(); i++){
                if(s[i] < 'a') ok = false;
            }
        }
        ans += ok;
    }
    cout << ans << '\n';
}