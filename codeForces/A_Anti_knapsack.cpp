#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t-->0){
        int n, k;
        cin >> n >> k;
        unordered_set<int> res;
        for(int i = n; i >= 1; i--){
            if(i==k) continue;
            if(res.count(k-i)) continue;
            res.insert(i);
        }
        cout << res.size() << '\n';
        for(int i:res){
            cout << i << ' ';
        }
        cout << endl;
    }
}