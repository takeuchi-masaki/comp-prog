#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int x, y; cin >> x >> y;
    int res;
    if(x<y){
        int res1 = y-x;
        int res2 = abs(y+x)+1;
        res = min(res1, res2);
    } else {
        int res1 = abs(y-x)+2;
        int res2 = abs(y+x)+1;
        res = min(res1, res2);
    }
    cout << res << '\n';
}