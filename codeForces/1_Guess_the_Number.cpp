#include <bits/stdc++.h>
using namespace std;

int main(){
    int l = 1, r = 1e6 + 1;
    while(r - l > 1){
        int m = l + (r - l)/2;
        cout << m << endl;
        string resp;
        cin >> resp;
        if(resp == "<"){
            r = m;
        } else {
            l = m;
        }
    }
    cout << "! " << l << endl;
}