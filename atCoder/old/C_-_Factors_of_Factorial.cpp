#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
map<long long, long long> factors;

void factorize(long long num){
    while(num % 2 == 0){
        factors[2]++;
        num >>= 1;
    }
    for(long long i = 3; i * i <= num; i += 2){
        while(num % i == 0){
            num /= i;
            factors[i]++;
        }
    }
    if(num != 1ll) factors[num]++;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for(int i = 2; i <= n; i++){
        factorize(i);
    }
    long long ans = 1;
    for(auto [prime, cnt] : factors){
        ans *= cnt + 1;
        ans %= MOD;
    }
    cout << ans << '\n';
}