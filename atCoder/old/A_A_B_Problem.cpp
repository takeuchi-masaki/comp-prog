#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, a, b;
    cin >> n >> a >> b;
    long long res = 0;
    if(a>b){
        res = 0;
    } else if(n==1){
        if(a==b){
            res = 1;
        } else {
            res = 0;
        }
    } else {
        res = (a + (n-1)*b) - (b+(n-1)*a) + 1;
    }
    cout << res << endl;
}