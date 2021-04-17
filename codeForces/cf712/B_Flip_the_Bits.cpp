#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    string a, b; cin >> a >> b;
    bool ok = true, same = true;
    int one = 0, zero = 0;
    vector<pair<int,int>> prefix(n);
    for(int i = 0; i<n; i++){
        if(a[i]=='0'){
            zero++;
        } else one++;
        prefix[i].first = zero;
        prefix[i].second = one;
    }
    for(int i = n-1; i>=0; i--){
        if( (a[i]==b[i])!=same ){
            if(prefix[i].first == prefix[i].second) {
                same = !same;
            } else {
                ok = false;
                break;
            }
        } 
        // char one = a[i], two = b[i];
        // if(i&1){
        //     if( (a[i]==b[i])!=same ){
        //         if(prefix[i].first == prefix[i].second) same = !same;
        //         else { ok = false; break; }
        //     } 
        // } else {
        //     if( (a[i]==b[i])!=same ){
        //         ok = false;
        //         break;
        //     }
        // }
    }
    cout << (ok?"YES\n":"NO\n");
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}