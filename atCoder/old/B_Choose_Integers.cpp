#include <bits/stdc++.h>
using namespace std;

int main(){
    // check even odd of mod value and a
    int a, b, c;
    cin >> a >> b >> c;
    int target = c % b;
    // odd + odd multiple = odd or even
    // even + even multiple = even
    bool ok = false;
    for(int i = a; i < a*b; i+=a){
        if(i%b == target) {
            ok = true;
            break;
        }
    }
    cout << (ok?"YES":"NO") << endl;
}