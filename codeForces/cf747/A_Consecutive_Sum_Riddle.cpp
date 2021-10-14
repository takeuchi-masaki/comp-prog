#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n; cin >> n;
    cout << -(n-1) << ' ' << n << endl;

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