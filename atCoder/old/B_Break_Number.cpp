#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int num = 2;
    int k = 0;
    while(num < n){
        ++k;
        num = 1 << k;
    }
    if(num > n) --k;
    if(k == -1) cout << 1;
    else cout << (1<<k);
}