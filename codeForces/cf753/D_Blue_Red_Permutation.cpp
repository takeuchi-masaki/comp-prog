#include <bits/stdc++.h>
using namespace std;

bool solve(){
    int n; cin >> n;
    vector<int> red, blue, val(n);
    for(int&i:val)cin>>i;
    string s; cin >> s;
    for(int i = 0; i < n; i++){
        if(s[i] == 'B'){
            blue.push_back(val[i]);
        } else {
            red.push_back(val[i]);
        }
    }
    sort(red.begin(), red.end(), greater<int>());
    sort(blue.begin(), blue.end());
    for(int i = 0; i < blue.size(); i++){
        if(blue[i] <= i){
            return false;
        }
    }
    for(int i = 0; i < red.size(); i++){
        if(red[i] > n-i){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << (solve()?"YES\n":"NO\n");
    }
}