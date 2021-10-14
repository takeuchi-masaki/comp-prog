#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    char c; cin >> c;
    string s; cin >> s;
    bool allSame = true;
    for(int i = 0; i < n; i++){
        if(s[i] != c) {
            allSame = false;
            break;
        }
    }
    if(allSame){
        cout << 0 << endl;
        return;
    }
    for(int i = 1; i <= n; i++){
        bool allMultGood = true;
        for(int curr = i; curr <= n; curr+=i){
            if(s[curr-1] != c){
                allMultGood = false;
                break;
            }
        }
        if(allMultGood){
            cout << 1 << endl;
            cout << i << endl;
            return;
        }
    }
    cout << 2 << endl;
    cout << n-1 << ' ' << n << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}