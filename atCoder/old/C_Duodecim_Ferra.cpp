#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int l; cin >> l;
    // res = length choose 11
    // n! / (11!*(n-11)!)
    long long ans = 1;
    for(int i = 1; i <= 11; i++){
        ans *= l-i;
        ans /= i;
    }
    cout << ans << '\n';
}