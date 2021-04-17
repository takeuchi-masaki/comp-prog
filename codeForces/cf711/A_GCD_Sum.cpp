#include <bits/stdc++.h>
using namespace std;

void solve(){
    string n; cin >> n;
    int sum = 0;
    for(int i = 0; i < n.length(); i++){
        sum+=(int)n[i]-'0';
    }
    long long nn = stoll(n);
    while(true){
        // cout << nn << " " << sum << '\n';
        int curr_gcd = gcd(nn, (long long)sum);
        if( curr_gcd>1 ){
            cout << nn << '\n';
            return;
        }
        if( nn%10==9 ){
            // n = to_string(nn);
            // sum = 0;
            // for(int i = 0; i < n.length(); i++){
            //     sum+=(int)n[i]-'0';
            // }
            cout << ++nn << '\n';
            return;
        }
        nn++;
        sum++;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}