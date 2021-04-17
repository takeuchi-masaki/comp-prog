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
        vector<int> layer(n);
        vector<bool> res(n, false);
        for(int i = 0; i < n; i++){
            cin >> layer[i];
        }
        int currDrench = layer[n-1];
        for(int i = n-1; i>=0; i--){
            currDrench = max(--currDrench, layer[i]);
            // cout << layer[i] << " " << currDrench << endl;
            if(currDrench>0){
                res[i] = 1;
            }
        }
        for(bool b:res){
            cout << (b?1:0) << " ";
        }
        cout << endl;
    }
}