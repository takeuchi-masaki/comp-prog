#include <bits/stdc++.h>
using namespace std;

void ans(bool ok){
    cout << (ok ? "AC" : "TLE") << '\n';
}

void factorial(long long m, long long n){
    long long fact = 1;
    for(int i = 2; i <= n; i++){
        fact *= i;
        if(fact > m){
            ans(false);
            return;
        }
    }
    ans(true);
}

void exponential(long long m, long long n){
    long long exp = 2;
    for(int i = 1; i < n; i++){
        exp<<=1;
        if(exp > m){
            ans(false);
            return;
        }
    }
    ans(true);
}

void n4(long long m, long long n){
    long long cmp = n;
    for(int i = 1; i < 4; i++){
        cmp *= n;
        if(cmp > m){
            ans(false);
            return;
        }
    }
    ans(true);
}

void n3(long long m, long long n){
    long long cmp = n;
    for(int i = 1; i < 3; i++){
        cmp *= n;
        if(cmp > m){
            ans(false);
            return;
        }
    }
    ans(true);
}

void n2(long long m, long long n){
    if(n*n > m) ans(false);
    else ans(true);
}

void nlogn(long long m, long long n){
    if(n * log2(n) > m) ans(false);
    else ans(true);
}

void linear(long long m, long long n){
    if(n > m) ans(false);
    else ans(true);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long m, n, t;
    cin >> m >> n >> t;
    switch(t){
        case 1: factorial(m, n); break;
        case 2: exponential(m, n); break;
        case 3: n4(m, n); break;
        case 4: n3(m, n); break;
        case 5: n2(m, n); break;
        case 6: nlogn(m, n); break;
        case 7: linear(m, n); break;
    }
}