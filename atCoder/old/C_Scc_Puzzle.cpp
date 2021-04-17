#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,m;
    cin >> n >> m;
    long long res = n;
    if(m-n*2<=0){
        res=m/2;
    } else {
        m-=(n*2);
        res+=m/4;
    }
    cout << res << endl;
}