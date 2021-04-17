#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    long long x, y, a, b;
    cin >> x >> y >> a >> b;
    long long exp = 0;
    while(x < y/a && x*a < y && a*x < x+b){
        x*=a;
        ++exp;
    } 
    exp += (y-x-1)/b;
    cout << exp;
}

