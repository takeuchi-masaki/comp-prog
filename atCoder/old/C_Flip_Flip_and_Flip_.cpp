#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;
    long long x, y;
    if(n==1) {
        x = 1;
    } else {
        x = n-2;
    }
    if(m==1){
        y = 1;
    } else {
        y = m-2;
    }
    cout << x*y << endl;
}