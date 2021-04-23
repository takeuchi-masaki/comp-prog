#include <bits/stdc++.h>
using namespace std;

void bad(){
    cout << -1 << '\n';
}

void solve(){
    long long n; cin >> n;
    // if(n<2050) {
    //     bad();
    //     return;
    // }
    long long cnt = n/2050;
    n %= 2050;
    if(n!=0) {
        bad();
        return;
    }
    // cout << cnt << '\n';
    int res = 0;
    while(cnt>0){
        res+=cnt%10;
        cnt/=10;
    }
    cout << res << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout)
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}