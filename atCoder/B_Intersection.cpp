#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int maxA = 0, minB = 1e9;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        maxA = max(maxA, a);
    }
    for(int i = 0; i < n; i++){
        int b; cin >> b;
        minB = min(minB, b);
    }
    int res = minB - maxA + 1;
    if(res<0) res=0;
    cout << res << endl;
}