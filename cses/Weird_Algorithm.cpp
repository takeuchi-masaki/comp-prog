#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long n; cin >> n;
    cout << n << ' ';
    while(n!=1){
        if(n&1){
            n*=3;
            n++;
        } else {
            n>>=1;
        }
        cout << n << ' ';
    }
}