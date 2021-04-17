#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    vector<int> vec(t);
    for(auto& i: vec){
        cin >> i;
    }
    sort(vec.begin(),vec.end(),greater<>());
    int len = 0;
    for(int i = 1; i < vec.size(); i++){
        len+=vec[i];
    }
    if(vec[0] < len) cout << "Yes";
    else cout << "No";
}

