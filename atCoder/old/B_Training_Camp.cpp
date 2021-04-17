#include <bits/stdc++.h>
using namespace std;

const int MOD = 1E9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long res = 1;
    for(int i = 2; i <= n; i++){
        res = (res*i)%MOD;
    }
    cout << res <<endl;
}