#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long a = 1, b = n;
    for(long long i = 2; i*i<=n; i++){
        if(n%i==0){
            if(i>a){
                a = i;
                b = n/i;
            }
        }
    }
    long long res = a+b-2;
    cout << res << endl;
}