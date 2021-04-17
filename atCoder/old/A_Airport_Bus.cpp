#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> t(n);
    for(auto& i:t)cin>>i;
    sort(t.begin(),t.end());
    // int start = 0, res = 1;
    // for(int i = 0; i < n; i++){
    //     if( t[i] > t[start]+k || i >= start + c ){
    //         start = i;
    //         res++;
    //     }
    // }
    int res;
    for(int i = 0; i < n; i++){
        int f = i;
        while(i<n){
            
        }
    }
    cout << res << endl;
}