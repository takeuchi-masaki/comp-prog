#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    unordered_map<string,int> add, subtr;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        add[temp]++;
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        string temp;
        cin >> temp;
        subtr[temp]++;
    }
    int res = 0;
    for(auto [x,y]:add){
        res= max(max(0,add[x]-subtr[x]), res);
    }
    cout << res << endl;
}