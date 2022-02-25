#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        if((n&1) && (i == n/2 + 1)){
            cout << n << ' ';
            for(int num = n - 1; num >= 3; num--){
                cout << num << ' ';
            }
            cout << "1 2\n";
            continue;
        }
        for(int num = n - 1; num >= 1; num--){
            int pos = n - num - 1;
            if(i == pos){
                cout << n << ' ';
            }
            cout << num << ' ';
        }
        if(i == n - 1) cout << n << ' ';
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}