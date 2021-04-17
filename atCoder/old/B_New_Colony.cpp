#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> h(n);
        for(auto& i:h) cin >> i;
        int res = -1;
        bool off = false;
        for(int i = 0; i < k; i++){
            int currH = 100, currIndex = -1;
            for(int j = 0; j < n; j++){
                if(j==n-1){
                    if(h[j]>currH){
                        h[j-1]++;
                        currIndex = j; // implicit break
                    } else {
                        off = true;
                        break;
                    }
                }else if(h[j]<=currH){
                    currH=h[j];
                } else {
                    h[j-1]++;
                    currIndex = j;
                    break;
                }
            }
            if(off) {
                res = -1;
                break;
            }
            res = currIndex;
        }
        cout << res << endl;
    }
}