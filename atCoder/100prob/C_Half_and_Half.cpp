#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int maxAB = max(x, y);
    int ans = 1e9;
    for(int ab = 0; ab <= maxAB; ab++){
        int remA = max(x - ab, 0);
        int remB = max(y - ab, 0);
        int currCost = ab * c * 2 + remA * a + remB * b;
        ans = min(ans, currCost);
    }
    cout << ans << '\n';
}