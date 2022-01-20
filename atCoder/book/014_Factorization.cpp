#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long n; cin >> n;
    long long nCopy = n;
    for(long long i = 2; n > 1 && i*i <= nCopy; i++){
        while(n % i == 0){
            cout << i << ' ';
            n /= i;
        }
    }
    if(n > 1) cout << n;
    cout << '\n';
}