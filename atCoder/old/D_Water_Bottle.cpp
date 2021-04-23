#include <bits/stdc++.h>
using namespace std;

const long double PI = acosl(-1);

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    long double a, b, x; cin >> a >> b >> x;
    x/=a;
    long double res = 0;
    if(2*x>=a*b){
        long double h = (a*b-x)*2 / a;
        res = atan2(h, a);
    } else {
        long double h2 = (2*x) / b;
        res = atan2(b, h2);
    }
    res*=180/PI;
    cout << fixed << setprecision(10);
    cout << res << '\n';
}