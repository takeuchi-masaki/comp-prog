#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& i: a)cin >> i;
    long long res = 0;
    for(int i = 0; i < n; i++){
        res+=a[i]-1;
    }
    cout << res << endl;
}