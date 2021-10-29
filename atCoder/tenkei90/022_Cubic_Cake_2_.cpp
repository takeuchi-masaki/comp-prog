#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long a, b, c; cin >> a >> b >> c;
    long long gcdabc = gcd(a, gcd(b, c));
    long long ans = a/gcdabc -1;
    ans += b/gcdabc -1;
    ans += c/gcdabc -1;
    cout << ans << '\n';
}