#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        unordered_set<int> initial(n);
        int init_max = 0;
        for(int i = 0; i < n; i++){
            int temp;
            cin>>temp;
            initial.insert(temp);
            init_max = max(init_max,temp);
        }
        // case: mex < max
        // case: mex > max
        //  eventually, mex = max+1
        //  (max + 1 + max + 1 ) /2 = max+1
        int init_mex = -1, res = n+k;
        for(int i = 0; i < n; i++){
            if(!initial.count(i)){
                init_mex = i;
                break;
            }    
        }
        if(init_mex!=-1 && k > 0){
            // cout << initial.size() << " init size" << endl;
            res = initial.size() + (initial.count((init_max+init_mex+1)/2)?0:1);
        }
        cout << res << endl;
    }
}