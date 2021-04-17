#include <bits/stdc++.h>
using namespace std;

void ans(bool ok){
    cout << (ok?"Yes\n":"No\n");
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    int mx = max(n,m), mn = min(n,m);

    if(k<mn && k!=0){
        ans(false);
        return 0;
    }
    if (k%n==0 || k%m==0) {
        ans(true);
        return 0;
    }
    for(int i = 1; i < mn; i++){
        for(int j = 1; j < mx; j++){
            int res = (mx-j)*i + (mn-i)*j;
            // cout << res << '\n';
            if(k==res){
                // cout << i << " " << j << '\n';
                ans(true);
                return 0;
            }
        }
    }
    ans(false);
    return 0;
}