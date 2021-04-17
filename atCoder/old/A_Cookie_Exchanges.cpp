#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b, c;
    cin >> a >> b >> c;
    int count = 0;
    while(true){
        if( (a&1) || (b&1) || (c&1) ) break;
        int tempA = a/2;
        int tempB = b/2;
        int tempC = c/2;
        a = tempB + tempC;
        b = tempA + tempC;
        c = tempA + tempB;
        ++count;
        if(a == b && b == c) {
            count = -1;
            break;
        }
    }
    cout << count << endl;
}