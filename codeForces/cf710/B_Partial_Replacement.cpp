#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int start = 0, end = n-1;
    for(int i = 0; i < n; i++){
        if(s[i]=='*'){ start = i; break; }
    }
    for(int i = n-1; i>=0; i--){
        if(s[i]=='*'){ end = i; break; }
    }
    if(start==end){
        cout << "1\n";
        return;
    }
    else if( (end-start-1)<k ){
        cout << "2\n";
        return;
    }

    // case: at least 3
    int prev = start, lastStar = start, res = 2;
    while(true){
        res++;
        for(int i = prev+1; i <= prev+k; i++){
            if(s[i]=='*'){
                lastStar = i;
                if( (end-lastStar-1)<k ) {
                    cout << res << "\n";
                    return;
                }
            }
        }
        prev = lastStar;
        if( (end-lastStar-1)<k ) {
            cout << res << "\n";
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}