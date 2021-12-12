#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long x, p, x2, p2;
    cin >> x >> p >> x2 >> p2;
    int mn = min(p, p2);
    p -= mn, p2 -= mn;
    if(p >= 7){
        cout << ">\n";
        return;
    }
    if(p2 >= 7){
        cout << "<\n";
        return;
    }
    for(int i = 0; i < p; i++) x *= 10;
    for(int i = 0; i < p2; i++) x2 *= 10;
    if(x < x2){
        cout << "<\n";
    } else if(x > x2){
        cout << ">\n";
    } else {
        cout << "=\n";
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}