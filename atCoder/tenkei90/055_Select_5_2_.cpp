#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long n, p, q; cin >> n >> p >> q;
    vector<long long>arr(n);
    for(long long&i:arr)cin>>i;
    int ans = 0;
    for(int a = 0; a < n-4; a++){
        for(int b = a+1; b < n-3; b++){
            for(int c = b+1; c < n-2; c++){
                for(int d = c+1; d < n-1; d++){
                    for(int e = d+1; e < n; e++){
                        long long mult = (arr[a]*arr[b])%p;
                        mult = (mult*arr[c])%p;
                        mult = (mult*arr[d])%p;
                        mult = (mult*arr[e])%p;
                        if(mult == q) ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}