#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long n, k; cin >> n >> k;
    vector<long long> a(n), less(n,0);
    for(long long &i:a) cin >> i;
    long long ans = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(a[i] > a[j]) ans++;
        }
    }
    cout << ans << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i] > a[j]) less[i]++;
        }
    }
    long long mult = k*(k+1)/2 %MOD;


    for(long long num:less){

        ans = (ans + mult*num) %MOD;
    }

    cout << ans << endl;
}