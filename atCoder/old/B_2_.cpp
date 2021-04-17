#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int w, h, n; cin >> w >> h >> n;
    int x0 = 0, x_end = w, y0 = 0, y_end = h;
    int res = 0;
    for(int i = 0; i < n; i++){
        int x, y, a; cin >> x >> y >> a;
        switch(a){
            case 1:
                x0 = max(x0, x);
                break;
            case 2:
                x_end = min(x_end, x);
                break;
            case 3:
                y0 = max(y0, y);
                break;
            case 4:
                y_end = min(y_end, y);
                break;
        }
    }
    if(x_end-x0 < 0 || y_end-y0 < 0) cout << 0 << '\n';
    else cout << (x_end-x0) * (y_end-y0) << '\n';
}