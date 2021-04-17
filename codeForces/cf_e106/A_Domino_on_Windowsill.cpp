#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k1, k2; // number of cells
        cin >> n >> k1 >> k2;
        int w, b; // white and black dominos
        cin >> w >> b;
        bool ok = true;
        int k = (k1+k2)/2;
        int opp = ((n-k1)+(n-k2))/2;
        if(w > k || b > opp) ok = false;
        // if((k1&1)!=(k2&1)){
        //     int k = (k1+k2)/2;
        //     if( (n&1)==0 ){
        //         if(w > k || b > n-k) ok = false;
        //     }
        //     else {

        //     }
        // } else {
        //     int k = (k1+k2)/2;
        //     int opp = ((n-k1)+(n-k2))/2;
        //     if(w > k || b > opp) ok = false;
        // }
        cout << (ok?"YES":"NO") << endl;
    }
}