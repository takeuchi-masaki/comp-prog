#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int h, w; cin >> h >> w;
    if(h == 1 or w == 1){
        cout << h*w << endl;
        return 0;
    }
    cout << ((h+1)/2) * ((w+1)/2) << '\n';
}