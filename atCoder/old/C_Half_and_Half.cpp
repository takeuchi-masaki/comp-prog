#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    long long res = a*x + b*y;
    int less = min(x,y);
    long long ab = less*c*2;
    long long allC = max(x,y)*c*2;
    x-=less;
    y-=less;
    ab+=x*a + y*b;
    res = min(res,min(ab,allC));
    cout << res << endl;
}