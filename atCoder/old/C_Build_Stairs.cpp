#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(auto& i:h) cin >> i;
    bool ok = true;
    for(int i = n-1; i > 0; i--){
        if(h[i]<h[i-1]){
            h[i-1]--;
            // cout << i << endl;
        }
        if(h[i]<h[i-1]){
            ok = false;
            // cout << i << endl;
            break;
        }
    }
    cout << (ok?"Yes":"No") << endl;
}