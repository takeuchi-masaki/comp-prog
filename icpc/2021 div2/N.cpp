#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // x: portions for recipe
    // y: portions necessary
    int n, x, y;
    cin >> n >> x >> y;
    for(int i = 0; i < n; i++){
        int nec; cin >> nec;
        nec *= y;
        nec /= x;
        cout << nec << '\n';
    }
}