#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n){
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n%2 == 0) return false;
    for(long long i = 3; i*i <= n; i+=2){
        if(n%i == 0) return false;
    }
    return true;
}

int main(){
    freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    auto start = chrono::steady_clock::now();

    long long n = 1e9+7;
    // cin >> n;
    for(int i = 0; i < 100; i++){
        cout << n << " is ";
        if( !isPrime(n) ) cout << "not ";
        cout << "prime\n";
    }
    auto end = chrono::steady_clock::now();

    cout << "runtime: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms\n";
}