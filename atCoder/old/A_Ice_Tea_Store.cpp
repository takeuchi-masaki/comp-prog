#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;
    long long one = min(s,min(q*4,h*2));
    long long two = min(d,one*2);
    long long res = (n/2)*two;
    if(n&1) res+=one;
    cout << res << endl;
}