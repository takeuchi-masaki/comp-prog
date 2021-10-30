#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int&i:a)cin>>i;
    int currAdd = 0;
    for(int i = 0; i < n; i++){
        // cout << i+1+currAdd << ' ' << a[i] << '\n';
        if(a[i] > i+currAdd+1){
            currAdd += a[i]-(i+currAdd+1);
            // cout << "modified " << currAdd << '\n';
        }
    }
    cout << currAdd << '\n';
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