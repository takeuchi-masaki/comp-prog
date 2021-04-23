#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    long long X;
    cin >> n >> X;
    // cout << n << ' ' << X << '\n';
    long long res = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        // cout << a[i] << ' ';
    }
    // cout << '\n';
    for(int i = 0; i < n; i++){
        if(X>>i &1){
            res+=a[i];
        }
    }
    cout << res << '\n';
    // cout << '\n';
}