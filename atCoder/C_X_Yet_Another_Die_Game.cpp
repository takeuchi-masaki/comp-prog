#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // freopen("input.txt","r",stdin);
    long long x; cin >> x;
    long long res = 0;
    
    if(x>11){
        res = x/11 * 2;
        x%=11;
    }

    if(x>6){
        res += 2;
    } else if(x>0) res++;
    cout << res << '\n';

    return 0;
}