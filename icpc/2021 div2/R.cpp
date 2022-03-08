#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string a, b; cin >> a >> b;
    int ans = 1;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]) ans<<=1; // ans /= 2;
    }
    cout << ans << '\n';
}