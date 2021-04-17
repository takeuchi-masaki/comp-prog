#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    map<int,int> m;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        m[temp]++;
    }
    int res = 0;
    for(auto [x,y]:m){
        if(x==y) continue;
        if(x<y) {
            res+=y-x;
        } else {
            res+=y;
        }
    }
    cout << res << '\n';
}