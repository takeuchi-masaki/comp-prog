// #include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int currK = 0;
    for(int i = 0; i < n/2; i++){
        int comp = n-1-i; // complement
        if(s[i] != s[comp]){
            currK++;
        }
    }
    cout << abs(k-currK) << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout)
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}