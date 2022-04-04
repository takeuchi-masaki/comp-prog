#include <bits/stdc++.h>
using namespace std;

map<long long,int> factorize(long long num){
    map<long long,int> factors;
    for(long long i = 2; i * i <= num; i++){
        while(num % i == 0){
            num /= i;
            factors[i]++;
        }
    }
    if(num != 1ll) factors[num]++;
    return factors;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long A, B; cin >> A >> B;
    long long abGCD = __gcd(A, B);
    int count = 1 + factorize(abGCD).size();
    cout << count << '\n';
}