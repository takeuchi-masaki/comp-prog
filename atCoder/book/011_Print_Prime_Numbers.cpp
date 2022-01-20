#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> primes = {2, 3};
    for(int i = 5; i <= n; i+=2){
        bool ok = true;
        for(int check = 3; check*check <= i && ok; check+=2){
            if(i % check == 0) ok = false;
        }
        if(ok) primes.push_back(i);
    }
    for(int i : primes) cout << i << ' ';
    cout << '\n';
}