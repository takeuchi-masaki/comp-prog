#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long cd = lcm(c,d);
    long long res = b - (b/c + b/d - b/cd);
    a--;
    res -= a - (a/c + a/d - a/cd);
    cout << res << endl;
}