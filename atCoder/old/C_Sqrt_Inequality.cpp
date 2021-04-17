#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    long long a, b, c; cin >> a >> b >> c;
    bool ok;
    long long res1 = a*b*4;
    long long res2 = c-a-b;
    if(res2<0){
        ok = false;
    } else {
        res2*=res2;
        ok = res1<res2;
    }
    cout << (ok?"Yes\n":"No\n");
}