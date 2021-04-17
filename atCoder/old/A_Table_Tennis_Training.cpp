#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, a, b, res;
    cin >> n >> a >> b;
    if((a&1)==(b&1)){
        res = (b-a)/2;
    }
    else{
        long long opt1, opt2;
        long long after = (b-a)/2;
        opt1 = n-b+1+after;
        opt2 = a-1+1+after;

        // opt1 = (n-b)+1+(n-a);
        // opt2 = ((a-1)+1+(b-1))/2;
        res = min(opt1,opt2);
    }
    cout << res << endl;
}