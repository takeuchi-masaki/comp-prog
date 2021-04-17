#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long c, d, x;
        cin >> c >> d >> x;
        double res1 = (double)(x+d)/c;
        long long res = res1;
        if(res != res1) res = 0;
        
        cout << res << endl;
    }
}