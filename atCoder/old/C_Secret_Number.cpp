#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    unordered_set<int> req, no;
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='o'){
            req.insert(i);
        } else if(s[i]=='x'){
            no.insert(i);
        }
    }
    int ans = 0;
    for(int i = 0; i <= 9999; i++){
        string s = to_string(i);
        bool valid = true;
        vector<bool> contain(10, false);
        if(s.size()<4) {
            contain[0] = true;
            if(no.count(0)) {
                valid = false;
            }
        }
        for(int j = 0; j < s.size(); j++){
            contain[s[j]-'0'] = true;
            if(no.count(s[j]-'0')){
                valid = false;
            }
        }
        for(int i:req){
            if(!contain[i]) valid = false;
        }
        if(valid) ans++;
    }
    cout << ans << endl;
}