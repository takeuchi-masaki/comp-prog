#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long n, k; cin >> n >> k;
    vector<long long> a(n), total(n), initial(n);
    for(long long&i:a)cin>>i;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[j] < a[i]){
                total[i]++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(a[j] < a[i]) initial[i]++;
        }
    }
    long long mult = k*(k-1)/2;
    mult %= MOD;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans = (ans + initial[i]*k) %MOD;
        long long add = mult*total[i];
        add %= MOD;
        ans = (ans + add)%MOD;
    }
    cout << ans << endl;
}