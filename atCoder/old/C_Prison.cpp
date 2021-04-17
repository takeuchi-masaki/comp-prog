#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> l(m),r(m);
    for(int i = 0; i < m; i++){
        cin >> l[i] >> r[i];
    }
    int left = 0, right = n;
    for(int i = 0; i < m; i++){
        left = max(left,l[i]);
        right = min(right,r[i]);
    }
    cout << max(right-left+1,0) << endl;
}