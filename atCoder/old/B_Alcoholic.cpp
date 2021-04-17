#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    long long n, x;
    cin >> n >> x;
    // x ml
    x*=100;
    unsigned long long drink = 0;
    int count = 0;
    bool drank = false;
    while(n--){
        int v, p;
        cin >> v >> p;
        // volume ml
        // percent p volume p/100
        drink += v * p;
        ++count;
        if(drink > x) {
            drank = true;
            break;
        }
    }
    if(!drank) {
        count = -1;
    }
    cout << count;
}

