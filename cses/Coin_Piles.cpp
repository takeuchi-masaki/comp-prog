#include <bits/stdc++.h>
using namespace std;

bool solve(){
    int a, b; cin >> a >> b;
    if(a == 0 || b == 0) return a == 0 && b == 0;
    if((a+b) % 3 != 0) return false;
    int high = max(a, b);
    int low = min(a, b);
    low -= high/2;
    if(high&1) low-=2;
    if(low < 0) return false;
    return low%3 == 0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << (solve() ? "YES\n" : "NO\n");
    }
}