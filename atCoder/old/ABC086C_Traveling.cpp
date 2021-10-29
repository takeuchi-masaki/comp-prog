#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int currX = 0, currY = 0, currT = 0;
    bool ok = true;
    for(int i = 0; i < n && ok; i++){
        int t, x, y; cin >> t >> x >> y;
        int manhattanDist = abs(x-currX) + abs(y-currY);
        int diffT = t-currT;
        if(manhattanDist > diffT) ok = false;
        else if( (manhattanDist-diffT)&1 ) ok = false;
        currX = x, currY = y, currT = t;
    }
    cout << (ok?"Yes\n":"No\n");
}