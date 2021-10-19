#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    int ans = 0;
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            int want = (x - i*500 - j*100)/50;
            if(want >= 0 && want <= c) ans++;
        }
    }
    cout << ans << endl;
}