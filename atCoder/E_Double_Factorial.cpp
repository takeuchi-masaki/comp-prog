#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long n; cin >> n;
    if(n&1) {
        cout << "0\n";
        return 0;
    }
    n /= 10;
    long long ans = n;
    while(n > 0){
        n /= 5;
        ans += n;
    }
    cout << ans << '\n';
}