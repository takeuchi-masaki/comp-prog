#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    bool ok = false;
    for(int i = 1; i <= 10000; i++){
        int postTax8 = i*0.08;
        int postTax10 = i*0.1;
        if(postTax8==a && postTax10==b){
            ok = true;
            cout<< i << endl;
            break;
        }
    }
    if(!ok) cout << -1 << endl;
}