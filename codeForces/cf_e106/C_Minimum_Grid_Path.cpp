#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> c(n);
        for(auto& i:c) cin >> i;
        // const long long INF = 1E18;
        long long cntMin1 = n, cntMin2 = n;
        long long min1 = c[0],
         min2 = c[1],
         min1cost = min1*cntMin2,
         min2cost = min2*cntMin2,
         res = min1cost+min2cost;
        
        for(int i = 2; i < n; i++){
            if(i%2==0){
                cntMin1--;
                if( c[i] < min1 ){
                    min1cost -= min1 * cntMin1;
                    min1cost += c[i] * cntMin1;
                    min1 = c[i];
                } else {
                    min1cost -= min1;
                    min1cost += c[i];
                }
            } else {
                cntMin2--;
                if( c[i] < min2 ){
                    min2cost -= min2 * cntMin2;
                    min2cost += c[i] * cntMin2;
                    min2 = c[i];
                } else {
                    min2cost -= min2;
                    min2cost += c[i];
                }
            }
            res = min(res, min1cost+min2cost);
        }
        cout << res << endl;
    }
}