#include <bits/stdc++.h>
using namespace std;

vector<long long> fact(50);

int main(){
    int n,p;
    cin >> n >> p;
    int even = 0,odd = 0;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if(temp&1){
            odd++;
        } else {
            even++;
        }
    }
    // even + even = even
    // odd + odd = even
    // odd + even = odd
    long long res;
    if(odd==0){
        if(p){
            res=0;
        } else {
            res = 1LL<<n;
        }
    } else {
        res = 1LL<<(n-1);
    }
    cout << res << endl;
}