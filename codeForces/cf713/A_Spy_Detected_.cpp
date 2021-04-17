#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int&i:a)cin>>i;
    int start = a[0], sec = a[1];
    if(start!=sec){
        if(a[2] == a[0]){
            cout << "2\n";
            return;
        } else {
            cout << "1\n";
            return;
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i]!=start){
            cout << i+1 << '\n';
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}