#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // long long MAX = 1e9;
    long long n = 0, num = 0;
    while(num <= 15){
        num = n*(n+1)/2;
        n++;
        cout << n << ' ' << num << endl;
    }
    // cout << n << endl;
    // int num = 44722;
    // cout << num * (num+1) / 2 << endl;
}

/*
    1 0
    2 1
    3 3
    4 6
    5 10
    6 15
    7 21
*/