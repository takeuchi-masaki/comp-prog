#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long a, b; cin >> a >> b;
    bool odd = (a*b)&1;
    cout << (odd?"Odd\n":"Even\n");
}