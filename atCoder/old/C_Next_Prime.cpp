#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin >> x;
    const int MAX = (int)10E9;
    if(x==2) {
        cout << 2 << endl;
    } else {
        for(long long d = x; d < MAX; d++){
        if((d&1)==0) continue;
        bool prime = true;
        for(long long i = 3; i*i<=d; i+=2){
            if(d%i==0) prime = false;
        }
        if(prime){
            cout << d << endl;
            break;
        }
    }
    }
}