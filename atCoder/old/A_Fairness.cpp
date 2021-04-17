#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a,b,c,k;
    cin >> a >> b >> c >> k;
    long long res = a-b;
    if(k&1) res *= -1;
    cout << res << endl;
}