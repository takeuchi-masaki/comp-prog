#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int x, y; cin >> x >> y;
    // x : point on B where A is zero
    // y : number of degrees in B that equal a change of a single degree in A
    if(y==1){
        if(x == 0) cout << "ALL GOOD\n";
        else cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << fixed << setprecision(9);
    cout << (double)-x/(y-1) << endl;
}