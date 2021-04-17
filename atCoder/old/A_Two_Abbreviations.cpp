#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    long long l = lcm((long long)n,(long long)m);
    int ln = l/n, lm = l/m;
    long long l2 = lcm((long long)ln, (long long)lm);
    for(long long i = 0; i <= l; i+=l2){
        if(s[i/ln]!=t[i/lm]){
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << l << '\n';
    return 0;
}