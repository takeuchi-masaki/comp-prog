#include <bits/stdc++.h>
using namespace std;

// int f(int x){
//     if(x%100) return 0;
//     return f(x/100)+1;
// }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int d, n;
    cin >> d >> n;
    long long lower = 1;
    for(int i = 1; i <= d; i++){
        lower*=100;
    }
    long long res = lower*n;
    if(n>=100) res = lower*101;
    cout << res << endl;
    // for(int i = 1; ; i++){
    //     if(f(i)==d){
    //         if(--n==0){
    //             cout << i << endl;
    //             return 0;
    //         }
    //     }
    // }
}