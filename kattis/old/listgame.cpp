#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int x;
    cin >> x;
    // find factors of x
    int count = 0;
    while((x&1)==0){
        x/=2;
        ++count;
    }
    for(int i = 3; i*i <= x; i+=2){
        if(x == 1) break;
        while(x%i==0){
            x/=i;
            ++count;
            if(x == 1) break;
        }
    }
    cout << count;
}

