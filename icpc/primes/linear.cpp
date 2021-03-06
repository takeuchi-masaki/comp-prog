#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n){
    if(n <= 1) return false;
    if(n <= 3) return true;
    for(long long i = 2; i < n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

int main(){
    freopen("out.txt","w",stdout);

    auto start = chrono::steady_clock::now();

    long long n = 1e9+7;
    cout << n << " is ";
    if( !isPrime(n) ) cout << "not ";
    cout << "prime\n";

    auto end = chrono::steady_clock::now();

    cout << "runtime: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms\n";
}