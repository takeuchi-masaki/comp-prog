#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    long long h, w;
    cin >> h >> w;
    if(h > 1 && w > 1){
        cout << (h*w + 1)/2;
    } else {
        cout << 1;
    }
}