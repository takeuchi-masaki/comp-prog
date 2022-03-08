#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, x, y;
    cin >> n >> x >> y;
    for(int i = 0; i < n; i++){
        int nec; cin >> nec;
        nec *= y;
        nec = (nec + x - 1) / x;
        cout << nec << '\n';
    }
}